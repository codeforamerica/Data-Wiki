<?php
/**
 * @file
 * System module integration.
 */

/**
 * Implements hook_menu().
 */
function mobile_codes_menu() {
  $items = array();
  drupal_alter('mobile_codes_menu', $items);
  return $items;
}

/**
 * Implements hook_theme().
 */
function mobile_codes_theme() {
  $items = array();
  drupal_alter('mobile_codes_theme', $items);
  return $items;
}
