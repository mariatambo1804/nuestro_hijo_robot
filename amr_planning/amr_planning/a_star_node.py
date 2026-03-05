import rclpy
from rclpy.lifecycle import LifecycleNode, LifecycleState, TransitionCallbackReturn

from amr_msgs.msg import PoseStamped as AmrPoseStamped
from geometry_msgs.msg import PoseStamped
from nav_msgs.msg import Path

import os
import traceback

from amr_planning.a_star import AStar


class AStarNode(LifecycleNode):
    def __init__(self):
        """A* node initializer."""
        super().__init__("a_star")

        # Parameters
        self.declare_parameter("goal", (0.0, 0.0))
        self.declare_parameter("world", "project")

    def on_configure(self, state: LifecycleState) -> TransitionCallbackReturn:
        """Handles a configuring transition.

        Args:
            state: Current lifecycle state.

        """
        self.get_logger().info(f"Transitioning from '{state.label}' to 'inactive' state.")

        try:
            # Parameters
            self._goal = tuple(
                self.get_parameter("goal").get_parameter_value().double_array_value.tolist()
            )
            world = self.get_parameter("world").get_parameter_value().string_value

            # Subscribers
            self._subscriber_pose = self.create_subscription(
                AmrPoseStamped, "pose", self._path_callback, 10
            )

            # Publishers
            # TODO: 3.5. Create the /path publisher (Path message).

            self._publisher_path = self.create_publisher(
                msg_type=Path, topic="/path", qos_profile=10
            )

            # Constants
            SENSOR_RANGE = 1.0  # Ultrasonic sensor range [m]

            # Attribute and object initializations
            map_path = os.path.realpath(
                os.path.join(os.path.dirname(__file__), "..", "maps", world + ".json")
            )
            self._localized = False
            self._planning = AStar(map_path, SENSOR_RANGE)

        except Exception:
            self.get_logger().error(f"{traceback.format_exc()}")
            return TransitionCallbackReturn.ERROR

        return super().on_configure(state)

    def on_activate(self, state: LifecycleState) -> TransitionCallbackReturn:
        """Handles an activating transition.

        Args:
            state: Current lifecycle state.

        """
        self.get_logger().info(f"Transitioning from '{state.label}' to 'active' state.")

        return super().on_activate(state)

    def _path_callback(self, pose_msg: AmrPoseStamped):
        """Subscriber callback. Executes A* and publishes the smoothed path to the goal.

        Args:
            pose_msg: Message containing the robot pose estimate.

        """
        if pose_msg.localized and not self._localized:
            # Execute A* with heuristic (A*) and without heuristic (naive)
            start = (pose_msg.pose.position.x, pose_msg.pose.position.y)

            path_astar, steps_astar = self._planning.a_star(start, self._goal, use_heuristic=True)
            smoothed_astar = AStar.smooth_path(path_astar, data_weight=0.5, smooth_weight=0.1)

            path_naive, steps_naive = self._planning.a_star(start, self._goal, use_heuristic=False)
            smoothed_naive = AStar.smooth_path(path_naive, data_weight=0.1, smooth_weight=0.2)

            self.get_logger().info(f"A*: steps={steps_astar}; Naive: steps={steps_naive}")

            # Save both figures with different titles so you can compare images
            self._planning.show(path_astar, smoothed_astar, title="A*_path", save_figure=True)
            self._planning.show(path_naive, smoothed_naive, title="Naive_path", save_figure=True)

            # Publish the smoothed A* path by default
            self._publish_path(smoothed_astar)

        self._localized = pose_msg.localized

    def _publish_path(self, path: list[tuple[float, float]]) -> None:
        """Publishes the robot's path to the goal in a nav_msgs.msg.Path message.

        Args:
            path: Smoothed path (initial location first) in (x, y) format.

        """
        # TODO: 3.6. Complete the function body with your code (i.e., replace the pass statement).
        msg = Path()  # Type of message
        msg.header.stamp = self.get_clock().now().to_msg()

        # We have to include every point in the path
        for x, y in path:
            pose = PoseStamped()
            pose.header.stamp = msg.header.stamp
            pose.pose.position.x = float(x)
            pose.pose.position.y = float(y)
            pose.pose.position.z = 0.0
            # Neutral orientation
            pose.pose.orientation.x = 0.0
            pose.pose.orientation.y = 0.0
            pose.pose.orientation.z = 0.0
            pose.pose.orientation.w = 1.0
            msg.poses.append(pose)

        # Publish message
        self._publisher_path.publish(msg)


def main(args=None):
    rclpy.init(args=args)

    a_star_node = AStarNode()

    try:
        rclpy.spin(a_star_node)
    except KeyboardInterrupt:
        pass

    a_star_node.destroy_node()
    rclpy.try_shutdown()


if __name__ == "__main__":
    main()
