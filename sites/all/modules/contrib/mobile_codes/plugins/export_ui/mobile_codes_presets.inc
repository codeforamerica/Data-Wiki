<?php
/**
 * @file
 */

$plugin = array(
  'schema' => 'mobile_codes_presets',
  'access' => 'administer mobile codes',
  'menu' => array(
    'menu prefix' => 'admin/config/content/mobile_codes',
    'menu item' => 'presets',
    'menu title' => 'Presets',
    'menu description' => 'Administer Mobile Codes presets.',
  ),
  'title singular' => t('preset'),
  'title singular proper' => t('Preset'),
  'title plural' => t('presets'),
  'title plural proper' => t('Presets'),
  'form' => array(
    'settings' => 'mobile_codes_presets_export_ui_form',
    'submit' => 'mobile_codes_presets_export_ui_form_submit',
  ),
);
