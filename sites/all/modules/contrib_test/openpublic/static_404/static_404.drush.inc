<?php

// $Id$

/**
 * @file
 * Drush functionality for static_404 module
 */

/**
 * hook drush command, provide callback for 404 page generation
 */
function static_404_drush_command() {
  $items = array();
  $items['static_404_generate'] = array(
    'description' => 'Regenerates the static 404 page',
    'callback' => 'drush_static_404_generate',
  );
  return $items;
}

function drush_static_404_generate() {
  static_404_generate();
}
