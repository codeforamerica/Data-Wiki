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
  $view->name = 'categories';
  $view->description = 'A view of categories';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Categories';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Categories';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Taxonomy: Term */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = 1;
  /* Filter criterion: Taxonomy: Vocabulary machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'categories' => 'categories',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'categories';
  $translatables['categories'] = array(
    t('Master'),
    t('Categories'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Page'),
  );
  $export['categories'] = $view;

  $view = new view;
  $view->name = 'web_resources';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Online Communities';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Online Communities';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 1;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'search_result';
  $handler->display->display_options['row_options']['links'] = 1;
  $handler->display->display_options['row_options']['comments'] = 0;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = 'These are online community resources, blogs, and links to discussions.

Anyone can add more community discussions. <a href="/user">Sign up</a> to <a href="/node/add/online-community">add</a>, update and <a href="/node/add/feed-web-resource">import</a> data.';
  /* Relationship: Feeds item: Owner feed */
  $handler->display->display_options['relationships']['feed_nid']['id'] = 'feed_nid';
  $handler->display->display_options['relationships']['feed_nid']['table'] = 'feeds_item';
  $handler->display->display_options['relationships']['feed_nid']['field'] = 'feed_nid';
  $handler->display->display_options['relationships']['feed_nid']['required'] = 0;
  $handler->display->display_options['relationships']['feed_nid']['reverse_relation'] = 0;
  /* Field: Fields: Neighborhood */
  $handler->display->display_options['fields']['field_neighborhood']['id'] = 'field_neighborhood';
  $handler->display->display_options['fields']['field_neighborhood']['table'] = 'field_data_field_neighborhood';
  $handler->display->display_options['fields']['field_neighborhood']['field'] = 'field_neighborhood';
  $handler->display->display_options['fields']['field_neighborhood']['label'] = '';
  $handler->display->display_options['fields']['field_neighborhood']['exclude'] = TRUE;
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
  $handler->display->display_options['fields']['field_neighborhood']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_neighborhood']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_neighborhood']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_neighborhood']['field_api_classes'] = 0;
  /* Field: Fields: Region */
  $handler->display->display_options['fields']['field_region']['id'] = 'field_region';
  $handler->display->display_options['fields']['field_region']['table'] = 'field_data_field_region';
  $handler->display->display_options['fields']['field_region']['field'] = 'field_region';
  $handler->display->display_options['fields']['field_region']['label'] = '';
  $handler->display->display_options['fields']['field_region']['exclude'] = TRUE;
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
  /* Field: Fields: State */
  $handler->display->display_options['fields']['field_state']['id'] = 'field_state';
  $handler->display->display_options['fields']['field_state']['table'] = 'field_data_field_state';
  $handler->display->display_options['fields']['field_state']['field'] = 'field_state';
  $handler->display->display_options['fields']['field_state']['label'] = '';
  $handler->display->display_options['fields']['field_state']['exclude'] = TRUE;
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
  /* Field: Fields: City */
  $handler->display->display_options['fields']['field_city']['id'] = 'field_city';
  $handler->display->display_options['fields']['field_city']['table'] = 'field_data_field_city';
  $handler->display->display_options['fields']['field_city']['field'] = 'field_city';
  $handler->display->display_options['fields']['field_city']['label'] = '';
  $handler->display->display_options['fields']['field_city']['exclude'] = TRUE;
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
  /* Field: Fields: Location */
  $handler->display->display_options['fields']['field_location']['id'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['table'] = 'field_data_field_location';
  $handler->display->display_options['fields']['field_location']['field'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['label'] = '';
  $handler->display->display_options['fields']['field_location']['exclude'] = TRUE;
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
  /* Field: Fields: URL */
  $handler->display->display_options['fields']['field_url_1']['id'] = 'field_url_1';
  $handler->display->display_options['fields']['field_url_1']['table'] = 'field_data_field_url';
  $handler->display->display_options['fields']['field_url_1']['field'] = 'field_url';
  $handler->display->display_options['fields']['field_url_1']['label'] = '';
  $handler->display->display_options['fields']['field_url_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_url_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_url_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_url_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_url_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_url_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_url_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_url_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_url_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_url_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_url_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_url_1']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_url_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_url_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_url_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_url_1']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_url_1']['field_api_classes'] = 0;
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
  /* Field: Fields: Ownership */
  $handler->display->display_options['fields']['field_ownership']['id'] = 'field_ownership';
  $handler->display->display_options['fields']['field_ownership']['table'] = 'field_data_field_ownership';
  $handler->display->display_options['fields']['field_ownership']['field'] = 'field_ownership';
  $handler->display->display_options['fields']['field_ownership']['label'] = '';
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
  $handler->display->display_options['fields']['field_ownership']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_ownership']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_ownership']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_ownership']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_ownership']['click_sort_column'] = 'tid';
  $handler->display->display_options['fields']['field_ownership']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_ownership']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_ownership']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_ownership']['field_api_classes'] = 0;
  /* Field: Fields: Type of Group */
  $handler->display->display_options['fields']['field_type_web_resource']['id'] = 'field_type_web_resource';
  $handler->display->display_options['fields']['field_type_web_resource']['table'] = 'field_data_field_type_web_resource';
  $handler->display->display_options['fields']['field_type_web_resource']['field'] = 'field_type_web_resource';
  $handler->display->display_options['fields']['field_type_web_resource']['label'] = '';
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
  $handler->display->display_options['fields']['field_type_web_resource']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_type_web_resource']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_type_web_resource']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_type_web_resource']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_type_web_resource']['click_sort_column'] = 'tid';
  $handler->display->display_options['fields']['field_type_web_resource']['field_api_classes'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_neighborhood][field_region]
