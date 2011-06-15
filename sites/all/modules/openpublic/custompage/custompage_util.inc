<?php

/**
 * Render a custompage tile for a view.
 *
 * @param $name
 *      The Name of the view to render.
 * @param $title
 *      The title of the tile block, if blank it will use the view title, if you
 *      want it explicitly omitted, pass FALSE.
 * @param $display_id
 *      The view display id.  Blocks are numbered block_<em>N</em> and pages are numbered page_<em>N</em>.
 */
function custompage_view_tile( $name, $title = '', $display_id = 'block_1') {

  $args = func_get_args();
  array_shift($args); // remove $name
  if (count($args)) {
    array_shift($args); // remove $title
  }
  if (count($args)) {
    array_shift($args); // remove $display_id
  }

  $view = views_get_view($name);

  if (empty($view)) {
    return;
  }

  //Use View's title unless something else explicitely indicated or
  //$title === False, which means caller does not want title rendered
  if ( $title !== FALSE ) {
    if (empty($title)) {
      $display_title = $view->display[$display_id]->display_options['title'];
      $title = $display_title;
      if (empty($display_title)) { // if title was not set, use default one.
        $title = $view->display['default']->display_options['title'];
        if (empty($title)) { // If title is not set anywhere, use display name
          $title = $view->display[$display_id]->display_title;
        }
      }
    }
  }

  if (!isset($view->override_path)) {
    $view->override_path = $_GET['q'];
  }
  $content =  $view->preview($display_id, $args);

  if ( !empty($title) ) {
    $content = "<div><h2>$title</h2>$content</div>";
  }

  $editlink = custompage_edit_link('admin/build/views/edit/' . $name);
  $tile = custompage_tile_wrap( $content, $editlink );

  return $tile;
}


/**
 * @param $key
 *   can be $nid of a node or a $title. If $key is not numer, it is assumed
 *   to be a title and $type parameter is required. If several nodes with the
 *   same title exist, only the first one will be returned.
 * @param $type
 *   node type
 */
function custompage_node_tile( $key, $type = '', $teaser_only = FALSE, $show_title = TRUE ) {
  global $language;

  $langcode = $language->language; //ISO2 code
  $default = language_default();
  $default_langcode = $default->language;

  if ( is_numeric($key) ) {
    $node = node_load( array('nid' => $key) );
  }
  else if ( is_string($key) && !empty($type) && is_string($type) ) {
    $node = node_load( array('title' => $key, 'type' => $type, 'language' => $default_langcode) );
  }

  if ( !is_object($node) ) {
    return '&nbsp;'; //We should never return empty string since that makes entire page blank
    //due to some weird bug/behaviour in Drupal. Ugh
  }

  $sql = 'SELECT n.nid FROM {node} n WHERE n.tnid = %d and n.language = \'%s\' ';
  $i18n_nid = db_result(db_query(db_rewrite_sql($sql), $node->nid, $langcode)); //defaults should be in default language

  if ( is_numeric($i18n_nid) && ($i18n_nid > 0)  ) {
    $node = node_load( $i18n_nid );
  } //Serve Default language version (English usually) by default!

  if (!$show_title) {
    unset($node->title);
  }
  $content = node_view($node, $teaser_only, TRUE);
  $editlink = custompage_edit_link('node/' . $node->nid . '/edit/');
  $tile = custompage_tile_wrap( $content, $editlink );

  return $tile;
}

/**
 * Put a regions content in a custompage tile.
 *
 * @param $region
 *    The region key
 */
function custompage_region_tile($region) {
  $tile = theme('blocks', $region);

  if (empty($tile)) {
    return '';
  } //Fixing: http://drupal.org/node/358442

  $editlink = custompage_edit_link('admin/build/block/list', FALSE);
  $tile = custompage_tile_wrap($tile, $editlink);
  return $tile;
}

/**
 * @param $menu_name
 *   The system name of the menu as recorded in the {menu_custom} table.
 */
function custompage_menu_tile( $menu_name ) {

  $out = "<ul class=\"menu-$menu_name\">";
  $menu = menu_navigation_links( $menu_name );
  foreach ( $menu as $item ) {
    $item = _custompage_translate_path($item);
    $out .= "<li>" . theme_menu_item_link( $item ) . "</li>";
  }

  $out .= "</ul>";

  $editlink = custompage_edit_link('admin/build/menu-customize/' . $menu_name);
  $tile = custompage_tile_wrap( $out, $editlink );

  return $tile;
}

/**
 * Generate an Edit link for inline editing.
 *
 * @param $url
 *    The url to link out to. This is the edit url for the resource you are displaying
 * @param $return
 *    Do you want to include the standard 'destination' query string param to return to after edit.
 */
function custompage_edit_link($url, $return = TRUE) {
  if ($return) {
    $dest = substr($_SERVER['REQUEST_URI'], 1); //chop-out the leading "/"
    if (strpos('?', $url) === FALSE) {
      $url .= '?';
    }
    $url .= "destination=$dest";
  }
  $editlink = l(t('Edit'), $url);
  $editlink = urldecode($editlink); //urldecode destination argument
  return $editlink;
}

/**
 * Wrap custompage tiles in some HTML that allows for easy inline editing.
 */
function custompage_tile_wrap( $content, $editlink ) {

  if (empty($content)) {
    return '';
  } // Don't do anything if empty

  $out = $content;
  $extraclass = '';
  if ( user_access('edit custompage tiles') && variable_get('custompage_inline_edit', FALSE)) {
    $out = '<div class="edit">' . $editlink . '</div>' . $out;
    $extraclass = 'cp_showborder';
  }

  return '<div class="cp_tile ' . $extraclass . '">' . $out . '</div>';
}

/**
 * The idea for this function comes from the original work by Jonathan Hedstrom:
 *
 * @see http://www.opensourcery.com/blog/jonathan-hedstrom/drupal-6-and-primarysecondary-menu-translation
 */
function _custompage_translate_path($link) {
  global $language;

  if ($language && module_exists('translation')) {
    // get a list of all available paths
    $new_paths = translation_path_get_translations($link['href']);
    if ($new_paths[$language->language]) {
      // if a translated path exists, set it here
      $link['href'] = $new_paths[$language->language];
    }

    // translate the title (this adds every menu title to the locale_source
    // table, for later translation
    $link['title'] = t($link['title']);
    if ($link['attributes']['title']) {
      $link['attributes']['title'] = t($link['attributes']['title']);
    }
  }

  return $link;
}

