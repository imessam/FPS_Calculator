#include "fps.h"

FPS::FPS() {

    this->frame_count = 0;

    this->fps = 0.0f;
    this->avg_fps = 0.0f;
    this->frame_time = 0.0f;
}

FPS::~FPS() {}

void FPS::start() {

    this->start_time = std::chrono::system_clock::now();

    return;
}

void FPS::update() {

    this->current_time = std::chrono::system_clock::now();
    this->elapsed_time = this->current_time - this->start_time;

    this->frame_time += this->elapsed_time.count();

    this->frame_count++;

    return;
}

float FPS::getFps() {

    if(this->frame_time > 0.0f){
        this->fps = this->frame_count / this->frame_time;
    }

    return this->fps;
}

float FPS::getAvgFps() {

    if(this->frame_count >= 30){
        this->avg_fps = this->frame_count / this->frame_time;
        this->frame_time = 0.0f;
        this->frame_count = 0;
    }

    return this->avg_fps;
}

void FPS::reset() {

    this->frame_count = 0;

    this->fps = 0.0f;
    this->avg_fps = 0.0f;
    this->frame_time = 0.0f;

    return ;
}