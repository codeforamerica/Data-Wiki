<?php
/**
 * @file
 * File module integration.
 */

/**
 * Implements hook_mobile_codes_field_formatter_info() on behalf of file.module.
 */
function file_mobile_codes_field_formatter_info() {
  return array(
    'file' => array(
      'callback' => 'file_mobile_codes_field_formatter_data'
    ),
  );
}

/**
 * Callback for File module Mobile Codes formatter.
 */
function file_mobile_codes_field_formatter_data($item) {
  return file_create_url($item['uri']);
}
