///
/// ImpactFeedbackStyle.hpp
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2024 Marc Rousavy @ Margelo
///

#pragma once

#if __has_include(<NitroModules/NitroHash.hpp>)
#include <NitroModules/NitroHash.hpp>
#else
#error NitroModules cannot be found! Are you sure you installed NitroModules properly?
#endif
#if __has_include(<NitroModules/JSIConverter.hpp>)
#include <NitroModules/JSIConverter.hpp>
#else
#error NitroModules cannot be found! Are you sure you installed NitroModules properly?
#endif
#if __has_include(<NitroModules/NitroDefines.hpp>)
#include <NitroModules/NitroDefines.hpp>
#else
#error NitroModules cannot be found! Are you sure you installed NitroModules properly?
#endif

namespace margelo::nitro::haptics {

  /**
   * An enum which can be represented as a JavaScript union (ImpactFeedbackStyle).
   */
  enum class ImpactFeedbackStyle {
    LIGHT      SWIFT_NAME(light) = 0,
    MEDIUM      SWIFT_NAME(medium) = 1,
    HEAVY      SWIFT_NAME(heavy) = 2,
    SOFT      SWIFT_NAME(soft) = 3,
    RIGID      SWIFT_NAME(rigid) = 4,
  } CLOSED_ENUM;

} // namespace margelo::nitro::haptics

namespace margelo::nitro {

  using namespace margelo::nitro::haptics;

  // C++ ImpactFeedbackStyle <> JS ImpactFeedbackStyle (union)
  template <>
  struct JSIConverter<ImpactFeedbackStyle> {
    static inline ImpactFeedbackStyle fromJSI(jsi::Runtime& runtime, const jsi::Value& arg) {
      std::string unionValue = JSIConverter<std::string>::fromJSI(runtime, arg);
      switch (hashString(unionValue.c_str(), unionValue.size())) {
        case hashString("light"): return ImpactFeedbackStyle::LIGHT;
        case hashString("medium"): return ImpactFeedbackStyle::MEDIUM;
        case hashString("heavy"): return ImpactFeedbackStyle::HEAVY;
        case hashString("soft"): return ImpactFeedbackStyle::SOFT;
        case hashString("rigid"): return ImpactFeedbackStyle::RIGID;
        default: [[unlikely]]
          throw std::invalid_argument("Cannot convert \"" + unionValue + "\" to enum ImpactFeedbackStyle - invalid value!");
      }
    }
    static inline jsi::Value toJSI(jsi::Runtime& runtime, ImpactFeedbackStyle arg) {
      switch (arg) {
        case ImpactFeedbackStyle::LIGHT: return JSIConverter<std::string>::toJSI(runtime, "light");
        case ImpactFeedbackStyle::MEDIUM: return JSIConverter<std::string>::toJSI(runtime, "medium");
        case ImpactFeedbackStyle::HEAVY: return JSIConverter<std::string>::toJSI(runtime, "heavy");
        case ImpactFeedbackStyle::SOFT: return JSIConverter<std::string>::toJSI(runtime, "soft");
        case ImpactFeedbackStyle::RIGID: return JSIConverter<std::string>::toJSI(runtime, "rigid");
        default: [[unlikely]]
          throw std::invalid_argument("Cannot convert ImpactFeedbackStyle to JS - invalid value: "
                                    + std::to_string(static_cast<int>(arg)) + "!");
      }
    }
    static inline bool canConvert(jsi::Runtime& runtime, const jsi::Value& value) {
      if (!value.isString()) {
        return false;
      }
      std::string unionValue = JSIConverter<std::string>::fromJSI(runtime, value);
      switch (hashString(unionValue.c_str(), unionValue.size())) {
        case hashString("light"):
        case hashString("medium"):
        case hashString("heavy"):
        case hashString("soft"):
        case hashString("rigid"):
          return true;
        default:
          return false;
      }
    }
  };

} // namespace margelo::nitro
