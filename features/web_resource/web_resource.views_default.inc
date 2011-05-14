<?php
/**
 * @file
 * web_resource.views_default.inc
 */

/**
 * Implementation of hook_views_default_views().
 */
function web_resource_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'web_resources';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Web resources';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Web resources';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  /* Field: Fields: URL */
  $handler->display->display_options['fields']['field_url']['id'] = 'field_url';
  $handler->display->display_options['fields']['field_url']['table'] = 'field_data_field_url';
  $handler->display->display_options['fields']['field_url']['field'] = 'field_url';
  $handler->display->display_options['fields']['field_url']['label'] = '';
  $handler->display->display_options['fields']['field_url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_url']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_url']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_url']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_url']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_url']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_url']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_url']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_url']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_url']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_url']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_url']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_url']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_url']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_url']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_url']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_url']['field_api_classes'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['title']['alter']['path'] = '[field_url]';
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 1;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 1;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
  /* Field: Fields: Categories */
  $handler->display->display_options['fields']['field_categories']['id'] = 'field_categories';
  $handler->display->display_options['fields']['field_categories']['table'] = 'field_data_field_categories';
  $handler->display->display_options['fields']['field_categories']['field'] = 'field_categories';
  $handler->display->display_options['fields']['field_categories']['label'] = '';
  $handler->display->display_options['fields']['field_categories']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_categories']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_categories']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_categories']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_categories']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_categories']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_categories']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_categories']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_categories']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_categories']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_categories']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_categories']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_categories']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_categories']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_categories']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_categories']['click_sort_column'] = 'tid';
  $handler->display->display_options['fields']['field_categories']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_categories']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_categories']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_categories']['field_api_classes'] = 0;
  /* Field: Fields: Neighborhood */
  $handler->display->display_options['fields']['field_neighborhood']['id'] = 'field_neighborhood';
  $handler->display->display_options['fields']['field_neighborhood']['table'] = 'field_data_field_neighborhood';
  $handler->display->display_options['fields']['field_neighborhood']['field'] = 'field_neighborhood';
  $handler->display->display_options['fields']['field_neighborhood']['label'] = '';
  $handler->display->display_options['fields']['field_neighborhood']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_neighborhood']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_neighborhood']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_neighborhood']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_neighborhood']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_neighborhood']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_neighborhood']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_neighborhood']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_neighborhood']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_neighborhood']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_neighborhood']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_neighborhood']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_neighborhood']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_neighborhood']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_neighborhood']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_neighborhood']['click_sort_column'] = 'tid';
  $handler->display->display_options['fields']['field_neighborhood']['field_api_classes'] = 0;
  /* Field: Fields: Region */
  $handler->display->display_options['fields']['field_region']['id'] = 'field_region';
  $handler->display->display_options['fields']['field_region']['table'] = 'field_data_field_region';
  $handler->display->display_options['fields']['field_region']['field'] = 'field_region';
  $handler->display->display_options['fields']['field_region']['label'] = '';
  $handler->display->display_options['fields']['field_region']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_region']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_region']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_region']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_region']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_region']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_region']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_region']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_region']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_region']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_region']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_region']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_region']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_region']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_region']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_region']['click_sort_column'] = 'tid';
  $handler->display->display_options['fields']['field_region']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_region']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_region']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_region']['field_api_classes'] = 0;
  /* Field: Fields: City */
  $handler->display->display_options['fields']['field_city']['id'] = 'field_city';
  $handler->display->display_options['fields']['field_city']['table'] = 'field_data_field_city';
  $handler->display->display_options['fields']['field_city']['field'] = 'field_city';
  $handler->display->display_options['fields']['field_city']['label'] = '';
  $handler->display->display_options['fields']['field_city']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_city']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_city']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_city']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_city']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_city']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_city']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_city']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_city']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_city']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_city']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_city']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_city']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_city']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_city']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_city']['click_sort_column'] = 'tid';
  $handler->display->display_options['fields']['field_city']['field_api_classes'] = 0;
  /* Field: Fields: State */
  $handler->display->display_options['fields']['field_state']['id'] = 'field_state';
  $handler->display->display_options['fields']['field_state']['table'] = 'field_data_field_state';
  $handler->display->display_options['fields']['field_state']['field'] = 'field_state';
  $handler->display->display_options['fields']['field_state']['label'] = '';
  $handler->display->display_options['fields']['field_state']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_state']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_state']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_state']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_state']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_state']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_state']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_state']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_state']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_state']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_state']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_state']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_state']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_state']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_state']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_state']['click_sort_column'] = 'tid';
  $handler->display->display_options['fields']['field_state']['field_api_classes'] = 0;
  /* Field: Fields: Location */
  $handler->display->display_options['fields']['field_location']['id'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['table'] = 'field_data_field_location';
  $handler->display->display_options['fields']['field_location']['field'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['label'] = '';
  $handler->display->display_options['fields']['field_location']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_location']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_location']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_location']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_location']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_location']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_location']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_location']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_location']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_location']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_location']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_location']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_location']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_location']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_location']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_location']['click_sort_column'] = 'wkt';
  $handler->display->display_options['fields']['field_location']['type'] = 'geofield_wkt';
  $handler->display->display_options['fields']['field_location']['settings'] = array(
    'data' => 'full',
  );
  $handler->display->display_options['fields']['field_location']['field_api_classes'] = 0;
  /* Field: Fields: Ownership */
  $handler->display->display_options['fields']['field_ownership']['id'] = 'field_ownership';
  $handler->display->display_options['fields']['field_ownership']['table'] = 'field_data_field_ownership';
  $handler->display->display_options['fields']['field_ownership']['field'] = 'field_ownership';
  $handler->display->display_options['fields']['field_ownership']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_ownership']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_ownership']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_ownership']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_ownership']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_ownership']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_ownership']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_ownership']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_ownership']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_ownership']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_ownership']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_ownership']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_ownership']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_ownership']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_ownership']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_ownership']['click_sort_column'] = 'tid';
  $handler->display->display_options['fields']['field_ownership']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_ownership']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_ownership']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_ownership']['field_api_classes'] = 0;
  /* Field: Fields: Type */
  $handler->display->display_options['fields']['field_type_web_resource']['id'] = 'field_type_web_resource';
  $handler->display->display_options['fields']['field_type_web_resource']['table'] = 'field_data_field_type_web_resource';
  $handler->display->display_options['fields']['field_type_web_resource']['field'] = 'field_type_web_resource';
  $handler->display->display_options['fields']['field_type_web_resource']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_type_web_resource']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_type_web_resource']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_type_web_resource']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_type_web_resource']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_type_web_resource']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_type_web_resource']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_type_web_resource']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_type_web_resource']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_type_web_resource']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_type_web_resource']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_type_web_resource']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_type_web_resource']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_type_web_resource']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_type_web_resource']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_type_web_resource']['click_sort_column'] = 'tid';
  $handler->display->display_options['fields']['field_type_web_resource']['field_api_classes'] = 0;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['external'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['edit_node']['element_label_type'] = 'em';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['edit_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['edit_node']['empty_zero'] = 0;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Improve this data!';
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
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'web_resource' => 'web_resource',
  );
  /* Filter criterion: Search: Search Terms */
  $handler->display->display_options['filters']['keys']['id'] = 'keys';
  $handler->display->display_options['filters']['keys']['table'] = 'search_index';
  $handler->display->display_options['filters']['keys']['field'] = 'keys';
  $handler->display->display_options['filters']['keys']['exposed'] = TRUE;
  $handler->display->display_options['filters']['keys']['expose']['operator_id'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['keys']['expose']['operator'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['identifier'] = 'keys';
  $handler->display->display_options['filters']['keys']['expose']['multiple'] = FALSE;
  /* Filter criterion: Taxonomy: Term ID (with depth) */
  $handler->display->display_options['filters']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['filters']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['value'] = '';
  $handler->display->display_options['filters']['term_node_tid_depth']['exposed'] = TRUE;
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['operator_id'] = 'term_node_tid_depth_op';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['label'] = 'Neighborhood';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['operator'] = 'term_node_tid_depth_op';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['identifier'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['reduce_duplicates'] = 1;
  $handler->display->display_options['filters']['term_node_tid_depth']['vocabulary'] = 'neighborhood';
  $handler->display->display_options['filters']['term_node_tid_depth']['error_message'] = 1;
  $handler->display->display_options['filters']['term_node_tid_depth']['depth'] = '0';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'web-resources';
  $translatables['web_resources'] = array(
    t('Master'),
    t('Web resources'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('[field_url]'),
    t('Ownership'),
    t('Type'),
    t('Improve this data!'),
    t('Search'),
    t('Neighborhood'),
    t('Page'),
  );
  $export['web_resources'] = $view;

  return $export;
}
