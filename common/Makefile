###########################################################
# Copy STM32CubeMX generated files to the common directory
BOARD = NUCLEO-H743ZI2
###########################################################

DEST_DIR = $(dir $(realpath $(lastword $(MAKEFILE_LIST))))
SOURCE_DIR = $(dir $(DEST_DIR)../boardConfig/$(BOARD)/)

# Filters of files to exclude
SYNC_FILES_EXCLUDE := \
	Makefile \
	*.ioc \
	*.ld \
	*.s \
	.mxproject \
	**/FreeRTOS \
	**/Sparkbox \
	SPARKBOX_HOST

EXCLUDE_FLAGS = $(addprefix --exclude=, $(SYNC_FILES_EXCLUDE))

all: sync

sync:
	rsync -avhmP $(EXCLUDE_FLAGS) $(SOURCE_DIR) $(DEST_DIR)