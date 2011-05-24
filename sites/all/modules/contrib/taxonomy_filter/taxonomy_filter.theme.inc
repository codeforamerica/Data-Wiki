<?php

/**
 * @file
 * Include file for Taxonomy Filter theming functions.
 */

/**
 * Render a breadcrumb style list of select and remove links to current search
 * criteria.
 *
 * @param array $terms taxonomy term objects associated with the current url.
 * @param array $block_info block information.
 * @return string $output html output.
 */
function theme_taxonomy_filter_block_current_content($variables) {
  $terms = $variables['terms'];
  $block_info = $variables['block_info'];
  $output = '<ul>';
  $links = array();
  foreach ($terms as $term) {
    $item = array();
    $item['tid'] = $term->tid;
    $item['title'] = check_plain($term->vocab_name . ' : ' . $term->name);
    $item['link_attributes']['title'] = $term->name;
    $item['item_attributes']['class'] = array('li-inline');
    $links[] = theme('taxonomy_filter_current_item', array('item' => $item, 'block_info' => $block_info));
  }
  $output .= implode('<li class="li-inline li-separator">›</li>', $links); // Use '›' instead of '>'.
  $output .= '</ul>';

  return $output;
}

/**
 * Process variables for taxonomy-filter-item.tpl.php.
 *
 * Process term ids in the order selected by user.
 * Display two links:
 *  1) All tids up to and including this tid (a "select" criteria link),
 *  2) All tids except this tid (a "remove" criteria link saved to post_link).
 */
function template_preprocess_taxonomy_filter_current_item(&$variables) {
  // Extract basic information.
  $link_tids = $variables['block_info']['url_tids'];
  $depth = $variables['block_info']['url_depth'];

  // Make code easier to read.
  $link = $variables['item']['link_attributes'];

  // Do the select criteria link.
  if (!isset($link['href'])) {
    $tids = _taxonomy_filter_tids_upto($link_tids, $variables['item']['tid']);
    $path = _taxonomy_filter_filter_link_path($tids, $depth);
    if ($path != '') {
      $link['href'] = $path;
    }
  }
  $name = $variables['item']['title'];
  $variables['link'] = theme('taxonomy_filter_link', array('name' => $name, 'attributes' => $link));

  // Add a remove criteria link (except on last tid).
  $tids = array_diff($link_tids, array($variables['item']['tid']));
  if (count($tids) > 0) {
    $name = 'remove';
    $path = _taxonomy_filter_filter_link_path($tids, $depth);
    $link['href'] = $path;
    if ($link['title']) {
      $link['title'] = 'Remove ' . $link['title'];
    }
    $link['super'] = true;
    $variables['post_link'] = theme('taxonomy_filter_link', array('name' => $name, 'attributes' => $link));
  }

  // Set list item attributes.
  if (isset($variables['item']['item_attributes']['class'])) {
    $variables['class'] = implode(' ', $variables['item']['item_attributes']['class']);
  }
  if (isset($variables['item']['item_attributes']['style'])) {
    $variables['style'] = implode('; ', $variables['item']['item_attributes']['style']);
  }
}

/**
 * Render links to allow the user to refine the current search criteria.
 *
 * @param array $sections vocabulary and term lists to refine the current url.
 * @param array $block_info block information.
 * @return string $output html output.
 */
function theme_taxonomy_filter_block_content($variables) {
  $sections = $variables['sections'];
  $block_info = $variables['block_info'];
  drupal_add_css(drupal_get_path('module', 'taxonomy_filter') . '/taxonomy_filter.css');
  $output = '';
  foreach ($sections as $section) {
    if ((/*isset($section['items']) &&*/ count($section['items']) >= 0) || isset($section['content'])) {
      $output .= theme('taxonomy_filter_section', array('section' => $section, 'block_info' => $block_info));
    }
  }
  return $output;
}

/**
 * Process variables for taxonomy-filter-section.tpl.php.
 */
