#pragma once

#include <chrono>
#include <ctime>  

class FPS {

    public:

        FPS();
        ~FPS();

        void start();

        void update();

        float getFps();
        float getAvgFps();

        void reset();

    private:

        std::chrono::time_point<std::chrono::system_clock> start_time;
        std::chrono::time_point<std::chrono::system_clock> current_time;
        std::chrono::time_point<std::chrono::system_clock> end_time;

        std::chrono::duration<float> elapsed_time;

        float fps;
        float avg_fps;
        float frame_time;
        int frame_count;

};