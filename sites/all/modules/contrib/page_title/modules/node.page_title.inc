<?php
// $Id: node.page_title.inc,v 1.1.4.2 2010/08/25 14:33:30 njt1982 Exp $

/**
 * @file
 * Node implementations of the page title hooks
 */


/**
 * Implementation of hook_page_title_alter().
 */
function node_page_title_alter(&$title) {
  if (arg(0) == 'node' && is_numeric(arg(1))) {
    // Get the node
    $node = menu_get_object('node');

    // If the node has a custom page title and the node type is configured to have a custom page title (ie, it's not a leftover from a previous setting), then use it.
    if (!empty($node->page_title) && variable_get('page_title_type_'. $node->type .'_showfield', 0)) {
      $title = $node->page_title;
    }
  }
}


/**
 * Implementation of hook_page_title_pattern_alter().
 */
function node_page_title_pattern_alter(&$pattern, &$types) {
  if ((arg(0) == 'node' && is_numeric(arg(1)))) {
    $types['node'] = menu_get_object();

    // If the node has any taxonomy, grab the first time and pass it over to be passed as a token.
    // TODO: Handle multiple terms? Only pass specific terms per content type?
    if (!empty($types['node']->taxonomy)) {
      $types['taxonomy'] = current($types['node']->taxonomy);
    }

    $pattern = variable_get('page_title_type_'. $types['node']->type, '');
  }
}
