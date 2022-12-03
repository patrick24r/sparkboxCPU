BOARD = NUCLEO-H743ZI2

TARGET_DIR = $(dir $(realpath $(lastword $(MAKEFILE_LIST))))
SOURCE_DIR = $(TARGET_DIR)/boardConfig/$(BOARD)

SYNC_FILES_EXCLUDE := \
	Makefile \
	Middlewares/FreeRTOS \
	Middlewares/Sparkbox

SYNC_FILES_EXCLUDE += $(shell find $(TARGET_DIR) -name [^.]*.ioc)

all: sync

sync:
	rsync -avhC --delete

clean: