<?php

/**
 * @file
 * A built-in basic template module for the Taxonomy Filter module.
 *
 * This is an include rather than a separate module so it can't be
 * disabled separately from the core module.
 */

/**
 * Implements hook_tf_template_info().
 */
function taxonomy_filter_tf_template_info() {
  return array(
    'name' => 'base',
    'desc' => 'The built in basic menu template that is always available.',
  );
}

/**
 * Implements hook_tf_item_alter().
 */
function taxonomy_filter_tf_item_alter(&$item, $details, $context = NULL) { // function taxonomy_filter_tf_item_alter(&$item, $section_info, $block_info, $context = NULL) {
  $section_info = $details['section_info'];
  $block_info = $details['block_info'];
  if ($context != 'base terms') {
    if (in_array($item['info']['item_tid'], $block_info['url_tids'])) {
      $item['link_attributes']['class'][] = 'selected';
    }
  }
}

/**
 * Implements hook_tf_link_tids_alter().
 */
function taxonomy_filter_tf_link_tids_alter(&$link_tids, $item_tid, $context) {
  if ($context == 'base terms') {
    $link_tids = array($item_tid);
  }
}

/**
 * Implements hook_tf_block_alter().
 */
function taxonomy_filter_tf_block_alter(&$block) {
  return; // TODO Re-enable this code?
  // Note: count results don't turn up here yet because there is no default count
  // settings for nontemplate blocks
  $tids = $block['info']['url_tids'];
  $section_info = array('link_depth' => 'all'); // TODO - count results aren't added because there are no default section settings.
  if (count($tids) > 1) {
    // Only add the base terms section to listings of more than one term
    $terms = array();
    foreach ($tids as $tid) {
      $terms[] = taxonomy_term_load($tid);
    }
    $items = taxonomy_filter_section_items($terms, $section_info, $block['info'], 'base terms');
    $new_section = array(
      'title' => t('Only topics tagged with:'),
      'items' => $items,
    );
    drupal_alter('tf_section', $new_section, $block['info']);
    $block['sections']['base_terms'] = $new_section;
  }
}
