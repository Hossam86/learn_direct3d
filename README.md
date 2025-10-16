# MyDirectXApp - vcpkg + CMake instructions

This small project demonstrates how to integrate DirectX dependencies using vcpkg with CMake.

Prerequisites

- Windows with Visual Studio (MSVC) and CMake installed.
- vcpkg (<https://github.com/microsoft/vcpkg>)

Quick setup

1. Install vcpkg (if not already):

  git clone <https://github.com/microsoft/vcpkg.git>
  .\vcpkg\bootstrap-vcpkg.bat

1. Install required packages (example uses DirectX Tool Kit):

  .\vcpkg\vcpkg install directxtk

1. Configure CMake to use vcpkg toolchain. There are two common ways:


  - Set environment variable `VCPKG_ROOT` to the vcpkg folder (CMakeLists will auto-detect).
  - Or pass the toolchain file directly when configuring CMake:

    cmake -S . -B build -DCMAKE_TOOLCHAIN_FILE=C:/path/to/vcpkg/scripts/buildsystems/vcpkg.cmake

1. Build:

  cmake --build build --config Debug

Notes
- The `CMakeLists.txt` in this project will attempt to use `VCPKG_ROOT` if `CMAKE_TOOLCHAIN_FILE` is not already set. If you prefer not to use the environment variable, pass `-DCMAKE_TOOLCHAIN_FILE` explicitly.

- If you add more vcpkg packages, install them with `vcpkg install <pkg>` and CMake should find them when the toolchain file is used.

## Troubleshooting

- If CMake can't find a package installed by vcpkg, ensure the same triplet was used (e.g., x64-windows) and that the toolchain file is the one from the same vcpkg installation.
License: MIT
