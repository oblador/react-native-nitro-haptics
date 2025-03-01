///
/// JImpactFeedbackStyle.hpp
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2025 Marc Rousavy @ Margelo
///

#pragma once

#include <fbjni/fbjni.h>
#include "ImpactFeedbackStyle.hpp"

namespace margelo::nitro::haptics {

  using namespace facebook;

  /**
   * The C++ JNI bridge between the C++ enum "ImpactFeedbackStyle" and the the Kotlin enum "ImpactFeedbackStyle".
   */
  struct JImpactFeedbackStyle final: public jni::JavaClass<JImpactFeedbackStyle> {
  public:
    static auto constexpr kJavaDescriptor = "Lcom/margelo/nitro/haptics/ImpactFeedbackStyle;";

  public:
    /**
     * Convert this Java/Kotlin-based enum to the C++ enum ImpactFeedbackStyle.
     */
    [[maybe_unused]]
    [[nodiscard]]
    ImpactFeedbackStyle toCpp() const {
      static const auto clazz = javaClassStatic();
      static const auto fieldOrdinal = clazz->getField<int>("_ordinal");
      int ordinal = this->getFieldValue(fieldOrdinal);
      return static_cast<ImpactFeedbackStyle>(ordinal);
    }

  public:
    /**
     * Create a Java/Kotlin-based enum with the given C++ enum's value.
     */
    [[maybe_unused]]
    static jni::alias_ref<JImpactFeedbackStyle> fromCpp(ImpactFeedbackStyle value) {
      static const auto clazz = javaClassStatic();
      static const auto fieldLIGHT = clazz->getStaticField<JImpactFeedbackStyle>("LIGHT");
      static const auto fieldMEDIUM = clazz->getStaticField<JImpactFeedbackStyle>("MEDIUM");
      static const auto fieldHEAVY = clazz->getStaticField<JImpactFeedbackStyle>("HEAVY");
      static const auto fieldSOFT = clazz->getStaticField<JImpactFeedbackStyle>("SOFT");
      static const auto fieldRIGID = clazz->getStaticField<JImpactFeedbackStyle>("RIGID");
      
      switch (value) {
        case ImpactFeedbackStyle::LIGHT:
          return clazz->getStaticFieldValue(fieldLIGHT);
        case ImpactFeedbackStyle::MEDIUM:
          return clazz->getStaticFieldValue(fieldMEDIUM);
        case ImpactFeedbackStyle::HEAVY:
          return clazz->getStaticFieldValue(fieldHEAVY);
        case ImpactFeedbackStyle::SOFT:
          return clazz->getStaticFieldValue(fieldSOFT);
        case ImpactFeedbackStyle::RIGID:
          return clazz->getStaticFieldValue(fieldRIGID);
        default:
          std::string stringValue = std::to_string(static_cast<int>(value));
          throw std::invalid_argument("Invalid enum value (" + stringValue + "!");
      }
    }
  };

} // namespace margelo::nitro::haptics
