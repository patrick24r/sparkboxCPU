#include "AudioController.hxx"

namespace Sparkbox {

sparkboxError_t AudioController::linkDriver(const AudioDriver_TypeDef* pAudioDriver) {
    if (pAudioDriver == nullptr) {
        return sparkboxError_t::AUDIO_DRIVER_INVALID;
    }

    this->driver = pAudioDriver;
    return sparkboxError_t::OK;
}

}