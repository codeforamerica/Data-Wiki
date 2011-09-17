<?php
/**
 * @file
 * Shorten module integration.
 */

/**
 * Implements hook_mobile_codes_settings_alter() on behalf of shorten.module.
 */
function shorten_mobile_codes_settings_alter(&$settings) {
  $settings['url']['shorten'] = array(
    'label' => t('Shorten URL'),
    'description' => t('Create a short URL with the Shorten module - !configure', array('!configure' => l(t('configure'), 'admin/config/shorten'))),
    'weight' => 10,
  );
}

/**
 * Implements mobile_codes_data_TYPE_SETTING().
 */
function mobile_codes_data_url_shorten(&$data) {
  $data = shorten_url($data);
}
