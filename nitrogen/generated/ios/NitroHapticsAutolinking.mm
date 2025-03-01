///
/// NitroHapticsAutolinking.mm
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2025 Marc Rousavy @ Margelo
///

#import <Foundation/Foundation.h>
#import <NitroModules/HybridObjectRegistry.hpp>
#import "NitroHaptics-Swift-Cxx-Umbrella.hpp"
#import <type_traits>

#include "HybridHapticsSpecSwift.hpp"

@interface NitroHapticsAutolinking : NSObject
@end

@implementation NitroHapticsAutolinking

+ (void) load {
  using namespace margelo::nitro;
  using namespace margelo::nitro::haptics;

  HybridObjectRegistry::registerHybridObjectConstructor(
    "Haptics",
    []() -> std::shared_ptr<HybridObject> {
      std::shared_ptr<margelo::nitro::haptics::HybridHapticsSpec> hybridObject = NitroHaptics::NitroHapticsAutolinking::createHaptics();
      return hybridObject;
    }
  );
}

@end
