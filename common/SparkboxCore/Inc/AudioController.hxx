#pragma once
#include "Sparkbox.hxx"

namespace Sparkbox {

typedef struct AudioDriver {
    sparkboxError_t(*initialize)(void);
    void (*deinitialize)(void);
} AudioDriver_TypeDef;

class AudioController {
public:
    sparkboxError_t linkDriver(const AudioDriver_TypeDef* pAudioDriver) {
        if (pAudioDriver == nullptr) {
            return sparkboxError_t::AUDIO_DRIVER_INVALID;
        }

        this->driver = pAudioDriver;
        return sparkboxError_t::OK;
    }

private:
    const AudioDriver_TypeDef* driver = nullptr;
};

}