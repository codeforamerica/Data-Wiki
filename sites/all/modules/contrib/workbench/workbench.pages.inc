<?php

/**
 * @file
 * Workbench page callbacks.
 */

/**
 * Page callback for the workbench content page.
 *
 * Note that we add Views information to the array and render
 * the Views as part of the alter hook provided here.
 *
 * @see hook_workbench_content_alter()
 * 
 * @return
 *  A Render API array of content creation options.
 */
function workbench_content() {
  $output = array();

  // Allow other modules to add content here.
  $output['#attributes'] = array('class' => array('admin'));
  $output['#theme'] = 'workbench_element';
  $output['workbench_current_user'] = array(
    '#title' => t('My Profile'),
    '#view' => 'workbench_current_user',
    '#attributes' => array('class' => array('left', 'clearfix')),
    '#theme' => 'workbench_element',
  );
  $output['workbench_edited'] = array(
    '#title' => t('Content I\'ve Edited'),
    '#view' => 'workbench_edited',
    '#view_display' => 'block_1',
    '#attributes' => array('class' => array('right', 'clearfix')),
    '#theme' => 'workbench_element',
  );
  $output['workbench_recent_content'] = array(
    '#title' => t('All Recent Content'),
    '#view' => 'workbench_recent_content',
    '#view_display' => 'block_1',
    '#attributes' => array('class' => array('clearfix'), 'style' => array('clear: both;')),
    '#theme' => 'workbench_element',
  );

  // Allow other modules to alter the default page.
  drupal_alter('workbench_content', $output);

  // Transform the Views into markup.
  foreach (element_children($output) as $key) {
    $value = $output[$key];
    if (isset($value['#view'])) {
      $markup = '';
      if (isset($output[$key]['#markup'])) {
        $markup = $output[$key]['#markup'];
      }
      $view = $value['#view'];
      $display = isset($value['#view_display']) ? $value['#view_display'] : 'default';
      // TODO: pass arguments to the View.
      $output[$key]['#markup'] = $markup . views_embed_view($view, $display);
    }
  }

  return $output;
}

/**
 * Simple page to show list of content type to create.
 *
 * @see hook_workbench_create_alter()
 *
 * @return
 *  A Render API array of content creation options.
 */
function workbench_create() {
  $output = array();
  $output['workbench_create_default'] = _workbench_create();

  // Allow other modules to add content here.
  drupal_alter('workbench_create', $output);

  return $output;
}

/**
 * Emulate node/add to return content creation list.
 *
 * @return
 *  A Render API array of content creation options.
 */
function _workbench_create() {
  $output = array();
  $output['#markup'] = '<h3>' . t('Create content') . '</h3>';

  $item = menu_get_item('node/add');
  $content = system_admin_menu_block($item);

  if (!empty($content)) {
    // Theme the arrray of content type creation links.
    $output['#markup'] .= theme('node_add_list', array('content' => $content));
  }
  else {
    $output['#markup'] .= t('You cannot create any new content. Please contact the site administrator.');
  }

  return $output;
}
