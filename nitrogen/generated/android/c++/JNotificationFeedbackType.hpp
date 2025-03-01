///
/// JNotificationFeedbackType.hpp
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2025 Marc Rousavy @ Margelo
///

#pragma once

#include <fbjni/fbjni.h>
#include "NotificationFeedbackType.hpp"

namespace margelo::nitro::haptics {

  using namespace facebook;

  /**
   * The C++ JNI bridge between the C++ enum "NotificationFeedbackType" and the the Kotlin enum "NotificationFeedbackType".
   */
  struct JNotificationFeedbackType final: public jni::JavaClass<JNotificationFeedbackType> {
  public:
    static auto constexpr kJavaDescriptor = "Lcom/margelo/nitro/haptics/NotificationFeedbackType;";

  public:
    /**
     * Convert this Java/Kotlin-based enum to the C++ enum NotificationFeedbackType.
     */
    [[maybe_unused]]
    [[nodiscard]]
    NotificationFeedbackType toCpp() const {
      static const auto clazz = javaClassStatic();
      static const auto fieldOrdinal = clazz->getField<int>("_ordinal");
      int ordinal = this->getFieldValue(fieldOrdinal);
      return static_cast<NotificationFeedbackType>(ordinal);
    }

  public:
    /**
     * Create a Java/Kotlin-based enum with the given C++ enum's value.
     */
    [[maybe_unused]]
    static jni::alias_ref<JNotificationFeedbackType> fromCpp(NotificationFeedbackType value) {
      static const auto clazz = javaClassStatic();
      static const auto fieldSUCCESS = clazz->getStaticField<JNotificationFeedbackType>("SUCCESS");
      static const auto fieldWARNING = clazz->getStaticField<JNotificationFeedbackType>("WARNING");
      static const auto fieldERROR = clazz->getStaticField<JNotificationFeedbackType>("ERROR");
      
      switch (value) {
        case NotificationFeedbackType::SUCCESS:
          return clazz->getStaticFieldValue(fieldSUCCESS);
        case NotificationFeedbackType::WARNING:
          return clazz->getStaticFieldValue(fieldWARNING);
        case NotificationFeedbackType::ERROR:
          return clazz->getStaticFieldValue(fieldERROR);
        default:
          std::string stringValue = std::to_string(static_cast<int>(value));
          throw std::invalid_argument("Invalid enum value (" + stringValue + "!");
      }
    }
  };

} // namespace margelo::nitro::haptics
