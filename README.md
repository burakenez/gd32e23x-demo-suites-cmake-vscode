[![GitHub tag (latest by date)](https://img.shields.io/github/v/tag/burakenez/gd32e23x-demo-suites-cmake-vscode)](https://github.com/burakenez/gd32e23x-demo-suites-cmake-vscode/tags/)

# GD32E23x Demo Suites CMake Visual Studio Code Integration

🚀 Welcome to the **GD32E23x Demo Suites CMake Visual Studio Code** repository! This project is designed to integrate the CMake build system with Visual Studio Code, providing a streamlined development environment for **_GD32E23x Demo Suites V2.4.0_**.

## ✨ Features
- **📦 Comprehensive Integration:** Pre-configured CMake and VS Code settings for seamless builds and debugging.
- **🔧 Toolchain Support:** Default configuration for **xPack GNU Arm Embedded GCC Toolchain** and **OpenOCD**.
- **⚙️ Customizability:** Easily adapt paths and configurations for your preferred toolchain or target MCU.
- **🧩 Lightweight Templates:** A structured and organized template for GD32E23x microcontroller projects.
- **🔍 Rich Extension Support:**
  - 🐞 Recommended extensions like `ms-vscode.cmake-tools`, `marus25.cortex-debug`, and `xaver.clang-format` ensure enhanced functionality for CMake, debugging, and code formatting.
  - 🖼️ Peripheral viewers, RTOS views, and other utilities provide an extensive debugging experience.
  - 🎨 The `vscode-icons-team.vscode-icons` extension offers visually improved folder and file navigation.
- **🛠️ Robust Debug Configuration:**
  - Pre-configured `launch.json` supports debugging with OpenOCD.
  - Features such as live watch, entry-point settings, and automated pre-launch build tasks streamline the debugging process.
  - Fully compatible with SVD files for enhanced peripheral visualization and live memory updates.

---

## Versions of Sub-Modules

### 1. **xPack GNU Arm Embedded GCC Toolchain**
- **Version:** _xpack-arm-none-eabi-gcc-11.3.1-1.1_
- **Path:** `Tools/xpack-arm-none-eabi-gcc-11.3.1-1.1`
- **Customization:**
  - Update the paths in these files:
    - `Projects/<BoardName>/<ProjectName>/cmake/arm-none-eabi-gcc.cmake` (line 2):
      ```cmake
      set(TOOLCHAIN_DIRECTORY "${CMAKE_SOURCE_DIR}/../../../Tools/xpack-arm-none-eabi-gcc-11.3.1-1.1/bin")
      ```
    - `Projects/<BoardName>/<ProjectName>/.vscode/launch.json` (line 12):
      ```json
      "gdbPath": "${workspaceFolder}/../../../Tools/xpack-arm-none-eabi-gcc-11.3.1-1.1/bin/arm-none-eabi-gdb.exe"
      ```
- [Download alternative versions here](https://github.com/xpack-dev-tools/arm-none-eabi-gcc-xpack/releases).

### 2. **OpenOCD**
- **Version:** _xpack-openocd-0.11.0-3_
- **Path:** `Tools/xpack-openocd-0.11.0-3`
- **Notes:**
  - Extracted from **Embedded Builder V1.4.1.23782**.
  - ⚠️ Avoid using other versions due to limited support for GD32 MCUs.
  - Update paths in these files if necessary:
    - `Projects/<BoardName>/<ProjectName>/.vscode/launch.json` (lines 14, 17):
      ```json
      "serverpath": "${workspaceFolder}/../../../Tools/xpack-openocd-0.11.0-3/bin/openocd.exe"
      ```
      ```json
      "${workspaceFolder}/../../../Tools/xpack-openocd-0.11.0-3/scripts/target/openocd_gdlink_gd32e23x.cfg"
      ```
    - `Projects/<BoardName>/<ProjectName>/.vscode/task.json`: Update all occurrences of:
      ```
      ${workspaceFolder}/../../../Tools/xpack-openocd-0.11.0-3
      ```

---

## Versions of Drivers and Middlewares

### 1. **CMSIS**
- **Version:** `V6.1`
- **Path:** `Drivers/CMSIS`

### 2. **CMSIS/GD/GD32E23x**
- **Version:** `V2.3.0 (2025-02-10)`
- **Path:** `Drivers/CMSIS/GD/GD32E23x`
- Extracted from `GD32E23x Demo Suites V2.4.0`

### 3. **GD32E23x_standard_peripheral**
- **Version:** `V2.3.0 (2025-02-10)`
- **Path:** `Drivers/GD32E23x_standard_peripheral`

---

## 🔧 Getting Started

### 1. 🖥️ Install Required Tools
1. **Visual Studio Code:** [Download here](https://code.visualstudio.com/).
2. **Git:** [Download here](https://git-scm.com/downloads).
   - If installed in a custom directory, update this path in `Projects/<BoardName>/<ProjectName>/.vscode/settings.json` (line 5):
     ```json
     "path": "C:\Program Files\Git\bin\bash.exe"
     ```

### 2. 📥 Clone the Repository
```bash
cd C:/gd32-cmake
# Clone the repository recursively to include submodules
git clone --recursive https://github.com/burakenez/gd32e23x-demo-suites-cmake-vscode.git
```
- ⚠️ Avoid long directory paths to prevent build issues.
- If downloading as a ZIP, manually include submodules in the `Tools` folder:
  - `xpack-arm-none-eabi-gcc-11.3.1-1.1`
  - `xpack-openocd-0.11.0-3`

### 3. 📂 Open Project Folder
- Open `Projects/<BoardName>/<ProjectName>` directly in Visual Studio Code.

### 4. 🧩 Install Recommended Extensions
- Extensions listed in `Projects/<BoardName>/<ProjectName>/.vscode/extensions.json` will be auto-installed.

### 5. ⚙️ Configure `cmake` and `ninja`
- These tools will be downloaded automatically using `vcpkg-configuration.json`.
- Update the vcpkg storage location in `Projects/<BoardName>/<ProjectName>/.vscode/settings.json` (line 15):
  ```json
  "vcpkg.storageLocation": "C:\Dev\Tools\vcpkg"
  ```
- Add paths to environment variables:
  - `cmake.exe`: `C:\Dev\Tools\vcpkg\root\downloads\artifacts\vcpkg-artifacts-arm\tools.kitware.cmake\3.28.4\bin`
  - `ninja.exe`: `C:\Dev\Tools\vcpkg\root\downloads\artifacts\vcpkg-artifacts-arm\tools.ninja.build.ninja\1.12.0`
- Restart your computer after installation.

### 6. 🛠️ Set CMake Preset
- Select **Debug** or **Release** from the CMake presets menu in VS Code.

### 7. 🔨 Build the Project
- Build options:
  - Click the **Build** button in the bottom panel.
  - Press `[CTRL + SHIFT + P]`, search for **CMake: Build**, and run.
  - Press `[CTRL + SHIFT + B]` to open configured tasks and select **Build**.
- Output files are generated in `Projects/<BoardName>/<ProjectName>/Build/Debug/Application/` or `.../Release/Application/`.

### 8. 🐞 Debug the Project
- Go to **Run and Debug** in VS Code.
- Select **Debug with OpenOCD** and press `[F5]` or click **Start Debugging**.

---

## 📂 Folder Structure

```plaintext
┌── Drivers  # Contains low-level drivers for hardware abstraction and CMSIS compatibility.
├── Middlewares  # Houses middleware libraries and third-party integrations.
├── Projects  # Holds board-specific project examples.
│   └── <BoardName>
│       └── <ProjectName>
│           ├── .vscode
│           │   ├── extensions.json      # Specifies recommended VS Code extensions for automatic installation.
│           │   ├── launch.json          # Debugging configuration, including paths to toolchain binaries.
│           │   ├── settings.json        # Project-specific workspace settings, such as paths for external tools.
│           │   └── tasks.json           # Defines build tasks and automation scripts for the VS Code environment.
│           ├── Application
│           │   ├── Core
│           │   │   ├── Inc
│           │   │   │   ├── gd32e23x_it.h  # Interrupt handler declarations specific to GD32E23x.
│           │   │   │   ├── gd32e23x_libopt.h  # Library options and configurations for efficient use.
│           │   │   │   └── systick.h  # Definitions and declarations related to the SysTick timer.
│           │   │   ├── Src
│           │   │   │   ├── gd32e23x_it.c  # Interrupt service routine implementations.
│           │   │   │   ├── main.c  # Entry point of the application, containing the main logic and system initialization.
│           │   │   │   ├── system_gd32e23x.c  # System initialization, clock setup, and core configurations.
│           │   │   │   └── systick.c  # SysTick timer setup and related functionalities.
│           │   ├── Startup
│           │   │   └── startup_gd32e23x.s  # Assembly code for initialization and vector table setup.
│           │   ├── User
│           │   │   └── syscalls.c  # Implements low-level system calls and I/O retargeting for the project.
│           │   ├── CMakeLists.txt  # CMake build instructions for the application.
│           │   └── readme.txt  # Brief notes and usage instructions for the application folder.
│           ├── Build
│           │   ├── Debug
│           │   │   └── Application
│           │   │       ├── Application.bin  # Binary file ready for flashing to the device.
│           │   │       ├── Application.elf  # Executable and Linkable Format file with debugging symbols.
│           │   │       ├── Application.hex  # Intel HEX file format for programming the microcontroller.
│           │   │       ├── Application.map  # Memory map of the application.
│           │   │       ├── Application.list # Assembly listing of the code.
│           │   │       └── Other files...   # Includes additional build outputs such as symbol tables.
│           ├── cmake
│           │   ├── arm-none-eabi-gcc.cmake  # Specifies toolchain settings for ARM GCC.
│           │   └── project.cmake  # General project-wide CMake configurations.
│           ├── Drivers
│           │   ├── BSP/GD32E235V_START  # Board support package configurations and drivers for GD32E235V_START.
│           │   ├── CMSIS  # CMSIS drivers for Cortex-M processors, supporting GD32E23x.
│           │   └── GD32E23x_standard_peripheral  # Peripheral library for GD32E23x.
│           ├── Middlewares  # Additional middleware or third-party libraries used in the project.
│           ├── Utilities  # Utility scripts, tools, and additional helper files for development.
│           ├── .clang-format  # Code formatting rules for maintaining a consistent coding style.
│           ├── CMakeLists.txt  # Main CMake build file for the entire project.
│           ├── CMakePresets.json  # Preset configurations for easier CMake builds.
│           ├── gd32e23x_flash.ld  # Linker script for defining memory regions and placements.
│           └── GD32E23x.svd  # System View Description file for debugging and register definitions. 
├── Tools  # Compilers, debuggers, and other tools required for building and debugging.
└── Utilities  # Shared utilities and helper scripts applicable across projects.
```

---

## 📚 Additional Information
Feel free to customize this template as per your project requirements. Contributions and feedback are always welcome!