[field_city] [field_state]';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['nl2br'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nothing']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing']['empty_zero'] = 0;
  /* Field: Feeds source: Feed node id */
  $handler->display->display_options['fields']['feed_nid']['id'] = 'feed_nid';
  $handler->display->display_options['fields']['feed_nid']['table'] = 'feeds_source';
  $handler->display->display_options['fields']['feed_nid']['field'] = 'feed_nid';
  $handler->display->display_options['fields']['feed_nid']['relationship'] = 'feed_nid';
  $handler->display->display_options['fields']['feed_nid']['label'] = '';
  $handler->display->display_options['fields']['feed_nid']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['feed_nid']['alter']['text'] = 'Source';
  $handler->display->display_options['fields']['feed_nid']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['feed_nid']['alter']['path'] = 'node/[feed_nid]';
  $handler->display->display_options['fields']['feed_nid']['alter']['absolute'] = 1;
  $handler->display->display_options['fields']['feed_nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['feed_nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['feed_nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['feed_nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['feed_nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['feed_nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['feed_nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['feed_nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['feed_nid']['element_type'] = 'div';
  $handler->display->display_options['fields']['feed_nid']['element_class'] = 'data-edit';
  $handler->display->display_options['fields']['feed_nid']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['feed_nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['feed_nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['feed_nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['feed_nid']['format_plural'] = 0;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 1;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '[feed_nid] | [edit_node]';
  $handler->display->display_options['fields']['edit_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['path'] = 'node/[nid]/edit';
  $handler->display->display_options['fields']['edit_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['external'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['edit_node']['element_type'] = 'div';
  $handler->display->display_options['fields']['edit_node']['element_class'] = 'data-edit';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['edit_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['edit_node']['empty_zero'] = 0;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Correct this data';
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
    'online_community' => 'online_community',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['path'] = 'online-communities';

  /* Display: ( JSON) Web Resource */
  $handler = $view->new_display('page', '( JSON) Web Resource', 'page_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_json';
  $handler->display->display_options['style_options']['root_object'] = 'rows';
  $handler->display->display_options['style_options']['top_child_object'] = 'web_resource';
  $handler->display->display_options['style_options']['plaintext_output'] = 1;
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
  /* Field: Fields: URL */
  $handler->display->display_options['fields']['field_url']['id'] = 'field_url';
  $handler->display->display_options['fields']['field_url']['table'] = 'field_data_field_url';
  $handler->display->display_options['fields']['field_url']['field'] = 'field_url';
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
  $handler->display->display_options['fields']['field_url']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_url']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_url']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_url']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_url']['field_api_classes'] = 0;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = 'permalink';
  $handler->display->display_options['fields']['path']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['path']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['path']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['path']['alter']['external'] = 0;
  $handler->display->display_options['fields']['path']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['path']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['path']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['path']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['path']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['path']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['path']['alter']['html'] = 0;
  $handler->display->display_options['fields']['path']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['path']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['path']['hide_empty'] = 0;
  $handler->display->display_options['fields']['path']['empty_zero'] = 0;
  $handler->display->display_options['fields']['path']['absolute'] = 1;
  /* Field: Fields: Location */
  $handler->display->display_options['fields']['field_location']['id'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['table'] = 'field_data_field_location';
  $handler->display->display_options['fields']['field_location']['field'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['label'] = 'location';
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
  $handler->display->display_options['fields']['field_location']['type'] = 'geofield_geojson';
  $handler->display->display_options['fields']['field_location']['settings'] = array(
    'data' => 'full',
  );
  $handler->display->display_options['fields']['field_location']['field_api_classes'] = 0;
  /* Field: Fields: Neighborhood */
  $handler->display->display_options['fields']['field_neighborhood']['id'] = 'field_neighborhood';
  $handler->display->display_options['fields']['field_neighborhood']['table'] = 'field_data_field_neighborhood';
  $handler->display->display_options['fields']['field_neighborhood']['field'] = 'field_neighborhood';
  $handler->display->display_options['fields']['field_neighborhood']['label'] = 'neighborhood';
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
  $handler->display->display_options['fields']['field_neighborhood']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_neighborhood']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_neighborhood']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_neighborhood']['field_api_classes'] = 0;
  /* Field: Fields: Region */
  $handler->display->display_options['fields']['field_region']['id'] = 'field_region';
  $handler->display->display_options['fields']['field_region']['table'] = 'field_data_field_region';
  $handler->display->display_options['fields']['field_region']['field'] = 'field_region';
  $handler->display->display_options['fields']['field_region']['label'] = 'region';
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
  $handler->display->display_options['fields']['field_city']['label'] = 'city';
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
  $handler->display->display_options['fields']['field_state']['label'] = 'state';
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
  /* Field: Fields: Categories */
  $handler->display->display_options['fields']['field_categories']['id'] = 'field_categories';
  $handler->display->display_options['fields']['field_categories']['table'] = 'field_data_field_categories';
  $handler->display->display_options['fields']['field_categories']['field'] = 'field_categories';
  $handler->display->display_options['fields']['field_categories']['label'] = 'categories';
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
  /* Field: Fields: Ownership */
  $handler->display->display_options['fields']['field_ownership']['id'] = 'field_ownership';
  $handler->display->display_options['fields']['field_ownership']['table'] = 'field_data_field_ownership';
  $handler->display->display_options['fields']['field_ownership']['field'] = 'field_ownership';
  $handler->display->display_options['fields']['field_ownership']['label'] = 'ownership';
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
  $handler->display->display_options['fields']['field_ownership']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_ownership']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_ownership']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_ownership']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_ownership']['click_sort_column'] = 'tid';
  $handler->display->display_options['fields']['field_ownership']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_ownership']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_ownership']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_ownership']['field_api_classes'] = 0;
  /* Field: Fields: Type of Group */
  $handler->display->display_options['fields']['field_type_web_resource']['id'] = 'field_type_web_resource';
  $handler->display->display_options['fields']['field_type_web_resource']['table'] = 'field_data_field_type_web_resource';
  $handler->display->display_options['fields']['field_type_web_resource']['field'] = 'field_type_web_resource';
  $handler->display->display_options['fields']['field_type_web_resource']['label'] = 'type';
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
  $handler->display->display_options['fields']['field_type_web_resource']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_type_web_resource']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_type_web_resource']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_type_web_resource']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_type_web_resource']['click_sort_column'] = 'tid';
  $handler->display->display_options['fields']['field_type_web_resource']['field_api_classes'] = 0;
  /* Field: Feeds source: Feed node id */
  $handler->display->display_options['fields']['feed_nid']['id'] = 'feed_nid';
  $handler->display->display_options['fields']['feed_nid']['table'] = 'feeds_source';
  $handler->display->display_options['fields']['feed_nid']['field'] = 'feed_nid';
  $handler->display->display_options['fields']['feed_nid']['relationship'] = 'feed_nid';
  $handler->display->display_options['fields']['feed_nid']['label'] = '';
  $handler->display->display_options['fields']['feed_nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['feed_nid']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['feed_nid']['alter']['path'] = 'node/[feed_nid]';
  $handler->display->display_options['fields']['feed_nid']['alter']['absolute'] = 1;
  $handler->display->display_options['fields']['feed_nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['feed_nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['feed_nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['feed_nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['feed_nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['feed_nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['feed_nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['feed_nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['feed_nid']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['feed_nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['feed_nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['feed_nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['feed_nid']['format_plural'] = 0;
  $handler->display->display_options['path'] = 'json/online-communities';
  $translatables['web_resources'] = array(
    t('Master'),
    t('Online Communities'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('These are online community resources, blogs, and links to discussions.

Anyone can add more community discussions. <a href="/user">Sign up</a> to <a href="/node/add/online-community">add</a>, update and <a href="/node/add/feed-web-resource">import</a> data.'),
    t('Owner feed'),
    t('[field_url]'),
    t('[field_neighborhood][field_region]
[field_city] [field_state]'),
    t('Source'),
    t('node/[feed_nid]'),
    t('.'),
    t(','),
    t('Nid'),
    t('[feed_nid] | [edit_node]'),
    t('node/[nid]/edit'),
    t('Correct this data'),
    t('Page'),
    t('( JSON) Web Resource'),
    t('URL'),
    t('permalink'),
    t('location'),
    t('neighborhood'),
    t('region'),
    t('city'),
    t('state'),
    t('categories'),
    t('ownership'),
    t('type'),
  );
  $export['web_resources'] = $view;

  return $export;
}
