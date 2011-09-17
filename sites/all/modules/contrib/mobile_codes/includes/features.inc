<?php
/**
 * @file
 * Features module integration.
 */

/**
 * Implements hook_features_api().
 */
function mobile_codes_features_api() {
  $features = array();

  $features['mobile_codes_presets'] = array(
    'name' => 'Mobile Codes: Presets',
    'api' => 'default_mobile_codes_presets',
    'default_hook' => 'default_mobile_codes_preset',
    'default_file' => FEATURES_DEFAULTS_CUSTOM,
    'default_filename' => 'default_mobile_codes_presets',
    'current_version' => 2,
    'module' => 'mobile_codes',
    'feature_source' => TRUE,
  );

  $features['mobile_codes_providers'] = array(
    'name' => 'Mobile Codes: Providers',
    'api' => 'default_mobile_codes_providers',
    'default_hook' => 'default_mobile_codes_provider',
    'default_file' => FEATURES_DEFAULTS_CUSTOM,
    'default_filename' => 'default_mobile_codes_providers',
    'current_version' => 2,
    'module' => 'mobile_codes',
    'feature_source' => TRUE,
  );

  return $features;
}
