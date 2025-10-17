# Minimum CMake version
cmake_minimum_required(VERSION 3.20)

# If the user didn't pass a toolchain file, try to detect vcpkg using the
# VCPKG_ROOT environment variable and set the vcpkg toolchain file so that
# packages installed with vcpkg are discoverable via find_package(... CONFIG).
if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
	if(DEFINED ENV{VCPKG_ROOT})
		set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE FILEPATH "Vcpkg toolchain file")
		message(STATUS "Using vcpkg toolchain file from VCPKG_ROOT: ${CMAKE_TOOLCHAIN_FILE}")
	else()
		message(STATUS "No CMAKE_TOOLCHAIN_FILE set and VCPKG_ROOT not found. If you use vcpkg, pass -DCMAKE_TOOLCHAIN_FILE=path/to/vcpkg.cmake or set VCPKG_ROOT.")
	endif()
	endif()
# Project
project(MyDirectXApp LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Executable (assumes there's a top-level main.cpp)
add_executable(MyDirectXApp WIN32 main.cpp)

# Try to find DirectX Tool Kit (DirectXTK) installed through vcpkg. We use
# the CONFIG mode so the vcpkg-provided config file is preferred when the
# vcpkg toolchain file is active.
find_package(DirectXTK CONFIG)
if(DirectXTK_FOUND)
	message(STATUS "Found DirectXTK via CMake: adding link to DirectXTK::DirectXTK")
	target_link_libraries(MyDirectXApp PRIVATE Microsoft::DirectXTK)
else()
	message(STATUS "DirectXTK not found. If you installed it with vcpkg, ensure the vcpkg toolchain file is used so CMake can find it.")
endif()
# Link standard Windows DirectX libraries when building for Windows
if(WIN32)
	target_link_libraries(MyDirectXApp PRIVATE d3d12 dxgi d3dcompiler)
endif()
message(STATUS "Configured project '${PROJECT_NAME}'")
