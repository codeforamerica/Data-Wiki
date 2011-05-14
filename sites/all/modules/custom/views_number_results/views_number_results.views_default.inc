<?php

/**
 * Implementation of hook_views_default_views().
 */
function views_number_results_views_default_views() {
  
  $view = new view;
  $view->name = 'number_results';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Number Results';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  
  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Number Results';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Global: Total Number Results */
  $handler->display->display_options['fields']['views_number_results']['id'] = 'views_number_results';
  $handler->display->display_options['fields']['views_number_results']['table'] = 'views';
  $handler->display->display_options['fields']['views_number_results']['field'] = 'views_number_results';
  $handler->display->display_options['fields']['views_number_results']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['views_number_results']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['views_number_results']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['views_number_results']['alter']['external'] = 0;
  $handler->display->display_options['fields']['views_number_results']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['views_number_results']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['views_number_results']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['views_number_results']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['views_number_results']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['views_number_results']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['views_number_results']['alter']['html'] = 0;
  $handler->display->display_options['fields']['views_number_results']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['views_number_results']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['views_number_results']['hide_empty'] = 0;
  $handler->display->display_options['fields']['views_number_results']['empty_zero'] = 0;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  
  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'number-results';
  $translatables['number_results'] = array(
    t('Master'),
    t('Number Results'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Total Number Results'),
    t('Page'),
  );

  return $views;
}
