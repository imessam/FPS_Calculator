#include "fps.h"

#include <iostream>

#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>

int main(int argc, char** argv) {

    FPS fps;

    float currentFps, avgFps;

    cv::VideoCapture cap{"../examples/test.mp4"};
    if (!cap.isOpened()) {
        std::cerr << "Error opening video stream or file" << std::endl;
        return -1;
    }

    cv::Mat frame;

    while (true) {
        fps.start();

        cap >> frame;

        if (frame.empty()) {
            break;
        }

        cv::imshow("Frame", frame);

        cv::waitKey((1.0f/30.0f) * 1000);

        fps.update();

        currentFps = fps.getFps();
        avgFps = fps.getAvgFps();

        std::cout << "Current FPS: " << currentFps << " Avg FPS: " << avgFps << std::endl;
    }
    
    return 0;
} 