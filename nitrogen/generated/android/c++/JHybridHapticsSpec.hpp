///
/// HybridHapticsSpec.hpp
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2025 Marc Rousavy @ Margelo
///

#pragma once

#include <NitroModules/JHybridObject.hpp>
#include <fbjni/fbjni.h>
#include "HybridHapticsSpec.hpp"




namespace margelo::nitro::haptics {

  using namespace facebook;

  class JHybridHapticsSpec: public jni::HybridClass<JHybridHapticsSpec, JHybridObject>,
                            public virtual HybridHapticsSpec {
  public:
    static auto constexpr kJavaDescriptor = "Lcom/margelo/nitro/haptics/HybridHapticsSpec;";
    static jni::local_ref<jhybriddata> initHybrid(jni::alias_ref<jhybridobject> jThis);
    static void registerNatives();

  protected:
    // C++ constructor (called from Java via `initHybrid()`)
    explicit JHybridHapticsSpec(jni::alias_ref<jhybridobject> jThis) :
      HybridObject(HybridHapticsSpec::TAG),
      _javaPart(jni::make_global(jThis)) {}

  public:
    virtual ~JHybridHapticsSpec() {
      // Hermes GC can destroy JS objects on a non-JNI Thread.
      jni::ThreadScope::WithClassLoader([&] { _javaPart.reset(); });
    }

  public:
    size_t getExternalMemorySize() noexcept override;

  public:
    inline const jni::global_ref<JHybridHapticsSpec::javaobject>& getJavaPart() const noexcept {
      return _javaPart;
    }

  public:
    // Properties
    

  public:
    // Methods
    void impact(ImpactFeedbackStyle style) override;
    void notification(NotificationFeedbackType type) override;
    void selection() override;
    void impactWithIntensity(ImpactFeedbackStyle style, double intensity) override;

  private:
    friend HybridBase;
    using HybridBase::HybridBase;
    jni::global_ref<JHybridHapticsSpec::javaobject> _javaPart;
  };

} // namespace margelo::nitro::haptics
