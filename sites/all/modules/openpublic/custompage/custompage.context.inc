<?php

/**
 * Implementation of hook_context_conditions().
 */
function custompage_context_conditions() {
  $items = array();

  $items['custompage'] = array(
    '#title' => t('CustomPage'),
    '#description' => t('Set this context when displaying one of following customapges.'),
    '#options' => _custompage_context_get_custompages(),
    '#type' => 'checkboxes',
  );

  return $items;
}

function _custompage_context_get_custompages() {
  static $custom_pages;

  if ( is_array( $custom_pages ) ) { //performance optimization
    return $custom_pages;
  }

  $custom_pages = array();
  $mappings = _custompage_get_mappings();

  foreach ($mappings as $mapping) {
    $custom_pages[$mapping->key] = $mapping->title;
  }

  ksort($custom_pages);

  return $custom_pages;
}
