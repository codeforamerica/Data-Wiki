<?php
/**
 * @file
 * datawiki_views.views_default.inc
 */

/**
 * Implementation of hook_views_default_views().
 */
function datawiki_views_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'categories';
  $view->description = 'Displaying Categories';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Categories';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Data Categories';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '250';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Total Number Results */
  $handler->display->display_options['header']['views_number_results']['id'] = 'views_number_results';
  $handler->display->display_options['header']['views_number_results']['table'] = 'views';
  $handler->display->display_options['header']['views_number_results']['field'] = 'views_number_results';
  $handler->display->display_options['header']['views_number_results']['empty'] = FALSE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Term';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = 1;
  /* Field: Taxonomy term: Term description */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  $handler->display->display_options['fields']['description']['label'] = 'Term Description';
  $handler->display->display_options['fields']['description']['exclude'] = TRUE;
  $handler->display->display_options['fields']['description']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['description']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['description']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['description']['alter']['external'] = 0;
  $handler->display->display_options['fields']['description']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['description']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['description']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['description']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['description']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['description']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['description']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['description']['alter']['html'] = 0;
  $handler->display->display_options['fields']['description']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['description']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['description']['hide_empty'] = 0;
  $handler->display->display_options['fields']['description']['empty_zero'] = 0;
  $handler->display->display_options['fields']['description']['hide_alter_empty'] = 0;
  /* Field: Taxonomy term: Image File */
  $handler->display->display_options['fields']['field_file_image']['id'] = 'field_file_image';
  $handler->display->display_options['fields']['field_file_image']['table'] = 'field_data_field_file_image';
  $handler->display->display_options['fields']['field_file_image']['field'] = 'field_file_image';
  $handler->display->display_options['fields']['field_file_image']['label'] = 'Image';
  $handler->display->display_options['fields']['field_file_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_file_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_file_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_file_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_file_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_file_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_file_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_file_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_file_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_file_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_file_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_file_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_file_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_file_image']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_file_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_file_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_file_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_file_image']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_file_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_file_image']['type'] = 'file_url_plain';
  $handler->display->display_options['fields']['field_file_image']['field_api_classes'] = 0;
  /* Field: Taxonomy vocabulary: Name */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['label'] = 'Vocabulary Name';
  $handler->display->display_options['fields']['name_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name_1']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['name_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name_1']['hide_alter_empty'] = 0;
  /* Sort criterion: Taxonomy term: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'categories' => 'categories',
    'civic_taxonomy' => 'civic_taxonomy',
    'demographics' => 'demographics',
    'type_community' => 'type_community',
    'type_group' => 'type_group',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Categories';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = 1;
  /* Field: Taxonomy term: Term description */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  $handler->display->display_options['fields']['description']['label'] = 'Term Description';
  $handler->display->display_options['fields']['description']['exclude'] = TRUE;
  $handler->display->display_options['fields']['description']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['description']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['description']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['description']['alter']['external'] = 0;
  $handler->display->display_options['fields']['description']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['description']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['description']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['description']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['description']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['description']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['description']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['description']['alter']['html'] = 0;
  $handler->display->display_options['fields']['description']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['description']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['description']['hide_empty'] = 0;
  $handler->display->display_options['fields']['description']['empty_zero'] = 0;
  $handler->display->display_options['fields']['description']['hide_alter_empty'] = 0;
  /* Field: Taxonomy term: Image File */
  $handler->display->display_options['fields']['field_file_image']['id'] = 'field_file_image';
  $handler->display->display_options['fields']['field_file_image']['table'] = 'field_data_field_file_image';
  $handler->display->display_options['fields']['field_file_image']['field'] = 'field_file_image';
  $handler->display->display_options['fields']['field_file_image']['label'] = 'Image';
  $handler->display->display_options['fields']['field_file_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_file_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_file_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_file_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_file_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_file_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_file_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_file_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_file_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_file_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_file_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_file_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_file_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_file_image']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_file_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_file_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_file_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_file_image']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_file_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_file_image']['type'] = 'file_url_plain';
  $handler->display->display_options['fields']['field_file_image']['field_api_classes'] = 0;
  /* Field: Taxonomy vocabulary: Name */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['label'] = 'Vocabulary Name';
  $handler->display->display_options['fields']['name_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name_1']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['name_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name_1']['hide_alter_empty'] = 0;
  $handler->display->display_options['path'] = 'categories';

  /* Display: Civic Taxonomies */
  $handler = $view->new_display('page', 'Civic Taxonomies', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Civic Taxonomy';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Term';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = 1;
  /* Field: Taxonomy term: Term description */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  $handler->display->display_options['fields']['description']['label'] = 'Term Description';
  $handler->display->display_options['fields']['description']['exclude'] = TRUE;
  $handler->display->display_options['fields']['description']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['description']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['description']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['description']['alter']['external'] = 0;
  $handler->display->display_options['fields']['description']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['description']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['description']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['description']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['description']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['description']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['description']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['description']['alter']['html'] = 0;
  $handler->display->display_options['fields']['description']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['description']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['description']['hide_empty'] = 0;
  $handler->display->display_options['fields']['description']['empty_zero'] = 0;
  $handler->display->display_options['fields']['description']['hide_alter_empty'] = 0;
  /* Field: Taxonomy term: Image File */
  $handler->display->display_options['fields']['field_file_image']['id'] = 'field_file_image';
  $handler->display->display_options['fields']['field_file_image']['table'] = 'field_data_field_file_image';
  $handler->display->display_options['fields']['field_file_image']['field'] = 'field_file_image';
  $handler->display->display_options['fields']['field_file_image']['label'] = 'Image';
  $handler->display->display_options['fields']['field_file_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_file_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_file_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_file_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_file_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_file_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_file_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_file_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_file_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_file_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_file_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_file_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_file_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_file_image']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_file_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_file_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_file_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_file_image']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_file_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_file_image']['type'] = 'file_url_plain';
  $handler->display->display_options['fields']['field_file_image']['field_api_classes'] = 0;
  /* Field: Taxonomy vocabulary: Name */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['label'] = 'Vocabulary Name';
  $handler->display->display_options['fields']['name_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name_1']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['name_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name_1']['hide_alter_empty'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'civic_taxonomy' => 'civic_taxonomy',
  );
  $handler->display->display_options['path'] = 'civic-taxonomy';

  /* Display: Terms */
  $handler = $view->new_display('page', 'Terms', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'All Terms';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
    'description' => 'description',
    'field_file_image' => 'field_file_image',
    'name_1' => 'name_1',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'description' => array(
      'align' => '',
      'separator' => '',
    ),
    'field_file_image' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'name_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'all' => 'all',
    'activity_level' => 'activity_level',
    'area_code' => 'area_code',
    'audience_size' => 'audience_size',
    'categories' => 'categories',
    'city' => 'city',
    'civic_taxonomy' => 'civic_taxonomy',
    'district' => 'district',
    'neighborhood' => 'neighborhood',
    'ownership' => 'ownership',
    'region' => 'region',
    'state' => 'state',
    'tags' => 'tags',
    'type_group' => 'type_group',
    'type_of_group' => 'type_of_group',
    'zipcode' => 'zipcode',
  );
  $handler->display->display_options['filters']['machine_name']['expose']['operator_id'] = 'machine_name_op';
  $handler->display->display_options['filters']['machine_name']['expose']['label'] = 'Vocabularies';
  $handler->display->display_options['filters']['machine_name']['expose']['operator'] = 'machine_name_op';
  $handler->display->display_options['filters']['machine_name']['expose']['identifier'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['expose']['reduce'] = 0;
  $handler->display->display_options['path'] = 'terms';
  $export['categories'] = $view;

  $view = new view;
  $view->name = 'categories_v2';
  $view->description = 'Displaying Categories';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Categories v2';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Data Categories';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '250';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Total Number Results */
  $handler->display->display_options['header']['views_number_results']['id'] = 'views_number_results';
  $handler->display->display_options['header']['views_number_results']['table'] = 'views';
  $handler->display->display_options['header']['views_number_results']['field'] = 'views_number_results';
  $handler->display->display_options['header']['views_number_results']['empty'] = FALSE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Term';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = 1;
  /* Field: Taxonomy term: Term description */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  $handler->display->display_options['fields']['description']['label'] = 'Term Description';
  $handler->display->display_options['fields']['description']['exclude'] = TRUE;
  $handler->display->display_options['fields']['description']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['description']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['description']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['description']['alter']['external'] = 0;
  $handler->display->display_options['fields']['description']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['description']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['description']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['description']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['description']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['description']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['description']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['description']['alter']['html'] = 0;
  $handler->display->display_options['fields']['description']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['description']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['description']['hide_empty'] = 0;
  $handler->display->display_options['fields']['description']['empty_zero'] = 0;
  $handler->display->display_options['fields']['description']['hide_alter_empty'] = 0;
  /* Field: Taxonomy term: Image File */
  $handler->display->display_options['fields']['field_file_image']['id'] = 'field_file_image';
  $handler->display->display_options['fields']['field_file_image']['table'] = 'field_data_field_file_image';
  $handler->display->display_options['fields']['field_file_image']['field'] = 'field_file_image';
  $handler->display->display_options['fields']['field_file_image']['label'] = 'Image';
  $handler->display->display_options['fields']['field_file_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_file_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_file_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_file_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_file_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_file_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_file_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_file_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_file_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_file_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_file_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_file_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_file_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_file_image']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_file_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_file_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_file_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_file_image']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_file_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_file_image']['type'] = 'file_url_plain';
  $handler->display->display_options['fields']['field_file_image']['field_api_classes'] = 0;
  /* Field: Taxonomy vocabulary: Name */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['label'] = 'Vocabulary Name';
  $handler->display->display_options['fields']['name_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name_1']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['name_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name_1']['hide_alter_empty'] = 0;
  /* Sort criterion: Taxonomy term: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'categories' => 'categories',
    'civic_taxonomy' => 'civic_taxonomy',
    'demographics' => 'demographics',
    'type_community' => 'type_community',
    'type_group' => 'type_group',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Categories';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = 1;
  /* Field: Taxonomy term: Term description */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  $handler->display->display_options['fields']['description']['label'] = 'Term Description';
  $handler->display->display_options['fields']['description']['exclude'] = TRUE;
  $handler->display->display_options['fields']['description']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['description']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['description']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['description']['alter']['external'] = 0;
  $handler->display->display_options['fields']['description']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['description']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['description']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['description']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['description']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['description']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['description']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['description']['alter']['html'] = 0;
  $handler->display->display_options['fields']['description']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['description']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['description']['hide_empty'] = 0;
  $handler->display->display_options['fields']['description']['empty_zero'] = 0;
  $handler->display->display_options['fields']['description']['hide_alter_empty'] = 0;
  /* Field: Taxonomy term: Image File */
  $handler->display->display_options['fields']['field_file_image']['id'] = 'field_file_image';
  $handler->display->display_options['fields']['field_file_image']['table'] = 'field_data_field_file_image';
  $handler->display->display_options['fields']['field_file_image']['field'] = 'field_file_image';
  $handler->display->display_options['fields']['field_file_image']['label'] = 'Image';
  $handler->display->display_options['fields']['field_file_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_file_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_file_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_file_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_file_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_file_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_file_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_file_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_file_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_file_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_file_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_file_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_file_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_file_image']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_file_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_file_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_file_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_file_image']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_file_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_file_image']['type'] = 'file_url_plain';
  $handler->display->display_options['fields']['field_file_image']['field_api_classes'] = 0;
  /* Field: Taxonomy vocabulary: Name */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['label'] = 'Vocabulary Name';
  $handler->display->display_options['fields']['name_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name_1']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['name_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name_1']['hide_alter_empty'] = 0;
  $handler->display->display_options['path'] = 'categories-v2';

  /* Display: Civic Taxonomies */
  $handler = $view->new_display('page', 'Civic Taxonomies', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Civic Taxonomy';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Term';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = 1;
  /* Field: Taxonomy term: Term description */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  $handler->display->display_options['fields']['description']['label'] = 'Term Description';
  $handler->display->display_options['fields']['description']['exclude'] = TRUE;
  $handler->display->display_options['fields']['description']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['description']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['description']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['description']['alter']['external'] = 0;
  $handler->display->display_options['fields']['description']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['description']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['description']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['description']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['description']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['description']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['description']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['description']['alter']['html'] = 0;
  $handler->display->display_options['fields']['description']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['description']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['description']['hide_empty'] = 0;
  $handler->display->display_options['fields']['description']['empty_zero'] = 0;
  $handler->display->display_options['fields']['description']['hide_alter_empty'] = 0;
  /* Field: Taxonomy term: Image File */
  $handler->display->display_options['fields']['field_file_image']['id'] = 'field_file_image';
  $handler->display->display_options['fields']['field_file_image']['table'] = 'field_data_field_file_image';
  $handler->display->display_options['fields']['field_file_image']['field'] = 'field_file_image';
  $handler->display->display_options['fields']['field_file_image']['label'] = 'Image';
  $handler->display->display_options['fields']['field_file_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_file_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_file_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_file_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_file_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_file_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_file_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_file_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_file_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_file_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_file_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_file_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_file_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_file_image']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_file_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_file_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_file_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_file_image']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_file_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_file_image']['type'] = 'file_url_plain';
  $handler->display->display_options['fields']['field_file_image']['field_api_classes'] = 0;
  /* Field: Taxonomy vocabulary: Name */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['label'] = 'Vocabulary Name';
  $handler->display->display_options['fields']['name_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name_1']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['name_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name_1']['hide_alter_empty'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'civic_taxonomy' => 'civic_taxonomy',
  );
  $handler->display->display_options['path'] = 'civic-taxonomy-v2';

  /* Display: Terms */
  $handler = $view->new_display('page', 'Terms', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'All Terms';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
    'description' => 'description',
    'field_file_image' => 'field_file_image',
    'name_1' => 'name_1',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'description' => array(
      'align' => '',
      'separator' => '',
    ),
    'field_file_image' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'name_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'all' => 'all',
    'activity_level' => 'activity_level',
    'area_code' => 'area_code',
    'audience_size' => 'audience_size',
    'categories' => 'categories',
    'city' => 'city',
    'civic_taxonomy' => 'civic_taxonomy',
    'district' => 'district',
    'neighborhood' => 'neighborhood',
    'ownership' => 'ownership',
    'region' => 'region',
    'state' => 'state',
    'tags' => 'tags',
    'type_group' => 'type_group',
    'type_of_group' => 'type_of_group',
    'zipcode' => 'zipcode',
  );
  $handler->display->display_options['filters']['machine_name']['expose']['operator_id'] = 'machine_name_op';
  $handler->display->display_options['filters']['machine_name']['expose']['label'] = 'Vocabularies';
  $handler->display->display_options['filters']['machine_name']['expose']['operator'] = 'machine_name_op';
  $handler->display->display_options['filters']['machine_name']['expose']['identifier'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['expose']['reduce'] = 0;
  $handler->display->display_options['path'] = 'terms-v2';
  $export['categories_v2'] = $view;

  $view = new view;
  $view->name = 'data_categories';
  $view->description = 'A JSON feed of Categories';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Data Categories';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Data Categories';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '250';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'views_json';
  $handler->display->display_options['style_options']['root_object'] = 'categories';
  $handler->display->display_options['style_options']['top_child_object'] = 'term';
  $handler->display->display_options['style_options']['plaintext_output'] = 1;
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 0;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = 1;
  /* Field: Taxonomy term: Term description */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  $handler->display->display_options['fields']['description']['label'] = 'description';
  $handler->display->display_options['fields']['description']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['description']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['description']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['description']['alter']['external'] = 0;
  $handler->display->display_options['fields']['description']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['description']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['description']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['description']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['description']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['description']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['description']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['description']['alter']['html'] = 0;
  $handler->display->display_options['fields']['description']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['description']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['description']['hide_empty'] = 0;
  $handler->display->display_options['fields']['description']['empty_zero'] = 0;
  $handler->display->display_options['fields']['description']['hide_alter_empty'] = 0;
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = 'id';
  $handler->display->display_options['fields']['tid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['tid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['tid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['tid']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['tid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['tid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['tid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['tid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['tid']['format_plural'] = 0;
  /* Field: Taxonomy term: Image URL */
  $handler->display->display_options['fields']['field_term_image_url']['id'] = 'field_term_image_url';
  $handler->display->display_options['fields']['field_term_image_url']['table'] = 'field_data_field_term_image_url';
  $handler->display->display_options['fields']['field_term_image_url']['field'] = 'field_term_image_url';
  $handler->display->display_options['fields']['field_term_image_url']['label'] = 'image_url';
  $handler->display->display_options['fields']['field_term_image_url']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_term_image_url']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_term_image_url']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_term_image_url']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_term_image_url']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_term_image_url']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_term_image_url']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_term_image_url']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_term_image_url']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_term_image_url']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_term_image_url']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_term_image_url']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_term_image_url']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_term_image_url']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_term_image_url']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_term_image_url']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_term_image_url']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_term_image_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_term_image_url']['type'] = 'plain';
  $handler->display->display_options['fields']['field_term_image_url']['field_api_classes'] = 0;
  /* Field: Taxonomy term: Weight */
  $handler->display->display_options['fields']['weight']['id'] = 'weight';
  $handler->display->display_options['fields']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['weight']['field'] = 'weight';
  $handler->display->display_options['fields']['weight']['label'] = 'term_weight';
  $handler->display->display_options['fields']['weight']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['weight']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['weight']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['weight']['alter']['external'] = 0;
  $handler->display->display_options['fields']['weight']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['weight']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['weight']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['weight']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['weight']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['weight']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['weight']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['weight']['alter']['html'] = 0;
  $handler->display->display_options['fields']['weight']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['weight']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['weight']['hide_empty'] = 0;
  $handler->display->display_options['fields']['weight']['empty_zero'] = 0;
  $handler->display->display_options['fields']['weight']['hide_alter_empty'] = 0;
  /* Field: Taxonomy vocabulary: Description */
  $handler->display->display_options['fields']['description_1']['id'] = 'description_1';
  $handler->display->display_options['fields']['description_1']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['fields']['description_1']['field'] = 'description';
  $handler->display->display_options['fields']['description_1']['label'] = 'vocabulary_description';
  $handler->display->display_options['fields']['description_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['description_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['description_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['description_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['description_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['description_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['description_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['description_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['description_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['description_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['description_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['description_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['description_1']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['description_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['description_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['description_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['description_1']['hide_alter_empty'] = 0;
  /* Field: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['fields']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['fields']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['fields']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['fields']['machine_name']['label'] = 'vocabulary_machine_name';
  $handler->display->display_options['fields']['machine_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['machine_name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['machine_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['machine_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['machine_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['machine_name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['machine_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['machine_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['machine_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['machine_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['machine_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['machine_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['machine_name']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['machine_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['machine_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['machine_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['machine_name']['hide_alter_empty'] = 0;
  /* Field: Taxonomy vocabulary: Name */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['label'] = 'vocabulary_name';
  $handler->display->display_options['fields']['name_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name_1']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['name_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name_1']['hide_alter_empty'] = 0;
  /* Field: Taxonomy term: Image File */
  $handler->display->display_options['fields']['field_file_image']['id'] = 'field_file_image';
  $handler->display->display_options['fields']['field_file_image']['table'] = 'field_data_field_file_image';
  $handler->display->display_options['fields']['field_file_image']['field'] = 'field_file_image';
  $handler->display->display_options['fields']['field_file_image']['label'] = 'image';
  $handler->display->display_options['fields']['field_file_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_file_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_file_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_file_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_file_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_file_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_file_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_file_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_file_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_file_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_file_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_file_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_file_image']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_file_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_file_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_file_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_file_image']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_file_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_file_image']['type'] = 'file_url_plain';
  $handler->display->display_options['fields']['field_file_image']['field_api_classes'] = 0;
  /* Field: Taxonomy term: Location */
  $handler->display->display_options['fields']['field_term_location']['id'] = 'field_term_location';
  $handler->display->display_options['fields']['field_term_location']['table'] = 'field_data_field_term_location';
  $handler->display->display_options['fields']['field_term_location']['field'] = 'field_term_location';
  $handler->display->display_options['fields']['field_term_location']['label'] = 'geometry';
  $handler->display->display_options['fields']['field_term_location']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_term_location']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_term_location']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_term_location']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_term_location']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_term_location']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_term_location']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_term_location']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_term_location']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_term_location']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_term_location']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_term_location']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_term_location']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_term_location']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_term_location']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_term_location']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_term_location']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_term_location']['click_sort_column'] = 'wkt';
  $handler->display->display_options['fields']['field_term_location']['type'] = 'geofield_geojson';
  $handler->display->display_options['fields']['field_term_location']['settings'] = array(
    'data' => 'full',
  );
  $handler->display->display_options['fields']['field_term_location']['field_api_classes'] = 0;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'categories' => 'categories',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'categories/json';

  /* Display: Civic Taxonomies */
  $handler = $view->new_display('page', 'Civic Taxonomies', 'page_1');
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'categories' => 'categories',
  );
  $handler->display->display_options['path'] = 'civic-taxonomy/json';

  /* Display: Terms */
  $handler = $view->new_display('page', 'Terms', 'page_2');
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'all' => 'all',
    'activity_level' => 'activity_level',
    'area_code' => 'area_code',
    'audience_size' => 'audience_size',
    'categories' => 'categories',
    'city' => 'city',
    'civic_taxonomy' => 'civic_taxonomy',
    'district' => 'district',
    'neighborhood' => 'neighborhood',
    'ownership' => 'ownership',
    'region' => 'region',
    'state' => 'state',
    'tags' => 'tags',
    'type_group' => 'type_group',
    'type_dataset' => 'type_dataset',
    'type_of_group' => 'type_of_group',
    'zipcode' => 'zipcode',
  );
  $handler->display->display_options['path'] = 'terms/json';
  $export['data_categories'] = $view;

  $view = new view;
  $view->name = 'flagged_content';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Flagged Content';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Duplicate Content';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'search_result';
  $handler->display->display_options['row_options']['links'] = 0;
  $handler->display->display_options['row_options']['comments'] = 0;
  /* Relationship: Flags: duplicate */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'duplicate';
  $handler->display->display_options['relationships']['flag_content_rel']['user_scope'] = 'any';
  /* Relationship: Flags: duplicate counter */
  $handler->display->display_options['relationships']['flag_count_rel']['id'] = 'flag_count_rel';
  $handler->display->display_options['relationships']['flag_count_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_count_rel']['field'] = 'flag_count_rel';
  $handler->display->display_options['relationships']['flag_count_rel']['flag'] = 'duplicate';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
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
  $handler->display->display_options['fields']['edit_node']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['edit_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['edit_node']['empty_zero'] = 0;
  $handler->display->display_options['fields']['edit_node']['hide_alter_empty'] = 0;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
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
    'community_group' => 'community_group',
  );

  /* Display: Duplicates */
  $handler = $view->new_display('page', 'Duplicates', 'page');
  $handler->display->display_options['path'] = 'manage/duplicates';

  /* Display: Inappropriate */
  $handler = $view->new_display('page', 'Inappropriate', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Inappropriate Content';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Flags: inappropriate */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'inappropriate';
  $handler->display->display_options['relationships']['flag_content_rel']['user_scope'] = 'any';
  /* Relationship: Flags: inappropriate counter */
  $handler->display->display_options['relationships']['flag_count_rel']['id'] = 'flag_count_rel';
  $handler->display->display_options['relationships']['flag_count_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_count_rel']['field'] = 'flag_count_rel';
  $handler->display->display_options['relationships']['flag_count_rel']['flag'] = 'inappropriate';
  $handler->display->display_options['path'] = 'manage/inappropriate';

  /* Display: Recommended */
  $handler = $view->new_display('page', 'Recommended', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Recommended Groups';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Flags: like */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'like';
  $handler->display->display_options['relationships']['flag_content_rel']['user_scope'] = 'any';
  /* Relationship: Flags: like counter */
  $handler->display->display_options['relationships']['flag_count_rel']['id'] = 'flag_count_rel';
  $handler->display->display_options['relationships']['flag_count_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_count_rel']['field'] = 'flag_count_rel';
  $handler->display->display_options['relationships']['flag_count_rel']['flag'] = 'like';
  $handler->display->display_options['path'] = 'manage/recommended';

  /* Display: Inactive Groups */
  $handler = $view->new_display('page', 'Inactive Groups', 'page_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Inactive Groups';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Flags: group_inactive */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'group_inactive';
  $handler->display->display_options['relationships']['flag_content_rel']['user_scope'] = 'any';
  /* Relationship: Flags: group_inactive counter */
  $handler->display->display_options['relationships']['flag_count_rel']['id'] = 'flag_count_rel';
  $handler->display->display_options['relationships']['flag_count_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_count_rel']['field'] = 'flag_count_rel';
  $handler->display->display_options['relationships']['flag_count_rel']['flag'] = 'group_inactive';
  $handler->display->display_options['path'] = 'manage/inactive';

  /* Display: Favorited Groups */
  $handler = $view->new_display('page', 'Favorited Groups', 'page_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Favorite Groups';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Flags: bookmarks */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'bookmarks';
  /* Relationship: Flags: bookmarks counter */
  $handler->display->display_options['relationships']['flag_count_rel']['id'] = 'flag_count_rel';
  $handler->display->display_options['relationships']['flag_count_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_count_rel']['field'] = 'flag_count_rel';
  $handler->display->display_options['relationships']['flag_count_rel']['flag'] = 'bookmarks';
  $handler->display->display_options['path'] = 'manage/dashboard/favorites';
  $export['flagged_content'] = $view;

  return $export;
}
