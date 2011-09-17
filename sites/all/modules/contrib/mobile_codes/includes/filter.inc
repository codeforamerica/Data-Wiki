<?php
/**
 * @file
 * Filter module integration.
 */

/**
 * Implements hook_filter_info().
 */
function mobile_codes_filter_info() {
  $filters = array();

  $filters['mobile_codes'] = array(
    'title' => t('Mobile Codes'),
    'process callback' => 'mobile_codes_filter_process',
    'tips callback'  => 'mobile_codes_filter_tips',
    'weight' => -10,
  );

  return $filters;
}

/**
 * Mobile Codes filter process callback.
 */
function mobile_codes_filter_process($text, $filter, $format, $langcode, $cache, $cache_id) {
  $attr = '';

  if (preg_match_all('/\[mobilecode([^]]*)\]([^[]*)\[\/mobilecode\]/', $text, $codes, PREG_SET_ORDER)) {
    foreach ($codes as $match) {
      $attr = array();
      if (preg_match_all('/(\S*?)=["\'](.*?)["\']/', $match[1], $attributes, PREG_SET_ORDER)) {
        foreach ($attributes as $attribute) {
          $attr[$attribute[1]] = $attribute[2];
        }
      }
      $text = str_replace($match[0], theme('mobilecode', array('data' => $match[2], 'attributes' => $attr)), $text);
    }
  }

  return $text;
}

/**
 * Mobile Codes filter tips callback.
 */
function mobile_codes_filter_tips($filter, $format, $long = FALSE) {
  return t('Create a Mobile Code using the following format') . ': [mobilecode #preset="<em>preset</em>"]<em>content</em>[/mobilecode]';
}
