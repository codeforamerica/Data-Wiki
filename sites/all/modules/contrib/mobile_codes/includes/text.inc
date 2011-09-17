<?php
/**
 * @file
 * Text module integration.
 */

/**
 * Implements hook_mobile_codes_field_formatter_info() on behalf of text.module.
 */
function text_mobile_codes_field_formatter_info() {
  return array(
    'text' => array(
      'callback' => 'text_mobile_codes_field_formatter_data'
    ),
  );
}

/**
 * Callback for Text module Mobile Codes formatter.
 */
function text_mobile_codes_field_formatter_data($item) {
  return $item['safe_value'];
}
