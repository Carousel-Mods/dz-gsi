include .env

# Variables
P_SOURCE := $(P_DRIVE_SOURCE_PATH)

# Default mode
.DEFAULT_GOAL := build

# Clean all log files from DayZ directory
.PHONY: clean_logs
clean_logs:
	./utils/LogsCleaner.bat

# Clean all source files to avoid conflict
.PHONY: clean_source
clean_source:
	rmdir /S /Q $(P_SOURCE)

# Copy mod files to P:/ drive
.PHONY: copy
copy: clean_logs clean_source
	xcopy /E /I /Y * $(P_SOURCE)

# TODO: Create automatic mod building
.PHONY: build
build: copy
	dir

# TODO: Create automatic mod running
.PHONY: run
run: build
	dir

.PHONY: test
test:
	dir $(P_SOURCE)
