#pragma once

namespace Sparkbox {
    typedef enum Error {
        OK = 0,

        CORE_DRIVER_INVALID = 100,

        AUDIO_DRIVER_INVALID = 200,

        VIDEO_DRIVER_INVALID = 300,

        GAMEPAD_DRIVER_INVALID = 400,

    } sparkboxError_t;
}
