/**
 * Sample React Native App
 * https://github.com/facebook/react-native
 *
 * @format
 */

import React from 'react';
import { Button, Platform, ScrollView } from 'react-native';

import { Haptics } from 'react-native-nitro-haptics';

function App(): React.JSX.Element {
  return (
    <ScrollView contentInsetAdjustmentBehavior="automatic">
      <Button title="Impact" onPress={() => Haptics.impact('medium')} />
      <Button
        title="Notification"
        onPress={() => Haptics.notification('warning')}
      />
      <Button title="Selection" onPress={() => Haptics.selection()} />
      {Platform.OS === 'android' && (
        <Button
          title="Android Haptics"
          onPress={() => Haptics.performAndroidHaptics('confirm')}
        />
      )}
    </ScrollView>
  );
}

export default App;
