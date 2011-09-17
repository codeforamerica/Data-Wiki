<?php
/**
 * @file
 * Image module integration.
 */

/**
 * Implements hook_mobile_codes_field_formatter_info() on behalf of image.module.
 */
function image_mobile_codes_field_formatter_info() {
  return array(
    'image' => array(
      'callback' => 'image_mobile_codes_field_formatter_data'
    ),
  );
}

/**
 * Callback for Image module Mobile Codes formatter.
 */
function image_mobile_codes_field_formatter_data($item) {
  return file_create_url($item['uri']);
}
