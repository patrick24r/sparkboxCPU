all: consoleOS levelLoader

flash: all
	$(MAKE) -C startupLevelLoader flash

consoleOS: common
	$(MAKE) -C consoleOSLevel

levelLoader: common
	$(MAKE) -C startupLevelLoader

common:
	$(MAKE) -C common

.PHONY: common