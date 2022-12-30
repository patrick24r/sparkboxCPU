#pragma once
#include "SparkboxError.hxx"
#include "VideoDataModel.hxx"

#include "CoreController.hxx"
#include "AudioController.hxx"
#include "VideoController.hxx"
#include "GamepadController.hxx"

namespace Sparkbox {

// Singleton class template
template<typename T>
class Singleton  {
public:
    static T& getInstance(void) {
        static T instance;
        return instance;
    }

    // Stop any copying of the singleton
    Singleton(Singleton const& copy) = delete;
    Singleton& operator=(Singleton const& copy) = delete;

protected:
    Singleton() {}
    ~Singleton() {}

};

class Sparkbox : public Singleton<Sparkbox> {
    friend class Singleton<Sparkbox>;
public:
    CoreController& core;
    AudioController& audio;
    VideoController& video;
    GamepadController& gamepad;
protected:
    Sparkbox() {
        core = CoreController::getInstance();
        audio = AudioController::getInstance();
        video = VideoController::getInstance();
        gamepad = GamepadController::getInstance();
    }
};


}