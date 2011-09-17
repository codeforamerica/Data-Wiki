<?php
/**
 * @file
 * Link module integration.
 */

/**
 * Implements hook_mobile_codes_field_formatter_info() on behalf of link.module.
 */
function link_mobile_codes_field_formatter_info() {
  return array(
    'link_field' => array(
      'callback' => 'link_mobile_codes_field_formatter_data'
    ),
  );
}

/**
 * Callback for Link module Mobile Codes formatter.
 */
function link_mobile_codes_field_formatter_data($item) {
  return $item['display_url'];
}
