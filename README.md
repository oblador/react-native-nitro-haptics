# Nitro Haptics

### Low Latency Haptic Feedback with Worklet Support for React Native

[![Follow oblador on Bluesky ](https://img.shields.io/badge/Bluesky-0285FF?style=social&logo=bluesky&label=oblador.bsky.social)](https://bsky.app/profile/oblador.bsky.social) [![X (formerly Twitter) Follow](https://img.shields.io/twitter/follow/trastknast)](https://x.com/trastknast) [![GitHub followers](https://img.shields.io/github/followers/oblador)](https://github.com/oblador)

---

[![CI](https://github.com/oblador/react-native-nitro-haptics/actions/workflows/ci.yml/badge.svg)](https://github.com/oblador/react-native-nitro-haptics/actions/workflows/ci.yml) [![NPM Version](https://img.shields.io/npm/v/react-native-nitro-haptics)](https://www.npmjs.com/package/react-native-nitro-haptics) [![NPM License](https://img.shields.io/npm/l/react-native-nitro-haptics)](https://github.com/oblador/react-native-nitro-haptics/blob/master/LICENSE)

## Features

- **Low latency** for timing interaction and feedback perfectly, thanks to extremely fast [Nitro Modules](https://nitro.margelo.com)
- **Worklet support** to ensure instant feedback even if JS thread is blocked
- Built for **New Architecture** from the start
- **Drop-in replacement** for `expo-haptics` for ease of adoption

## Installation

You need to install both Nitro Modules core package and Nitro Haptics:

```sh
npm install react-native-nitro-modules react-native-nitro-haptics
# Don't forget to update CocoaPods and recompile app:
cd ios && pod install
```

## Usage

See [Apple Human Interface Guidelines](https://developer.apple.com/design/human-interface-guidelines/playing-haptics) for best practices and references.

```tsx
import { Haptics } from 'react-native-nitro-haptics';

<Button title="Press me" onPress={() => Haptics.impact('medium')} />;
```

### Reanimated Worklets

Assuming your app has been correctly configured with Reanimated, Nitro Haptics can be called directly from the UI thread by using [Nitro Modules Boxing](https://nitro.margelo.com/docs/worklets):

```tsx
import { Gesture, GestureDetector } from 'react-native-gesture-handler';
import { Haptics } from 'react-native-nitro-haptics';
import { NitroModules } from 'react-native-nitro-modules';
const boxed = NitroModules.box(Haptics);

<GestureDetector
  gesture={Gesture.Tap().onBegin(() => {
    'worklet';
    boxed.unbox().impact('medium');
  })}
/>;
```

## API

### `Haptics.impact(style: 'light' | 'medium' | 'heavy' | 'soft' | 'rigid')`

Impact haptics provide a physical metaphor you can use to complement a visual experience. For example, people might feel a tap when a view snaps into place or a thud when two heavy objects collide.

`style` argument maps to [`UIImpactFeedbackGenerator.FeedbackStyle`](https://developer.apple.com/documentation/uikit/uiimpactfeedbackgenerator/feedbackstyle), see [HIG for visualization](https://developer.apple.com/design/human-interface-guidelines/playing-haptics#Impact).

### `Haptics.notification(type: 'success' | 'warning' | 'error')`

Notification haptics provide feedback about the outcome of a task or action, such as depositing a check or unlocking a vehicle.

`type` argument maps to [`UINotificationFeedbackGenerator.FeedbackType`](https://developer.apple.com/documentation/uikit/uinotificationfeedbackgenerator/feedbacktype), see [HIG for visualization](https://developer.apple.com/design/human-interface-guidelines/playing-haptics#Notification).

### `Haptics.selection()`

Selection haptics provide feedback while the values of a UI element are changing, see [HIG for visualization](https://developer.apple.com/design/human-interface-guidelines/playing-haptics#Selection).

## License

MIT
