all: consoleOS levelLoader

consoleOS: common
	$(MAKE) -C consoleOSLevel

levelLoader: common
	$(MAKE) -C startupLevelLoader

common:
	$(MAKE) -C common

.PHONY: common