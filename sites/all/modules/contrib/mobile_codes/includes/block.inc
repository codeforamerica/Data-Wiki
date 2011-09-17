<?php
/**
 * @file
 * Block module integration.
 */

/**
 * Implements hook_mobile_codes_default_mobile_codes_preset_alter() on behalf of block.module.
 */
function block_mobile_codes_default_mobile_codes_preset_alter(&$export) {
  $preset = new stdClass;
  $preset->disabled = FALSE; /* Edit this to true to make a default preset disabled initially */
  $preset->api_version = 2;
  $preset->name = 'block_node_url';
  $preset->provider = 'google';
  $preset->defaults = array(
    'width' => '180',
    'height' => '180',
    'output_encoding' => 'UTF-8',
  );

  $export['block_node_url'] = $preset;
}

/**
 * Implements hook_block_info().
 */
function mobile_codes_block_info() {
  $blocks = array();
  drupal_alter('mobile_codes_block_info', $blocks);
  return $blocks;
}

/**
 * Implements hook_mobile_codes_block_info_alter() on behalf of block.module.
 */
function block_mobile_codes_block_info_alter(&$blocks) {
  $blocks['node_url'] = array(
    'info' => t('Node URL'),
  );

  $blocks['generate_code'] = array(
    'info' => t('Mobile Code generator'),
  );
}

/**
 * Implements hook_block_configure().
 */
function mobile_codes_block_configure($delta) {
  if (function_exists($function = "mobile_codes_block_{$delta}_configure")) {
    return $function();
  }
  return array();
}

/**
 * Implements hook_block_save().
 */
function mobile_codes_block_save($delta = 0, $edit = array()) {
  if (function_exists($function = "mobile_codes_block_{$delta}_save")) {
    $function($edit);
  }
}

/**
 * Implements hook_block_view().
 */
function mobile_codes_block_view($delta) {
  if (function_exists($function = "mobile_codes_block_{$delta}_view")) {
    return $function();
  }
  return array();
}

/**
 * Node URL block configuration form.
 */
function mobile_codes_block_node_url_configure() {
  $form = array();

  $form['preset'] = array(
    '#type' => 'select',
    '#title' => t('Mobile Codes preset'),
    '#options' => array(),
    '#default_value' => variable_get('mobile_codes_block_node_url_preset', 'block_node_url'),
  );

  foreach (mobile_codes_presets_load_all() as $preset) {
    $form['preset']['#options'][$preset->name] = $preset->name;
  }

  return $form;
}

/**
 * Node URL block save callback.
 */
function mobile_codes_block_node_url_save($edit) {
  variable_set('mobile_codes_block_node_url_preset', $edit['preset']);
}

/**
 * Node URL block view callback.
 */
function mobile_codes_block_node_url_view() {
  if (arg(0) == 'node' && arg(1) != '' && arg(2) == '') {
    return array(
      'subject' => t('Node URL'),
      'content' => theme('mobilecode', array('data' => url('node/' . arg(1), array('absolute' => TRUE, 'alias' => TRUE)), 'attributes' => array('#preset' => variable_get('mobile_codes_block_node_url_preset', 'block_node_url'))))
    );
  }
}
