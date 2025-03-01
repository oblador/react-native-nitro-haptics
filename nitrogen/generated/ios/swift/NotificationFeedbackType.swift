///
/// NotificationFeedbackType.swift
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2025 Marc Rousavy @ Margelo
///

/**
 * Represents the JS union `NotificationFeedbackType`, backed by a C++ enum.
 */
public typealias NotificationFeedbackType = margelo.nitro.haptics.NotificationFeedbackType

public extension NotificationFeedbackType {
  /**
   * Get a NotificationFeedbackType for the given String value, or
   * return `nil` if the given value was invalid/unknown.
   */
  init?(fromString string: String) {
    switch string {
      case "success":
        self = .success
      case "warning":
        self = .warning
      case "error":
        self = .error
      default:
        return nil
    }
  }

  /**
   * Get the String value this NotificationFeedbackType represents.
   */
  var stringValue: String {
    switch self {
      case .success:
        return "success"
      case .warning:
        return "warning"
      case .error:
        return "error"
    }
  }
}
