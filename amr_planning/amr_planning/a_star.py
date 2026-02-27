import datetime
import math
import numpy as np
import os
import pytz

from amr_planning.map import Map
from matplotlib import pyplot as plt


class AStar:
    """Class to plan the optimal path to a given location using the A* algorithm."""

    def __init__(
        self,
        map_path: str,
        sensor_range: float,
        action_costs: tuple[float, float, float, float] = (1.0, 1.0, 1.0, 4.0),
    ):
        """A* class initializer.

        Args:
            map_path: Path to the map of the environment.
            sensor_range: Sensor measurement range [m].
            action_costs: Cost of of moving one cell left, right, up, and down.

        """
        self._actions: np.ndarray = np.array(
            [
                (-1, 0),  # Move one cell left
                (0, 1),  # Move one cell up
                (1, 0),  # Move one cell right
                (0, -1),  # Move one cell down
            ]
        )
        self._action_costs: tuple[float, float, float, float] = action_costs
        self._map: Map = Map(map_path, sensor_range, compiled_intersect=False, use_regions=False)

        self._figure, self._axes = plt.subplots(1, 1, figsize=(7, 7))
        self._timestamp = datetime.datetime.now(pytz.timezone("Europe/Madrid")).strftime(
            "%Y-%m-%d_%H-%M-%S"
        )

    def a_star(
        self,
        start: tuple[float, float],
        goal: tuple[float, float],
        use_heuristic: bool = True,
    ) -> tuple[list[tuple[float, float]], int]:
        """Computes the optimal path to a given goal location using the A* algorithm.

        Args:
            start: Initial location in (x, y) format.
            goal: Destination in (x, y) format.

        Returns:
            Path to the destination. The first value corresponds to the initial location.
            Number of A* iterations required to find the path.

        """
        # TODO: 3.2. Complete the function body (i.e., replace the code below).
        path: list[tuple[float, float]] = []
        steps: int = 0

        heuristic_total = self._compute_heuristic(goal) if use_heuristic else np.zeros_like(self._map.grid_map)

        rc_start = self._xy_to_rc(start)
        rc_goal  = self._xy_to_rc(goal)

        g_start = 0.0
        f_start = g_start + heuristic_total[rc_start]

        # CLAVE: open_list debe guardar nodos en (r,c), no en (x,y)
        open_list = {rc_start: (f_start, g_start)}
        closed_list = set()
        ancestors = {}

        while open_list:
            steps += 1
            current_rc = min(open_list, key=lambda k: open_list[k][0])
            f_current, g_current = open_list[current_rc]
            del open_list[current_rc]

            closed_list.add(current_rc)

            if current_rc == rc_goal:
                # Reconstruir en rc y convertir a xy
                path_rc = self._reconstruct_path(rc_start, rc_goal, ancestors)
                path = [self._rc_to_xy(rc) for rc in path_rc]
                return path, steps
            
            for i, action in enumerate(self._actions):
                dr = int(action[0])
                dc = int(action[1])

                neig_r = current_rc[0] + dr
                neig_c = current_rc[1] + dc
                neig_rc = (neig_r, neig_c)

                # límites
                if not (0 <= neig_r < self._map.grid_map.shape[0] and 0 <= neig_c < self._map.grid_map.shape[1]):
                    continue

                # obstáculo
                if self._map.grid_map[neig_rc] == 1:
                    continue

                if neig_rc in closed_list:
                    continue

                g_new = g_current + self._action_costs[i]
                f_new = g_new + heuristic_total[neig_rc]

                # actualizar si mejora
                if (neig_rc not in open_list) or (g_new < open_list[neig_rc][1]):
                    open_list[neig_rc] = (f_new, g_new)
                    ancestors[neig_rc] = current_rc

        return path, steps
    @staticmethod
    def smooth_path(
        path, data_weight: float = 0.1, smooth_weight: float = 0.8, tolerance: float = 1e-6
    ) -> list[tuple[float, float]]:
        """Computes a smooth trajectory from a Manhattan-like path.

        Args:
            path: Non-smoothed path to the goal (start location first).
            data_weight: The larger, the more similar the output will be to the original path.
            smooth_weight: The larger, the smoother the output path will be.
            tolerance: The algorithm will stop when after an iteration the smoothed path changes
                       less than this value.

        Returns: Smoothed path (initial location first) in (x, y) format.

        """
        # TODO: 3.4. Complete the function body (i.e., load smoothed_path).
        if len(path) < 2:
            return [(float(x), float(y)) for x, y in path]
        original = [(float(x), float(y)) for x, y in path]
        n_insert = 3 # number of points we are going to insert
        smoothedpath = [] # The smoothed path 
        for i in range(len(original) - 1): #Because the last point must be the goal
            x0, y0 = original[i]
            x1, y1 = original[i + 1]
            if i == 0: #if i am at the first point
                smoothedpath.append((x0, y0)) # The first point must be the start
            # we interpolate to include points into the original path
            for k in range(1, n_insert + 2):
                t = k / (n_insert + 1) # The percentage of the distance u move
                x = x0 + t * (x1 - x0)
                y = y0 + t * (y1 - y0)
                smoothedpath.append((x, y))
        original = smoothedpath.copy()
        smoothed = smoothedpath.copy()

        change = tolerance
        while change >= tolerance:
            change = 0.0
            for i in range(1, len(smoothed) - 1):
                x, y = smoothed[i]
                x_orig, y_orig = original[i]
                x_prev, y_prev = smoothed[i - 1]
                x_next, y_next = smoothed[i + 1]
                new_x = x + data_weight * (x_orig - x) + smooth_weight * (x_prev + x_next - 2 * x)
                new_y = y + data_weight * (y_orig - y) + smooth_weight * (y_prev + y_next - 2 * y)
                change += abs(new_x - x) + abs(new_y - y)
                smoothed[i] = (new_x, new_y)
        return smoothed

    @staticmethod
    def plot(axes, path: list[tuple[float, float]], smoothed_path: list[tuple[float, float]] = ()):
        """Draws a path.

        Args:
            axes: Figure axes.
            path: Path (start location first).
            smoothed_path: Smoothed path (start location first).

        Returns:
            axes: Modified axes.

        """
        x_val = [x[0] for x in path]
        y_val = [x[1] for x in path]

        axes.plot(x_val, y_val)  # Plot the path
        axes.plot(
            x_val[1:-1], y_val[1:-1], "bo", markersize=4
        )  # Draw blue circles in every intermediate cell

        if smoothed_path:
            x_val = [x[0] for x in smoothed_path]
            y_val = [x[1] for x in smoothed_path]

            axes.plot(x_val, y_val, "y")  # Plot the path
            axes.plot(
                x_val[1:-1], y_val[1:-1], "yo", markersize=4
            )  # Draw yellow circles in every intermediate cell

        axes.plot(x_val[0], y_val[0], "rs", markersize=7)  # Draw a red square at the start location
        axes.plot(
            x_val[-1], y_val[-1], "g*", markersize=12
        )  # Draw a green star at the goal location

        return axes

    def show(
        self,
        path,
        smoothed_path=(),
        title: str = "Path",
        display: bool = False,
        block: bool = False,
        save_figure: bool = False,
        save_dir: str = "images",
    ):
        """Displays a given path on the map.

        Args:
            path: Path (start location first).
            smoothed_path: Smoothed path (start location first).
            title: Plot title.
            display: True to open a window to visualize the particle filter evolution in real-time.
                Time consuming. Does not work inside a container unless the screen is forwarded.
            block: True to stop program execution until the figure window is closed.
            save_figure: True to save figure to a .png file.
            save_dir: Image save directory.

        """
        figure = self._figure
        axes = self._axes
        axes.clear()

        axes = self._map.plot(axes)
        axes = self.plot(axes, path, smoothed_path)

        axes.set_title(title)
        figure.tight_layout()  # Reduce white margins

        if display:
            plt.show(block=block)
            plt.pause(0.001)  # Wait for 1 ms or the figure won't be displayed

        if save_figure:
            save_path = os.path.join(os.path.dirname(__file__), "..", save_dir)

            if not os.path.isdir(save_path):
                os.makedirs(save_path)

            file_name = f"{self._timestamp} {title.lower()}.png"
            file_path = os.path.join(save_path, file_name)
            figure.savefig(file_path)

    def _compute_heuristic(self, goal: tuple[float, float]) -> np.ndarray:
        """Creates an admissible heuristic.

        Args:
            goal: Destination location in (x,y) coordinates.

        Returns:
            Admissible heuristic.

        """
        heuristic = np.zeros_like(self._map.grid_map)
        # TODO: 3.1. Complete the missing function body with your code.

        # Get the row and columns of the map
        rows_map,cols_map = np.shape(self._map.grid_map)

        # Change our goal destination into a row, col
        row_goal, col_goal = self._xy_to_rc(goal) 

        # Compute the Manhattan distance and add it to the heuristic matrix
        # That contains all of the distances from every cell to the goal
        for row in range(rows_map):
            for col in range(cols_map):
                heuristic[row,col] = abs(row - row_goal) + abs(col - col_goal)
        return heuristic

    def _reconstruct_path(
        self,
        start: tuple[float, float],
        goal: tuple[float, float],
        ancestors: dict[tuple[int, int], tuple[int, int]],
    ) -> list[tuple[float, float]]:
        """Computes the path from the start to the goal given the ancestors of a search algorithm.

        Args:
            start: Initial location in (x, y) format.
            goal: Goal location in (x, y) format.
            ancestors: Matrix that contains for every cell, None or the (x, y) ancestor from which
                       it was opened.

        Returns: Path to the goal (start location first) in (x, y) format.

        """

        # TODO 3.3
        # Operates on grid coordinates (row, col) since `ancestors` stores RC keys.
        path: list[tuple[int, int]] = []


        # Expect start and goal to be RC tuples when called from `a_star`.
        start_rc = start
        goal_rc = goal

        # Start from the goal and walk back to the start using ancestors
        idx_t = goal_rc
        path.append(idx_t)

        # If goal was never reached, return empty path
        if goal_rc != start_rc and goal_rc not in ancestors:
            return []

        while idx_t != start_rc:
            idx_t = ancestors[idx_t]
            path.append(idx_t)

        path.reverse()
        return path

    def _xy_to_rc(self, xy: tuple[float, float]) -> tuple[int, int]:
        """Converts (x, y) coordinates of a metric map to (row, col) coordinates of a grid map.

        Args:
            xy: (x, y) [m].

        Returns:
            rc: (row, col) starting from (0, 0) at the top left corner.

        """
        map_rows, map_cols = np.shape(self._map.grid_map)

        x = round(xy[0])
        y = round(xy[1])

        row = int(map_rows - (y + math.ceil(map_rows / 2.0)))
        col = int(x + math.floor(map_cols / 2.0))

        return row, col

    def _rc_to_xy(self, rc: tuple[int, int]) -> tuple[float, float]:
        """Converts (row, col) coordinates of a grid map to (x, y) coordinates of a metric map.

        Args:
            rc: (row, col) starting from (0, 0) at the top left corner.

        Returns:
            xy: (x, y) [m].

        """
        map_rows, map_cols = np.shape(self._map.grid_map)
        row, col = rc

        x = col - math.floor(map_cols / 2.0)
        y = map_rows - (row + math.ceil(map_rows / 2.0))

        return x, y
