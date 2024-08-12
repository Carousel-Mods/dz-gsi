# Load environment variables from .env file
include .env

# === PDrive paths =====================================================================================
P_SOURCE := $(P_DRIVE_SOURCE_PATH)
P_BUILDS := $(P_DRIVE_BUILDS_PATH)
PBIP_KEY := $(BIP_PRIVATE_KEY)

# === Config ===========================================================================================
.DEFAULT_GOAL := build

# === Tasks ============================================================================================

# Clean before build
clean:
	@echo "[MAKE] <- Cleaning up source directory ->"
	@rmdir /S /Q $(P_SOURCE) || true
	@echo "[MAKE] <- Cleaning up logs directory ->"
	@./utils/cleaner.bat

# Copy mod files to P:/ drive
copy: clean
	@echo "[MAKE] <- Copying files ->"
	@xcopy /E /I /Y * $(P_SOURCE)

# Automatic mod building
build: copy
	@echo "[MAKE] <- Building addons ->"
	@AddonBuilder.exe $(P_SOURCE) $(P_BUILDS)\addons -packonly -sign=$(PBIP_KEY) -project=P: -prefix=DayzGSI > logs\build.log 2>&1
	@findstr /C:"Build Successful" build.log >nul && (echo "[MAKE] !!! Build successful !!!") || (echo "[MAKE] !!! Build failed !!!" && exit /b 1)

# Run the game
run: build
	@echo "[MAKE] <- Running the game ->"
	./utils/debug.bat

# Prevent make from complaining if the target doesn't exist
.PHONY: clean copy build