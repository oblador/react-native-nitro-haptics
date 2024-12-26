const path = require('path');
const { getDefaultConfig, mergeConfig } = require('@react-native/metro-config');
const pkg = require('../package.json');

const root = path.resolve(__dirname, '..');

/**
 * Metro configuration
 * https://reactnative.dev/docs/metro
 *
 * @type {import('metro-config').MetroConfig}
 */
const config = {
  watchFolders: [root],
  resolver: {
    extraNodeModules: {
      [pkg.name]: root,
    },
  },
};

module.exports = mergeConfig(getDefaultConfig(__dirname), config);
