import { NitroModules } from 'react-native-nitro-modules';
import type { Haptics as HapticsSpec } from './specs/Haptics.nitro';

export type {
  ImpactFeedbackStyle,
  NotificationFeedbackType,
} from './specs/Haptics.nitro';

export const Haptics = NitroModules.createHybridObject<HapticsSpec>('Haptics');
