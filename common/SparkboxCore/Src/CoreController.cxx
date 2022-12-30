#include "CoreController.hxx"

namespace Sparkbox {

sparkboxError_t CoreController::linkDriver(const CoreDriver_TypeDef* pCoreDriver) {
    if (pCoreDriver == nullptr) {
        return sparkboxError_t::CORE_DRIVER_INVALID;
    }

    this->driver = pCoreDriver;
    return sparkboxError_t::OK;
}

}