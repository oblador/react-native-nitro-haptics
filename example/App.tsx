/**
 * Sample React Native App
 * https://github.com/facebook/react-native
 *
 * @format
 */

import React from 'react';
import {
  Button,
  SafeAreaView,
  ScrollView,
  StatusBar,
  useColorScheme,
  View,
} from 'react-native';

import { Colors, Header } from 'react-native/Libraries/NewAppScreen';
import { Haptics } from 'react-native-nitro-haptics';

function App(): React.JSX.Element {
  const isDarkMode = useColorScheme() === 'dark';

  const backgroundStyle = {
    backgroundColor: isDarkMode ? Colors.darker : Colors.lighter,
  };

  return (
    <SafeAreaView style={backgroundStyle}>
      <StatusBar
        barStyle={isDarkMode ? 'light-content' : 'dark-content'}
        backgroundColor={backgroundStyle.backgroundColor}
      />
      <ScrollView
        contentInsetAdjustmentBehavior="automatic"
        style={backgroundStyle}
      >
        <Header />
        <View
          style={{
            backgroundColor: isDarkMode ? Colors.black : Colors.white,
          }}
        >
          <Button title="Impact" onPress={() => Haptics.impact('medium')} />
          <Button
            title="Notification"
            onPress={() => Haptics.notification('warning')}
          />
          <Button title="Selection" onPress={() => Haptics.selection()} />
          <Button
            title="Impact With Intensity"
            onPress={() => Haptics.impactWithIntensity('light', 0.5)}
          />
        </View>
      </ScrollView>
    </SafeAreaView>
  );
}

export default App;
