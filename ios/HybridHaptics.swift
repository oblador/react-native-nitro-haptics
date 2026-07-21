//
//  HybridHaptics.swift
//  react-native-nitro-haptics
//
//  Created by Joel Arvidsson on 23.12.24.
//

import Foundation
import UIKit
import NitroModules

/**
 * Implement `HybridHapticsSpec` so we can expose this Swift class to JS.
 *
 * Nitro invokes these methods synchronously on the JS thread, but
 * UIFeedbackGenerator is main-thread-only UIKit API. Every call is bounced to
 * the main queue, and generators are reused between calls so the underlying
 * haptic engine is not activated/deactivated on every event.
 */
class HybridHaptics : HybridHapticsSpec {
  private var impactGenerators: [UIImpactFeedbackGenerator.FeedbackStyle: UIImpactFeedbackGenerator] = [:]
  private var notificationGenerator: UINotificationFeedbackGenerator? = nil
  private var selectionGenerator: UISelectionFeedbackGenerator? = nil

  func impact(style: ImpactFeedbackStyle) throws -> Void {
    let uiStyle = style.toUIImpactFeedbackType()
    DispatchQueue.main.async {
      let generator: UIImpactFeedbackGenerator
      if let cached = self.impactGenerators[uiStyle] {
        generator = cached
      } else {
        generator = UIImpactFeedbackGenerator(style: uiStyle)
        self.impactGenerators[uiStyle] = generator
      }
      generator.impactOccurred()
    }
  }

  func notification(type: NotificationFeedbackType) throws -> Void {
    let uiType = type.toUINotificationFeedbackType()
    DispatchQueue.main.async {
      let generator = self.notificationGenerator ?? UINotificationFeedbackGenerator()
      self.notificationGenerator = generator
      generator.notificationOccurred(uiType)
    }
  }

  func selection() throws -> Void {
    DispatchQueue.main.async {
      let generator = self.selectionGenerator ?? UISelectionFeedbackGenerator()
      self.selectionGenerator = generator
      generator.selectionChanged()
    }
  }

  func performAndroidHaptics(type: AndroidHaptics) throws -> Void {
    throw RuntimeError.error(withMessage: "AndroidHaptics not supported outside of Android")
  }
}

extension ImpactFeedbackStyle {
  func toUIImpactFeedbackType() -> UIImpactFeedbackGenerator.FeedbackStyle {
    switch self {
    case .light:
      return .light
    case .medium:
      return .medium
    case .heavy:
      return .heavy
    case .soft:
      return .soft
    case .rigid:
      return .rigid
    }
  }
}

extension NotificationFeedbackType {
  func toUINotificationFeedbackType() -> UINotificationFeedbackGenerator.FeedbackType {
    switch self {
    case .success:
      return .success
    case .warning:
      return .warning
    case .error:
      return .error
    }
  }
}
