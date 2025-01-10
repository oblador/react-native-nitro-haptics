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

  // Custom method to allow impact with intensity
  func impactWithIntensity(style: ImpactFeedbackStyle, intensity: Double) throws -> Void {
    // Ensure intensity is within the range (0, 1]
    guard intensity >= 0 && intensity <= 1 else {
      throw NSError(domain: "HybridHaptics", code: 1, userInfo: [NSLocalizedDescriptionKey: "Intensity must be greater than 0 and less than or equal to 1"])
    }
    // Create feedback generator with the appropriate style
    let generator = UIImpactFeedbackGenerator(style: style.toUIImpactFeedbackType())
    generator.prepare()
    generator.impactOccurred(intensity: CGFloat(intensity))
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
