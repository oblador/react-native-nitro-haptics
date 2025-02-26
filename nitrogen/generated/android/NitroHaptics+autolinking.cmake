#
# NitroHaptics+autolinking.cmake
# This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
# https://github.com/mrousavy/nitro
# Copyright © 2025 Marc Rousavy @ Margelo
#

# This is a CMake file that adds all files generated by Nitrogen
# to the current CMake project.
#
# To use it, add this to your CMakeLists.txt:
# ```cmake
# include(${CMAKE_SOURCE_DIR}/../nitrogen/generated/android/NitroHaptics+autolinking.cmake)
# ```

# Add all headers that were generated by Nitrogen
include_directories(
  "../nitrogen/generated/shared/c++"
  "../nitrogen/generated/android/c++"
  "../nitrogen/generated/android/"
)

# Add all .cpp sources that were generated by Nitrogen
target_sources(
  # CMake project name (Android C++ library name)
  NitroHaptics PRIVATE
  # Autolinking Setup
  ../nitrogen/generated/android/NitroHapticsOnLoad.cpp
  # Shared Nitrogen C++ sources
  ../nitrogen/generated/shared/c++/HybridHapticsSpec.cpp
  # Android-specific Nitrogen C++ sources
  ../nitrogen/generated/android/c++/JHybridHapticsSpec.cpp
)

# Define a flag to check if we are building properly
add_definitions(-DBUILDING_NITROHAPTICS_WITH_GENERATED_CMAKE_PROJECT)

# From node_modules/react-native/ReactAndroid/cmake-utils/folly-flags.cmake
# Used in node_modules/react-native/ReactAndroid/cmake-utils/ReactNative-application.cmake
 target_compile_definitions(
  NitroHaptics PRIVATE
  -DFOLLY_NO_CONFIG=1
  -DFOLLY_HAVE_CLOCK_GETTIME=1
  -DFOLLY_USE_LIBCPP=1
  -DFOLLY_CFG_NO_COROUTINES=1
  -DFOLLY_MOBILE=1
  -DFOLLY_HAVE_RECVMMSG=1
  -DFOLLY_HAVE_PTHREAD=1
  # Once we target android-23 above, we can comment
  # the following line. NDK uses GNU style stderror_r() after API 23.
  -DFOLLY_HAVE_XSI_STRERROR_R=1
)

# Add all libraries required by the generated specs
find_package(fbjni REQUIRED) # <-- Used for communication between Java <-> C++
find_package(ReactAndroid REQUIRED) # <-- Used to set up React Native bindings (e.g. CallInvoker/TurboModule)
find_package(react-native-nitro-modules REQUIRED) # <-- Used to create all HybridObjects and use the Nitro core library

# Link all libraries together
target_link_libraries(
        NitroHaptics
        fbjni::fbjni                              # <-- Facebook C++ JNI helpers
        ReactAndroid::jsi                         # <-- RN: JSI
        react-native-nitro-modules::NitroModules  # <-- NitroModules Core :)
)

# Link react-native (different prefab between RN 0.75 and RN 0.76)
if(ReactAndroid_VERSION_MINOR GREATER_EQUAL 76)
    target_link_libraries(
        NitroHaptics
        ReactAndroid::reactnative                 # <-- RN: Native Modules umbrella prefab
    )
else()
    target_link_libraries(
        NitroHaptics
        ReactAndroid::react_nativemodule_core     # <-- RN: TurboModules Core
    )
endif()
