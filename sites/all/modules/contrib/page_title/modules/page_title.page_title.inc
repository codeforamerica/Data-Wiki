<?php
// $Id: page_title.page_title.inc,v 1.1.4.3 2010/11/01 23:18:35 njt1982 Exp $

/**
 * @file
 * Page Title implementations of the page title hooks
 */


/**
 * Implementation of hook_page_title_alter().
 */
function page_title_page_title_alter(&$title) {
 // If nothing above set a title, give the legacy function a chance to act
  if (empty($title)) {
    $title = page_title_set_title();
  }

  // If we still have no title, fall back to the title provided by Drupal Core
  if (empty($title)) {
    $title = drupal_get_title();
  }
}


/**
 * Implementation of hook_page_title_pattern_alter().
 */
function page_title_page_title_pattern_alter(&$pattern, &$types) {
  // If frontpage, then use the frontpage pattern and set the title.
  if (drupal_is_front_page()) {
    // Get the frontpage pattern
    $pattern = variable_get('page_title_front', '[site-name] | [site-slogan]');
  }
}
