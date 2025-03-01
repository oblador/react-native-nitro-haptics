import { type HybridObject } from 'react-native-nitro-modules';

/**
 * The type of notification feedback generated by a UINotificationFeedbackGenerator object.
 * [`UINotificationFeedbackType`](https://developer.apple.com/documentation/uikit/uinotificationfeedbacktype)
 */
export type NotificationFeedbackType = 'success' | 'warning' | 'error';

/**
 * The mass of the objects in the collision simulated by a UIImpactFeedbackGenerator object
 * [`UIImpactFeedbackStyle`](https://developer.apple.com/documentation/uikit/uiimpactfeedbackstyle)
 */
export type ImpactFeedbackStyle =
  | 'light'
  | 'medium'
  | 'heavy'
  | 'soft'
  | 'rigid';

/**
 * Constants to be used to perform haptic feedback effects on Android, see
 * [`HapticFeedbackConstants`](https://developer.android.com/reference/android/view/HapticFeedbackConstants.html)
 */
export type AndroidHaptics =
  | 'confirm'
  | 'reject'
  | 'gesture-start'
  | 'gesture-end'
  | 'toggle-on'
  | 'toggle-off'
  | 'clock-tick'
  | 'context-click'
  | 'drag-start'
  | 'keyboard-tap'
  | 'keyboard-press'
  | 'keyboard-release'
  | 'long-press'
  | 'virtual-key'
  | 'virtual-key-release'
  | 'no-haptics'
  | 'segment-tick'
  | 'segment-frequent-tick'
  | 'text-handle-move';

export interface Haptics
  extends HybridObject<{ ios: 'swift'; android: 'kotlin' }> {
  impact(style: ImpactFeedbackStyle): void;
  notification(type: NotificationFeedbackType): void;
  selection(): void;
  performAndroidHaptics(type: AndroidHaptics): void;
}
