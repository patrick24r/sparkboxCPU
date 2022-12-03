#include "SparkboxVideoManager.hpp"

SparkboxVideoManager::SparkboxVideoManager()
{
    gpuDataModel = new GpuModel_TypeDef();
    allLayerNames.reserve(MAX_LAYERS);
}

SparkboxVideoManager::~SparkboxVideoManager()
{
    if (driver != NULL && isInitialized) {
       driver->hostDeinitialize(); 
    }
}

sparkboxError_t SparkboxVideoManager::linkDriver(const SparkboxVideoDriver_TypeDef* videoDriver)
{
    driver = NULL;
    // New driver, low level is no longer initialized
    isInitialized = 0;

    if (videoDriver == NULL ||
        videoDriver->gpuStartAddress == NULL ||
		videoDriver->hostInitialize == NULL ||
        videoDriver->hostBeginDMATx == NULL ||
		videoDriver->hostDeinitialize == NULL) {
		return SparkboxError::VIDEO_DRIVER_STRUCT_INVALID;
	} else {
		driver = videoDriver;
		isInitialized = 0; 
		return SparkboxError::SPARK_OK;
	}
}

sparkboxError_t SparkboxVideoManager::initialize()
{
    sparkboxError_t status;

    // Check for a valid host driver
	if (driver == NULL) {
		return SparkboxError::VIDEO_DRIVER_STRUCT_INVALID;
	} else if (isInitialized) {
		return SparkboxError::SPARK_OK;
	}

    // Initialize the host
	status = driver->hostInitialize();
    if (status == SparkboxError::SPARK_OK) isInitialized = 1;
	return status;
}


void SparkboxVideoManager::DMATransferCompleteCallback()
{
    // Finished transferring data to the GPU, unlock the data
    gpuDataLocked = 0;
    return;
}

void SparkboxVideoManager::videoThreadFunction()
{
    sparkboxError_t status;

    // Do nothing until initialized
	while (!isInitialized) {
		osDelay(100);
	}

    while (1) {
        HAL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin);
        osDelay(125);
    }


    while(1) {
        // Wait for any ongoing render to end and until max frame rate overrun is avoided
        while (gpuDataLocked /*&& isFrameRendering()*/) {
            osDelay(1);
        }

        // Lock all GPU data
        gpuDataLocked = 1;
        // Send all data to the GPU and begin a render
        status = driver->hostBeginDMATx(driver->gpuStartAddress, gpuDataModel, sizeof(GpuModel_TypeDef));
    }
}