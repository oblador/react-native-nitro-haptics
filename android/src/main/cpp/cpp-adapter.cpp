#include <jni.h>
#include "NitroHapticsOnLoad.hpp"

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void*) {
  return facebook::jni::initialize(vm, []() {
    margelo::nitro::haptics::registerAllNatives();
  });
}
