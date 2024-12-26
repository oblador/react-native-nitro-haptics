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

export interface Haptics
  extends HybridObject<{ ios: 'swift'; android: 'kotlin' }> {
  impact(style: ImpactFeedbackStyle): void;
  notification(type: NotificationFeedbackType): void;
  selection(): void;
}
