<?php
// $Id: forum.page_title.inc,v 1.1.4.3 2010/11/01 23:18:35 njt1982 Exp $

/**
 * @file
 * Forum implementations of the page title hooks
 */


/**
 * Implementation of hook_page_title_alter().
 */
function forum_page_title_alter(&$title) {
  // Check we're on a forum page and if there is a number to confirm it's a container or forum (rather than root)
  if (arg(0) == 'forum' && is_numeric(arg(1))) {
    $term = taxonomy_term_load(arg(1));
    if (variable_get('page_title_vocab_'. $term->vid .'_showfield', 0) && ($term_title = page_title_load_title($term->tid, 'term'))) {
      $title = $term_title;
    }
  }
}


/**
 * Implementation of hook_page_title_pattern_alter().
 */
function forum_page_title_pattern_alter(&$pattern, &$types) {
  // Forums Page title Patterns
  if (arg(0) == 'forum') {
    // If there is a numeric argument, then we're viewing a container or forum
    if (is_numeric(arg(1))) {
      $types['term'] = taxonomy_term_load(arg(1));
      $forum_vid = variable_get('forum_nav_vocabulary', '');
      $pattern = variable_get('page_title_vocab_'. $forum_vid, '');
    }
    // Otherwise its the root - lets grab the root pattern.
    else {
      $pattern = variable_get('page_title_forum_root_title', '');
    }
  }
}
