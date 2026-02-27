from enum import Enum


class State(Enum):
    FOLLOW = 0
    TURN_LEFT = 1


class WallFollower:
    def __init__(self, dt: float):
        self._dt = dt
        self.state = State.FOLLOW
        self.prev_error = 0.0
        self.turn_steps = 0  # NEW

    def compute_commands(self, z_us, z_v, z_w):

        front = min(z_us[3], z_us[4])
        right = min(z_us[6], z_us[7])
        left = min(z_us[0], z_us[1])

        # CHANGE: use 2.0 instead of 1.0
        if front == float("inf"):
            front = 1.0
        if right == float("inf"):
            right = 1.0
        if left == float("inf"):
            left = 1.0

        front_th = 0.30
        front_ok = 0.45

        if self.state == State.FOLLOW:
            self.turn_steps = 0  # NEW
            if front < front_th:
                self.state = State.TURN_LEFT

        elif self.state == State.TURN_LEFT:
            self.turn_steps += 1  # NEW
            if front > front_ok or self.turn_steps > int(1.2 / self._dt):  # NEW
                self.state = State.FOLLOW

        if self.state == State.TURN_LEFT:
            self.prev_error = 0.0
            return 0.0, 1.2

        # --- Prefer straight at intersections (keep going vertical) ---
        # thresholds (ajústalos un poco si hace falta)
        front_free = front > 0.60
        side_open = (left > 0.80) or (right > 0.80)

        if front_free and side_open:
            # go straight for this step (avoid drifting into side corridor)
            self.prev_error = 0.0
            return 0.45, 0.0

        v = 0.5
        ku = 6
        kp = 0.5 * ku
        kd = 2

        error = right - left
        d_error = (error - self.prev_error) / self._dt
        self.prev_error = error

        w = -kp * error - kd * d_error

        w = max(min(w, 1.2), -1.2)

        return v, w
