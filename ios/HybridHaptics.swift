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
 */
class HybridHaptics : HybridHapticsSpec {
  func impact(style: ImpactFeedbackStyle) throws -> Void {
    let generator = UIImpactFeedbackGenerator(style: style.toUIImpactFeedbackType())
    generator.prepare()
    generator.impactOccurred()
  }

  func notification(type: NotificationFeedbackType) throws -> Void {
    let generator = UINotificationFeedbackGenerator()
    generator.prepare()
    generator.notificationOccurred(type.toUINotificationFeedbackType())
  }

  func selection() throws -> Void {
    let generator = UISelectionFeedbackGenerator()
    generator.prepare()
    generator.selectionChanged()
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
