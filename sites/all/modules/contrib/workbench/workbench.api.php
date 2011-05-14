<?php

/**
 * @file
 * API documentation file for Workbench.
 */

/**
 * Allows modules to alter the default Workbench landing page.
 *
 * This hook is a convenience function to be used instead of
 * hook_page_alter(). In addition to the normal Render API elements,
 * you may also specify a #view and #view_display attribute, both
 * of which are strings that indicate which View to render on the page.
 *
 * @param $output
 *  A Render API array of content items, passed by reference.
 *
 * @see workbench_content()
 */
function hook_workbench_content_alter(&$output) {
  // Replace the default "Recent Content" view with our custom View.
  $output['workbench_recent_content']['#view'] = 'custom_view';
  $output['workbench_recent_content']['#view_display'] = 'block_2';
}

/**
 * Allows modules to alter the default content creation page.
 *
 * Worekbench supplies a Create Content tab which emulates core's
 * node/add page. The render array for this page may be modified
 * by other modules.
 *
 * @param $output
 *  A Render API array of content items, passed by reference.
 *
 * @see workbench_create()
 */
function hook_workbench_create_alter(&$output) {
  // Example taken from Workbench Media module.
  if (user_access('use workbench_media add form')) {
    // Mimic node_add_page() theming.
    $items = array(
      array(
        'title' => t('Upload Media'),
        'href' => 'admin/workbench/media/add',
        'localized_options' => array(),
        'description' => t('Add photos, videos, audio, or other files to the site.'),
      )
    );
    $output['field_workbench_create_media'] = array(
      '#title' => t('Create Media'),
      '#markup' => theme('node_add_list', array('content' => $items)),
      '#theme' => 'workbench_element',
      '#weight' => -1,
    );
  }
}
