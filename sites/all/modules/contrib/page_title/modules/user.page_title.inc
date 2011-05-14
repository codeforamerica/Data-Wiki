<?php
// $Id: user.page_title.inc,v 1.1.4.2 2010/08/25 14:33:30 njt1982 Exp $

/**
 * @file
 * User implementations of the page title hooks
 */


/**
 * Implementation of hook_page_title_alter().
 */
function user_page_title_alter(&$title) {
  // If we're looking at either a user profile page or a users blog page, get the user title
  if ((arg(0) == 'user' || arg(0) == 'blog') && is_numeric(arg(1))) {
    if (variable_get('page_title_user_showfield', 0) && ($user_title = page_title_load_title(arg(1), 'user'))) {
      $title = $user_title;
    }
  }
}


/**
 * Implementation of hook_page_title_pattern_alter().
 */
function user_page_title_pattern_alter(&$pattern, &$types) {
  // User
  if (arg(0) == 'user' && is_numeric(arg(1))) {
    $types['user'] = user_load(array('uid' => arg(1)));
    $pattern = variable_get('page_title_user', '');
  }
  // Blog
  elseif (arg(0) == 'blog' && is_numeric(arg(1))) {
    $types['user'] = user_load(array('uid' => arg(1)));
    $pattern = variable_get('page_title_blog', '');
  }
}
