from modules.fps import FPS

import pytest

@pytest.fixture
def fps() -> FPS:
   return FPS()

def test_start_stop(fps: FPS):

   assert fps.start()
