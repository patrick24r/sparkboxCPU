#pragma once
#include "Sparkbox.hxx"

namespace Sparkbox {

class VideoController : public Singleton<VideoController> {
    friend class Singleton<VideoController>;
};

}