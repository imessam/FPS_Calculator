import datetime

from abc import ABC

class FPS(ABC):

    def __init__(self) -> None:

        self.start_time : datetime.datetime = None
        self.current_time : datetime.datetime = None
        self.elapsed_time : datetime.timedelta = None

        self.frame_count : int = 0

        self.fps : float = 0.0
        self.avg_fps : float = 0.0
        self.frame_time : float = 0.0
    
    def start(self) -> None:

        self.start_time = datetime.datetime.now()

        return 
    
    def update(self) -> None:

        self.current_time = datetime.datetime.now()
        self.elapsed_time = self.current_time - self.start_time

        self.frame_time += self.elapsed_time.total_seconds()

        self.frame_count += 1

        return 
    
    def get_fps(self) -> float:

        if self.frame_time > 0.0:
            self.fps = self.frame_count / self.frame_time

        return round(self.fps, 2)
    
    def get_avg_fps(self) -> float:

        if self.frame_count >= 30:

            self.avg_fps = self.frame_count / self.frame_time
            self.frame_time = 0.0
            self.frame_count = 0

        return round(self.avg_fps, 2)

    def reset(self) -> None:

        self.start_time = None
        self.current_time = None
        self.elapsed_time = None

        self.frame_count = 0

        self.fps = 0.0
        self.avg_fps = 0.0
        self.frame_time = 0.0

        return 