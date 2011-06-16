<?php
// $Id: comment.page_title.inc,v 1.1.4.2 2010/08/25 14:33:30 njt1982 Exp $

/**
 * @file
 * Comment implementations of the page title hooks
 */


/**
 * Implementation of hook_page_title_alter().
 */
function comment_page_title_alter(&$title) {
  if (arg(0) == 'comment' && arg(1) == 'reply' && is_numeric(arg(2))) {
    // As this is a comment page, the node ID is in position 2, whereas a node page is position 1
    $node = menu_get_object('node', 2);

    // If the node has a custom page title and the node type is configured to have a custom page title (ie, it's not a leftover from a previous setting), then use it.
    if (!empty($node->page_title) && variable_get('page_title_type_'. $node->type .'_showfield', 0)) {
      $title = $node->page_title;
    }
    // otherwise set the page-title token to the parent node title. Makes more sense than "Reply to comment"...
    else {
      $title = $node->title;
    }
  }
}


/**
 * Implementation of hook_page_title_pattern_alter().
 */
function comment_page_title_pattern_alter(&$pattern, &$types) {
  // Comment reply page
  if (arg(0) == 'comment' && arg(1) == 'reply' && is_numeric(arg(2))) {
    // The node ID position is in arg 2...
    $types['node'] = menu_get_object('node', 2);

    // If the node has any taxonomy, grab the first time and pass it over to be passed as a token.
    // TODO: Handle multiple terms? Only pass specific terms per content type?
    if (!empty($types['node']->taxonomy)) {
      $types['taxonomy'] = current($types['node']->taxonomy);
    }

    // Is this a root comment or a child comment (top level or nested)...
    if (($pid = arg(3)) && $comment = _comment_load($pid)) {
      // Reply to comment...
      $types['comment'] = $comment;
      $pattern = variable_get('page_title_comment_child_reply', '');
    }
    else {
      // Reply to node...
      $pattern = variable_get('page_title_comment_reply', '');
    }
  }
}
