///
/// HybridHapticsSpec.swift
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2025 Marc Rousavy @ Margelo
///

import Foundation
import NitroModules

/// See ``HybridHapticsSpec``
public protocol HybridHapticsSpec_protocol: HybridObject {
  // Properties
  

  // Methods
  func impact(style: ImpactFeedbackStyle) throws -> Void
  func notification(type: NotificationFeedbackType) throws -> Void
  func selection() throws -> Void
  func performAndroidHaptics(type: AndroidHaptics) throws -> Void
}

/// See ``HybridHapticsSpec``
public class HybridHapticsSpec_base {
  private weak var cxxWrapper: HybridHapticsSpec_cxx? = nil
  public func getCxxWrapper() -> HybridHapticsSpec_cxx {
  #if DEBUG
    guard self is HybridHapticsSpec else {
      fatalError("`self` is not a `HybridHapticsSpec`! Did you accidentally inherit from `HybridHapticsSpec_base` instead of `HybridHapticsSpec`?")
    }
  #endif
    if let cxxWrapper = self.cxxWrapper {
      return cxxWrapper
    } else {
      let cxxWrapper = HybridHapticsSpec_cxx(self as! HybridHapticsSpec)
      self.cxxWrapper = cxxWrapper
      return cxxWrapper
    }
  }
}

/**
 * A Swift base-protocol representing the Haptics HybridObject.
 * Implement this protocol to create Swift-based instances of Haptics.
 * ```swift
 * class HybridHaptics : HybridHapticsSpec {
 *   // ...
 * }
 * ```
 */
public typealias HybridHapticsSpec = HybridHapticsSpec_protocol & HybridHapticsSpec_base