function template_preprocess_taxonomy_filter_section(&$variables) {
  if ($variables['section']['info']['module'] == 'tf_context') {
    // Context menu has another level to the arrays for parents, children, related and toplevel.
    // All other menu templates are similar to the default "static" (as it is called in 5.x) list.
    return;
  }

  $items = $variables['section']['items'];
  $is_list = (count($items) > 0);
  $section_info = $variables['section']['info'];
  $block_info = $variables['block_info'];

  if (isset($variables['section']['content'])) {
    $variables['content'] = $variables['section']['content'];
  }
  else {
    $content = '';
    if ($is_list) {
      foreach ($items as $item) {
        $content .= theme('taxonomy_filter_item', array('item' => $item, 'section_info' => $section_info, 'block_info' => $block_info));
      }
    }
    $variables['content'] = $content;
  }
  $variables['title'] = $variables['section']['title'];
  $variables['is_list'] = $is_list;
  if (is_array($variables['section']['info']['class'])) {
    $variables['class'] = implode(' ', $variables['section']['info']['class']);
  }
}

/**
 * Process variables for taxonomy-filter-item.tpl.php.
 */
function template_preprocess_taxonomy_filter_item(&$variables) {
  $link_attributes = array();
  $link_tids = $variables['item']['info']['link_tids'];
  // Depth handling: use filter menu setting with default = url depth.
  $depth = isset($variables['section_info']['section_settings']['depth']) ? $variables['section_info']['section_settings']['depth'] : 0;
  $depth = !$depth && isset($variables['block_info']['url_depth']) ? $variables['block_info']['url_depth'] : $depth;
  if (isset($variables['item']['link_attributes']['href'])) {
    $link_attributes['href'] = $variables['item']['link_attributes']['href'];
  }
  else {
    $path = _taxonomy_filter_filter_link_path($link_tids, $depth);
    if ($path != '') {
      $link_attributes['href'] = $path;
    }
  }
  if (isset($variables['item']['link_attributes']['class'])) {
    $link_attributes['class'] = $variables['item']['link_attributes']['class'];
  }
  if (isset($variables['item']['link_attributes']['title'])) {
    $link_attributes['title'] = $variables['item']['link_attributes']['title'];
  }
  $name = $variables['item']['title'];
  $variables['link'] = theme('taxonomy_filter_link', array('name' => $name, 'attributes' => $link_attributes));
  if (isset($variables['item']['item_attributes']['class'])) {
    $variables['class'] = implode(' ', $variables['item']['item_attributes']['class']);
  }
}

/**
 * Render a taxonomy filter link.
 *
 * @param string $name link display text.
 * @param array $attributes html attributes.
 * @return string html output.
 */
function theme_taxonomy_filter_link($variables) {
  $name = $variables['name'];
  $attributes = $variables['attributes'];
  if ($name) {
    if (isset($attributes['class']) && is_array($attributes['class'])) {
      $attributes['class'] = implode(' ', $attributes['class']);
    }
    if (isset($attributes['href'])) {
      if (isset($attributes['super'])) {
        unset($attributes['super']);
        $output = '<a' . drupal_attributes($attributes) . '>' . $name . '</a>';
        $output = '&nbsp;<sup>[' . $output . ']</sup>&nbsp;';
      }
      else {
        $output = '<a' . drupal_attributes($attributes) . '>' . $name . '</a>';
      }
    }
    else {
      $output = '<span' . drupal_attributes($attributes) . '>' . $name . '</span>';
    }
    return $output;
  }
}

/**
 * Render a list of available taxonomy filter menu templates.
 *
 * @param array $form form elements.
 * @return string html output.
 */
