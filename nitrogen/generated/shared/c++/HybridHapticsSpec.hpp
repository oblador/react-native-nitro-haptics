///
/// HybridHapticsSpec.hpp
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2025 Marc Rousavy @ Margelo
///

#pragma once

#if __has_include(<NitroModules/HybridObject.hpp>)
#include <NitroModules/HybridObject.hpp>
#else
#error NitroModules cannot be found! Are you sure you installed NitroModules properly?
#endif

// Forward declaration of `ImpactFeedbackStyle` to properly resolve imports.
namespace margelo::nitro::haptics { enum class ImpactFeedbackStyle; }
// Forward declaration of `NotificationFeedbackType` to properly resolve imports.
namespace margelo::nitro::haptics { enum class NotificationFeedbackType; }

#include "ImpactFeedbackStyle.hpp"
#include "NotificationFeedbackType.hpp"

namespace margelo::nitro::haptics {

  using namespace margelo::nitro;

  /**
   * An abstract base class for `Haptics`
   * Inherit this class to create instances of `HybridHapticsSpec` in C++.
   * You must explicitly call `HybridObject`'s constructor yourself, because it is virtual.
   * @example
   * ```cpp
   * class HybridHaptics: public HybridHapticsSpec {
   * public:
   *   HybridHaptics(...): HybridObject(TAG) { ... }
   *   // ...
   * };
   * ```
   */
  class HybridHapticsSpec: public virtual HybridObject {
    public:
      // Constructor
      explicit HybridHapticsSpec(): HybridObject(TAG) { }

      // Destructor
      ~HybridHapticsSpec() override = default;

    public:
      // Properties
      

    public:
      // Methods
      virtual void impact(ImpactFeedbackStyle style) = 0;
      virtual void notification(NotificationFeedbackType type) = 0;
      virtual void selection() = 0;

    protected:
      // Hybrid Setup
      void loadHybridMethods() override;

    protected:
      // Tag for logging
      static constexpr auto TAG = "Haptics";
  };

} // namespace margelo::nitro::haptics
