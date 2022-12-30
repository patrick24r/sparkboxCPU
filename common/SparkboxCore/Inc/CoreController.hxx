#pragma once
#include "Sparkbox.hxx"

namespace Sparkbox {

typedef struct CoreDriver {
    sparkboxError_t(*initialize)(void);
    void (*deinitialize)(void);
} CoreDriver_TypeDef;


class CoreController : public Singleton<CoreController> {
    friend class Singleton<CoreController>;
public:
    sparkboxError_t linkDriver(const CoreDriver_TypeDef* pCoreDriver);
private:
    const CoreDriver_TypeDef* driver;
}; // class CoreController

} // namespace Sparkbox

