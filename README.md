# sparkboxCPU

Games are broken up into levels. Each level has a maximum audio and sprite data size.

### Hardware Connectivity

SDRAM - Decoded audio storage
GPU - over SRAM interface


### Directory Structure

#### startupLevelLoader
This is the program launched on console startup. It loads and launches the console OS from the storage drive.

#### consoleOSLevel
This is a single level that provides a screen to select which game to play from all available games on the storage drive.

#### common
Contains all code common to the console OS and each level