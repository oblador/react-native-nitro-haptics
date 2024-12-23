#include <jni.h>
#include "NitroHapticsOnLoad.hpp"

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void*) {
  return margelo::nitro::haptics::initialize(vm);
}
