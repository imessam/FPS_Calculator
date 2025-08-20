import sys
import cv2

from modules.fps import FPS

def main():

    fps = FPS()

    current_fps = 0.0
    avg_fps = 0.0

    cap = cv2.VideoCapture("../examples/test.mp4")

    if not cap.isOpened():
        print("Error opening video stream or file")
        return -1
    


    while (True):
        fps.start()

        ret, frame = cap.read()

        if not ret or frame is None:
            break

        cv2.imshow("Frame", frame)
        cv2.waitKey(int((1.0/30.0)*1000))

        fps.update()

        current_fps = fps.get_fps()
        avg_fps = fps.get_avg_fps()

        print(f"Current FPS: {current_fps} | Avg FPS: {avg_fps}")
        
    
    return 0

if __name__ == "__main__":
    sys.exit(main())