function theme_taxonomy_filter_templates_table($variables) {
  $form = $variables['form'];
  $css_path = drupal_get_path('module', 'taxonomy_filter') . '/taxonomy-filter-admin.css';
  drupal_add_css($css_path, array('preprocess' => FALSE));

  $rows = array();
  foreach (element_children($form) as $key) {
    $template = &$form[$key];
    $row = array();
    $row[] = $template['name']['#value']; // $row[] = drupal_render($template['name']);
    $row[] = $template['desc']['#value']; // $row[] = drupal_render($template['desc']);
    $row[] = $template['module']['#value']; // $row[] = drupal_render_children($template['module']);
    $row[] = array('data' => $template['status']['#value'], 'class' => array('status')); // $row[] = array('data' => $template['status']['#value'], 'class' => 'status');
    $rows[] = array('data' => $row, 'class' => array($template['status']['#class'])); // $rows[] = array('data' => $row, 'class' => $template['status']['#class']);
  }
  $header = array(t('Name'), t('Description'), t('Module'), t('Status'));

  $output = theme('table', array('header' => $header, 'rows' => $rows));

  return $output;
}

/**
 * Render a list of configured taxonomy filter menus.
 *
 * @param array $form form elements.
 * @return string html output.
 */
function theme_taxonomy_filter_menus_table($variables) {
  $form = $variables['form'];
//   $css_path = drupal_get_path('module', 'taxonomy_filter') . '/taxonomy-filter-admin.css';
//   drupal_add_css($css_path, array('preprocess' => FALSE));

  $rows = array();
  foreach (element_children($form) as $key) {
    $menu = &$form[$key];
    $row = array();
    $row[] = $menu['name']['#value']; // $row[] = drupal_render($menu['name']);
    $row[] = $menu['template']['#value']; // $row[] = drupal_render($menu['template']);
    $row[] = $menu['edit']['#value']; // $row[] = drupal_render($menu['edit']);
    $row[] = $menu['delete']['#value']; // $row[] = drupal_render($menu['delete']);
    $row[] = $menu['vocabs']['#value']; // $row[] = drupal_render_children($menu['vocabs']);
    $rows[] = array('data' => $row, 'class' => array($menu['status']['#class'])); // $rows[] = array('data' => $row, 'class' => $menu['status']['#class']);
  }

  $header = array(t('Name'), t('Template'), array('data' => t('Operations'), 'colspan' => 2), t('Vocabs used on')); //, t('Module status'));

  $output = theme('table', array('header' => $header, 'rows' => $rows));

  return $output;
}

/**
 * Render an editable list of taxonomy filter menu to vocabulary mappings.
 *
 * @param array $form form elements.
 * @return string html output.
 */
function theme_taxonomy_filter_mappings_table($variables) {
  $form = $variables['form'];
  $mappings = variable_get('taxonomy_filter_mappings', array()); // TODO Duplicates call in form builder.
  $vids = array_keys($mappings);

  $rows = array();

  $header1 = '<tr>';
  $header1 .= _theme_table_cell(t('The filter menu for:'), true);
  $header1 .= _theme_table_cell(
    array(
      'data' => t('uses:'),
      'colspan' => 2,
    ), true);
  $header1 .= _theme_table_cell(
    array(
      'data' => t('and appears on term listings from:'),
    ), true);
  $header1 .= '</tr>';

  $header = array('Vocabulary', 'Refine Criteria', ' Current Criteria', 'Vocabularies', 'Operations');
  foreach ($vids as $row_vid) {
    $vocab = &$form['vocab' . $row_vid]; // TODO Are the '&' references needed???
    $vocab_name = drupal_render($vocab);

    $row = array();
    $row[] = $vocab['#value']; // $row[] = $vocab_name;

    $menu = &$form['refine_menu' . $row_vid]; // TODO Are the '&' references needed???
    $row[] = drupal_render($menu);

    $menu = &$form['current_menu' . $row_vid]; // TODO Are the '&' references needed???
    $row[] = drupal_render($menu);

    $menu = $form['vocabs' . $row_vid];
    $row[] = $menu['#value']; // $row[] = drupal_render($menu);

    $menu = $form['edit' . $row_vid];
    $row[] = $menu['#value']; // $row[] = drupal_render($menu); // $row[] = drupal_render_children($menu);

    $rows[] = array('data' => $row);
  }

  $table_output = theme('table', array('header' => $header, 'rows' => $rows));
  $table_output = str_replace("<thead>", "<thead>$header1\n", $table_output);

  return $table_output;
}
