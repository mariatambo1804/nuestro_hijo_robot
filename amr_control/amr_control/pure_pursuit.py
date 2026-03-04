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
        self._prev_w: float = 0.0

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

            # Heading error (alpha)
            beta = math.atan2(y_t - y, x_t - x)
            alpha = beta - theta
            alpha = math.atan2(math.sin(alpha), math.cos(alpha))

            # Rotate-in-place only once after a new path arrives
            if self.new_path and abs(alpha) > math.radians(25):
                v = 0.0
                w = 1.2 if alpha > 0.0 else -1.2
                return v, w
            elif abs(alpha) < math.radians(25):
                self.new_path = False

            # Bounds
            v_max, v_min = 0.8, 0.22
            Ld_max = self._lookahead_distance
            Ld_min = min(Ld_max, max(0.15, 0.35 * Ld_max))

            # Error scaling [0, 1]
            err = min(abs(alpha) / (math.pi / 2), 1.0)

            # Speed scheduling
            v = v_max - (v_max - v_min) * err

            # Lookahead scheduling
            Ld = Ld_max - (Ld_max - Ld_min) * err

            # Pure Pursuit angular command (sin smoothing)
            k = v / (Ld + 1e-9)
            w_raw = 2 * k * math.sin(alpha)

            # Saturation only
            w_max = 1.2
            w = max(-w_max, min(w_max, w_raw))

            # keep prev for potential future use
            self._prev_w = w

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
        self.new_path = True
        self._prev_w = 0.0
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
        for idx in range(origin_idx + 1, len(self._path)):
            x_new, y_new = self._path[idx]
            dist_new = ((x - x_new) ** 2 + (y - y_new) ** 2) ** 0.5
            if dist_new >= self._lookahead_distance:
                return self._path[idx]
        target_xy = self._path[-1]
        return target_xy
