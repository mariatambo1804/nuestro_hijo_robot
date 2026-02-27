import numpy as np
import math


class PurePursuit:
    """Class to follow a path using a simple pure pursuit controller."""

    def __init__(self, dt: float, lookahead_distance: float = 1.0):
        """Pure pursuit class initializer.

        Args:
            dt: Sampling period [s].
            lookahead_distance: Distance to the next target point [m].

        """
        self._dt: float = dt
        self._lookahead_distance: float = lookahead_distance
        self._path: list[tuple[float, float]] = []
        self.new_path: bool = False

    def compute_commands(self, x: float, y: float, theta: float) -> tuple[float, float]:
        """Pure pursuit controller implementation.

        Args:
            x: Estimated robot x coordinate [m].
            y: Estimated robot y coordinate [m].
            theta: Estimated robot heading [rad].

        Returns:
            v: Linear velocity [m/s].
            w: Angular velocity [rad/s].

        """
        # TODO: 4.4. Complete the function body with your code (i.e., compute v and w).
        try:
            if not self._path:
                return 0.0, 0.0

            # find closest point and the lookahead target on the path
            _, idx_closest = self._find_closest_point(x, y)
            x_t, y_t = self._find_target_point((x, y), idx_closest)

            # 3) Heading error (alpha): angle to the target relative to robot heading
            beta = math.atan2(y_t - y, x_t - x)  # direction robot -> target
            alpha = beta - theta
            alpha = math.atan2(math.sin(alpha), math.cos(alpha))

            # --- SIMPLE SAFETY: if target is behind, rotate in place first ---
            if abs(alpha) > math.radians(25):
                v = 0.0
                w = 1.2 if alpha > 0.0 else -1.2  # turn in place (tune 0.8 if needed)
                return v, w

            # Constant bounds
            v_max, v_min = 1, 0.28
            Ld_max = self._lookahead_distance
            Ld_min = 0.3  # in case we are really close to an edge

            # 4) Error scaling in [0, 1] using |alpha|
            #    0 means "well aligned"; 1 means "very misaligned" (>= 90 degrees).
            err = min(abs(alpha) / (math.pi / 2), 1.0)

            # 5) Speed scheduling:
            #    Large error -> smaller v, Small error -> larger v
            v = v_max - (v_max - v_min) * err

            # 6) Lookahead scheduling:
            #    Large error -> smaller lookahead to turn tighter
            #    Small error -> larger lookahead for smoother tracking
            Ld = Ld_max - (Ld_max - Ld_min) * err

            # 7) Pure Pursuit angular command:
            #    k = v / Ld combines speed and lookahead into a curvature gain.
            k = v / (Ld + 1e-9)
            w = 2.0 * k * math.sin(alpha)

            return v, w
        except Exception as e:
            print(f"[PurePursuit] {type(e).__name__}: {e}")
            return 0.0, 0.0

    @property
    def path(self) -> list[tuple[float, float]]:
        """Path getter."""
        return self._path

    @path.setter
    def path(self, value: list[tuple[float, float]]) -> None:
        """Path setter."""
        self._path = value

    def _find_closest_point(self, x: float, y: float) -> tuple[tuple[float, float], int]:
        """Find the closest path point to the current robot pose.

        Args:
            x: Estimated robot x coordinate [m].
            y: Estimated robot y coordinate [m].

        Returns:
            tuple[float, float]: (x, y) coordinates of the closest path point [m].
            int: Index of the path point found.

        """
        # TODO: 4.2. Complete the function body (i.e., find closest_xy and closest_idx).
        if not self._path:
            return (0.0, 0.0), 0

        closest_xy = (0.0, 0.0)
        closest_idx = 0
        min_dist = float("inf")

        for i, point in enumerate(self._path):
            dist = math.sqrt((point[0] - x) ** 2 + (point[1] - y) ** 2)
            if dist < min_dist:
                min_dist = dist
                closest_xy = point
                closest_idx = i
        return closest_xy, closest_idx

    def _find_target_point(
        self, origin_xy: tuple[float, float], origin_idx: int
    ) -> tuple[float, float]:
        """Find the destination path point based on the lookahead distance.

        Args:
            origin_xy: Current location of the robot (x, y) [m].
            origin_idx: Index of the current path point.

        Returns:
            tuple[float, float]: (x, y) coordinates of the target point [m].

        """
        # TODO: 4.3. Complete the function body with your code (i.e., determine target_xy).
        target_xy = self.path[origin_idx]
        x, y = origin_xy
        for idx in range(origin_idx, len(self._path)):
            x_new, y_new = self._path[idx]
            dist_new = ((x - x_new) ** 2 + (y - y_new) ** 2) ** 0.5
            if dist_new >= self._lookahead_distance:
                return self._path[idx]
        target_xy = self._path[-1]
        return target_xy
