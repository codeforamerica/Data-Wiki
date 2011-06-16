<?php
// $Id: taxonomy.page_title.inc,v 1.1.4.3 2010/11/01 21:25:11 njt1982 Exp $

/**
 * @file
 * Taxonomy implementations of the page title hooks
 */


/**
 * Implementation of hook_page_title_alter().
 */
function taxonomy_page_title_alter(&$title) {
  // If we're looking at a taxonomy term page, get the term title
  if (arg(0) == 'taxonomy' && arg(1) == 'term' && is_numeric(arg(2))) {
    $term = taxonomy_term_load(arg(2));
    if (variable_get('page_title_vocab_'. $term->vid .'_showfield', 0) && ($term_title = page_title_load_title($term->tid, 'term'))) {
      $title = $term_title;
    }
  }
}


/**
 * Implementation of hook_page_title_pattern_alter().
 */
function taxonomy_page_title_pattern_alter(&$pattern, &$types) {
  // Taxonomy Term Page
  if (arg(0) == 'taxonomy' && arg(1) == 'term' && is_numeric(arg(2)) && module_exists('taxonomy')) {
    $types['taxonomy'] = taxonomy_term_load(arg(2));
    $pattern = variable_get('page_title_vocab_'. $types['taxonomy']->vid, '');
  }
}
