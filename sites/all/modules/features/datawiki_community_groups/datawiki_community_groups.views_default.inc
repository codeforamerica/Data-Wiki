<?php
/**
 * @file
 * datawiki_community_groups.views_default.inc
 */

/**
 * Implementation of hook_views_default_views().
 */
function datawiki_community_groups_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'all_groups';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'All Groups';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'All Groups';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_text'] = 'See All';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: URL */
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
  /* Field: Content: Email */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'field_data_field_email';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_email']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_email']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_email']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_email']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_email']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_email']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_email']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_email']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_email']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_email']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_email']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_email']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_email']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_email']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_email']['click_sort_column'] = 'email';
  $handler->display->display_options['fields']['field_email']['type'] = 'email_default';
  $handler->display->display_options['fields']['field_email']['field_api_classes'] = 0;
  /* Field: Content: Updated/commented date */
  $handler->display->display_options['fields']['last_updated']['id'] = 'last_updated';
  $handler->display->display_options['fields']['last_updated']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['last_updated']['field'] = 'last_updated';
  $handler->display->display_options['fields']['last_updated']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['last_updated']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['last_updated']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['last_updated']['alter']['external'] = 0;
  $handler->display->display_options['fields']['last_updated']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['last_updated']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['last_updated']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['last_updated']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['last_updated']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['last_updated']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['last_updated']['alter']['html'] = 0;
  $handler->display->display_options['fields']['last_updated']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['last_updated']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['last_updated']['hide_empty'] = 0;
  $handler->display->display_options['fields']['last_updated']['empty_zero'] = 0;
  $handler->display->display_options['fields']['last_updated']['date_format'] = 'long';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
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
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['edit_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['edit_node']['empty_zero'] = 0;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['link_to_user'] = 1;
  $handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
  /* Sort criterion: Content: Updated/commented date */
  $handler->display->display_options['sorts']['last_updated']['id'] = 'last_updated';
  $handler->display->display_options['sorts']['last_updated']['table'] = 'node_comment_statistics';
  $handler->display->display_options['sorts']['last_updated']['field'] = 'last_updated';
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
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Content: Type';
  $handler->display->display_options['filters']['type']['expose']['use_operator'] = FALSE;
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['required'] = FALSE;
  $handler->display->display_options['filters']['type']['expose']['remember'] = FALSE;
  $handler->display->display_options['filters']['type']['expose']['multiple'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_url' => 'field_url',
    'field_email' => 'field_email',
    'last_updated' => 'last_updated',
    'edit_node' => 'edit_node',
    'name' => 'name',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_url' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_email' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'last_updated' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
    ),
    'name' => array(
      'sortable' => 0,
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
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: URL */
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
  /* Field: Content: Email */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'field_data_field_email';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_email']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_email']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_email']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_email']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_email']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_email']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_email']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_email']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_email']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_email']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_email']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_email']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_email']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_email']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_email']['click_sort_column'] = 'email';
  $handler->display->display_options['fields']['field_email']['type'] = 'email_default';
  $handler->display->display_options['fields']['field_email']['field_api_classes'] = 0;
  /* Field: Content: Updated/commented date */
  $handler->display->display_options['fields']['last_updated']['id'] = 'last_updated';
  $handler->display->display_options['fields']['last_updated']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['last_updated']['field'] = 'last_updated';
  $handler->display->display_options['fields']['last_updated']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['last_updated']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['last_updated']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['last_updated']['alter']['external'] = 0;
  $handler->display->display_options['fields']['last_updated']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['last_updated']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['last_updated']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['last_updated']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['last_updated']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['last_updated']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['last_updated']['alter']['html'] = 0;
  $handler->display->display_options['fields']['last_updated']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['last_updated']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['last_updated']['hide_empty'] = 0;
  $handler->display->display_options['fields']['last_updated']['empty_zero'] = 0;
  $handler->display->display_options['fields']['last_updated']['date_format'] = 'long';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
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
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['edit_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['edit_node']['empty_zero'] = 0;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Added By';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['link_to_user'] = 1;
  $handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Updated/commented date */
  $handler->display->display_options['sorts']['last_updated']['id'] = 'last_updated';
  $handler->display->display_options['sorts']['last_updated']['table'] = 'node_comment_statistics';
  $handler->display->display_options['sorts']['last_updated']['field'] = 'last_updated';
  $handler->display->display_options['sorts']['last_updated']['order'] = 'DESC';
  /* Sort criterion: Fields: URL (field_url) - url */
  $handler->display->display_options['sorts']['field_url_url']['id'] = 'field_url_url';
  $handler->display->display_options['sorts']['field_url_url']['table'] = 'field_data_field_url';
  $handler->display->display_options['sorts']['field_url_url']['field'] = 'field_url_url';
  $handler->display->display_options['sorts']['field_url_url']['expose']['label'] = 'URL';
  /* Sort criterion: Fields: Email (field_email) - email */
  $handler->display->display_options['sorts']['field_email_email']['id'] = 'field_email_email';
  $handler->display->display_options['sorts']['field_email_email']['table'] = 'field_data_field_email';
  $handler->display->display_options['sorts']['field_email_email']['field'] = 'field_email_email';
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Content: Type';
  $handler->display->display_options['filters']['type']['expose']['use_operator'] = FALSE;
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['required'] = FALSE;
  $handler->display->display_options['filters']['type']['expose']['remember'] = FALSE;
  $handler->display->display_options['filters']['type']['expose']['multiple'] = FALSE;
  $handler->display->display_options['path'] = 'groups/all';

  /* Display: Recently Added */
  $handler = $view->new_display('block', 'Recently Added', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Recently Added';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Total Number Results */
  $handler->display->display_options['header']['views_number_results']['id'] = 'views_number_results';
  $handler->display->display_options['header']['views_number_results']['table'] = 'views';
  $handler->display->display_options['header']['views_number_results']['field'] = 'views_number_results';
  $handler->display->display_options['header']['views_number_results']['label'] = 'Number of Groups';
  $handler->display->display_options['header']['views_number_results']['empty'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  $handler->display->display_options['block_description'] = 'Recently Added Groups';

  /* Display: CSV */
  $handler = $view->new_display('page', 'CSV', 'page_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_url' => 'field_url',
    'field_email' => 'field_email',
    'field_categories' => 'field_categories',
    'field_description' => 'field_description',
    'field_activity' => 'field_activity',
    'field_neighborhood' => 'field_neighborhood',
    'field_district' => 'field_district',
    'field_region' => 'field_region',
    'field_city' => 'field_city',
    'field_state' => 'field_state',
    'field_area_code' => 'field_area_code',
    'field_contact' => 'field_contact',
    'field_location' => 'field_location',
    'field_ownership' => 'field_ownership',
    'field_type_web_resource' => 'field_type_web_resource',
    'field_source' => 'field_source',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_url' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_email' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_categories' => array(
      'align' => '',
      'separator' => '',
    ),
    'field_description' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_activity' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_neighborhood' => array(
      'align' => '',
      'separator' => '',
    ),
    'field_district' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_region' => array(
      'align' => '',
      'separator' => '',
    ),
    'field_city' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_state' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_area_code' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_contact' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_location' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_ownership' => array(
      'align' => '',
      'separator' => '',
    ),
    'field_type_web_resource' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_source' => array(
      'sortable' => 0,
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
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: URL */
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
  /* Field: Content: Email */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'field_data_field_email';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_email']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_email']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_email']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_email']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_email']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_email']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_email']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_email']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_email']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_email']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_email']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_email']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_email']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_email']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_email']['click_sort_column'] = 'email';
  $handler->display->display_options['fields']['field_email']['type'] = 'email_default';
  $handler->display->display_options['fields']['field_email']['field_api_classes'] = 0;
  /* Field: Content: Categories */
  $handler->display->display_options['fields']['field_categories']['id'] = 'field_categories';
  $handler->display->display_options['fields']['field_categories']['table'] = 'field_data_field_categories';
  $handler->display->display_options['fields']['field_categories']['field'] = 'field_categories';
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
  $handler->display->display_options['fields']['field_categories']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_categories']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_categories']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_categories']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_categories']['click_sort_column'] = 'tid';
  $handler->display->display_options['fields']['field_categories']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_categories']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_categories']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_categories']['field_api_classes'] = 0;
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_description']['id'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description']['field'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_description']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_description']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_description']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_description']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_description']['alter']['trim'] = 1;
  $handler->display->display_options['fields']['field_description']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_description']['alter']['max_length'] = '200';
  $handler->display->display_options['fields']['field_description']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_description']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_description']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_description']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_description']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_description']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_description']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_description']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_description']['field_api_classes'] = 0;
  /* Field: Content: Activity Level */
  $handler->display->display_options['fields']['field_activity']['id'] = 'field_activity';
  $handler->display->display_options['fields']['field_activity']['table'] = 'field_data_field_activity';
  $handler->display->display_options['fields']['field_activity']['field'] = 'field_activity';
  $handler->display->display_options['fields']['field_activity']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_activity']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_activity']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_activity']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_activity']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_activity']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_activity']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_activity']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_activity']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_activity']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_activity']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_activity']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_activity']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_activity']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_activity']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_activity']['click_sort_column'] = 'tid';
  $handler->display->display_options['fields']['field_activity']['field_api_classes'] = 0;
  /* Field: Content: Neighborhood */
  $handler->display->display_options['fields']['field_neighborhood']['id'] = 'field_neighborhood';
  $handler->display->display_options['fields']['field_neighborhood']['table'] = 'field_data_field_neighborhood';
  $handler->display->display_options['fields']['field_neighborhood']['field'] = 'field_neighborhood';
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
  $handler->display->display_options['fields']['field_neighborhood']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_neighborhood']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_neighborhood']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_neighborhood']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_neighborhood']['click_sort_column'] = 'tid';
  $handler->display->display_options['fields']['field_neighborhood']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_neighborhood']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_neighborhood']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_neighborhood']['field_api_classes'] = 0;
  /* Field: Content: District */
  $handler->display->display_options['fields']['field_district']['id'] = 'field_district';
  $handler->display->display_options['fields']['field_district']['table'] = 'field_data_field_district';
  $handler->display->display_options['fields']['field_district']['field'] = 'field_district';
  $handler->display->display_options['fields']['field_district']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_district']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_district']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_district']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_district']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_district']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_district']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_district']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_district']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_district']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_district']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_district']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_district']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_district']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_district']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_district']['click_sort_column'] = 'tid';
  $handler->display->display_options['fields']['field_district']['field_api_classes'] = 0;
  /* Field: Content: Region */
  $handler->display->display_options['fields']['field_region']['id'] = 'field_region';
  $handler->display->display_options['fields']['field_region']['table'] = 'field_data_field_region';
  $handler->display->display_options['fields']['field_region']['field'] = 'field_region';
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
  $handler->display->display_options['fields']['field_region']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_region']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_region']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_region']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_region']['click_sort_column'] = 'tid';
  $handler->display->display_options['fields']['field_region']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_region']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_region']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_region']['field_api_classes'] = 0;
  /* Field: Content: City */
  $handler->display->display_options['fields']['field_city']['id'] = 'field_city';
  $handler->display->display_options['fields']['field_city']['table'] = 'field_data_field_city';
  $handler->display->display_options['fields']['field_city']['field'] = 'field_city';
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
  $handler->display->display_options['fields']['field_city']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_city']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_city']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_city']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_city']['click_sort_column'] = 'tid';
  $handler->display->display_options['fields']['field_city']['field_api_classes'] = 0;
  /* Field: Content: State */
  $handler->display->display_options['fields']['field_state']['id'] = 'field_state';
  $handler->display->display_options['fields']['field_state']['table'] = 'field_data_field_state';
  $handler->display->display_options['fields']['field_state']['field'] = 'field_state';
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
  $handler->display->display_options['fields']['field_state']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_state']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_state']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_state']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_state']['click_sort_column'] = 'tid';
  $handler->display->display_options['fields']['field_state']['field_api_classes'] = 0;
  /* Field: Content: Area Code */
  $handler->display->display_options['fields']['field_area_code']['id'] = 'field_area_code';
  $handler->display->display_options['fields']['field_area_code']['table'] = 'field_data_field_area_code';
  $handler->display->display_options['fields']['field_area_code']['field'] = 'field_area_code';
  $handler->display->display_options['fields']['field_area_code']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_area_code']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_area_code']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_area_code']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_area_code']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_area_code']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_area_code']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_area_code']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_area_code']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_area_code']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_area_code']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_area_code']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_area_code']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_area_code']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_area_code']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_area_code']['click_sort_column'] = 'tid';
  $handler->display->display_options['fields']['field_area_code']['field_api_classes'] = 0;
  /* Field: Content: Contact */
  $handler->display->display_options['fields']['field_contact']['id'] = 'field_contact';
  $handler->display->display_options['fields']['field_contact']['table'] = 'field_data_field_contact';
  $handler->display->display_options['fields']['field_contact']['field'] = 'field_contact';
  $handler->display->display_options['fields']['field_contact']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_contact']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_contact']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_contact']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_contact']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_contact']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_contact']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_contact']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_contact']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_contact']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_contact']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_contact']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_contact']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_contact']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_contact']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_contact']['field_api_classes'] = 0;
  /* Field: Fields: Location */
  $handler->display->display_options['fields']['field_location']['id'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['table'] = 'field_data_field_location';
  $handler->display->display_options['fields']['field_location']['field'] = 'field_location';
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
  $handler->display->display_options['fields']['field_location']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_location']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_location']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_location']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_location']['click_sort_column'] = 'wkt';
  $handler->display->display_options['fields']['field_location']['type'] = 'geofield_wkt';
  $handler->display->display_options['fields']['field_location']['field_api_classes'] = 0;
  /* Field: Content: Ownership */
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
  /* Field: Content: Type of Group */
  $handler->display->display_options['fields']['field_type_web_resource']['id'] = 'field_type_web_resource';
  $handler->display->display_options['fields']['field_type_web_resource']['table'] = 'field_data_field_type_web_resource';
  $handler->display->display_options['fields']['field_type_web_resource']['field'] = 'field_type_web_resource';
  $handler->display->display_options['fields']['field_type_web_resource']['label'] = 'Type';
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
  /* Field: Content: Source */
  $handler->display->display_options['fields']['field_source']['id'] = 'field_source';
  $handler->display->display_options['fields']['field_source']['table'] = 'field_data_field_source';
  $handler->display->display_options['fields']['field_source']['field'] = 'field_source';
  $handler->display->display_options['fields']['field_source']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_source']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_source']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_source']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_source']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_source']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_source']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_source']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_source']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_source']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_source']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_source']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_source']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_source']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_source']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_source']['field_api_classes'] = 0;
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['external'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['changed']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['changed']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['html'] = 0;
  $handler->display->display_options['fields']['changed']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['changed']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['changed']['hide_empty'] = 0;
  $handler->display->display_options['fields']['changed']['empty_zero'] = 0;
  $handler->display->display_options['fields']['changed']['date_format'] = 'long';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Added By';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['link_to_user'] = 1;
  $handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
  $handler->display->display_options['path'] = 'groups/all/csv';

  /* Display: GroupCounter */
  $handler = $view->new_display('block', 'GroupCounter', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Group Counter';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nothing']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing']['empty_zero'] = 0;
  /* Field: Global: Total Number Results */
  $handler->display->display_options['fields']['views_number_results']['id'] = 'views_number_results';
  $handler->display->display_options['fields']['views_number_results']['table'] = 'views';
  $handler->display->display_options['fields']['views_number_results']['field'] = 'views_number_results';
  $handler->display->display_options['fields']['views_number_results']['label'] = '';
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
  $handler->display->display_options['fields']['views_number_results']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['views_number_results']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['views_number_results']['hide_empty'] = 0;
  $handler->display->display_options['fields']['views_number_results']['empty_zero'] = 0;

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = FALSE;
  /* Header: Global: Total Number Results */
  $handler->display->display_options['header']['views_number_results']['id'] = 'views_number_results';
  $handler->display->display_options['header']['views_number_results']['table'] = 'views';
  $handler->display->display_options['header']['views_number_results']['field'] = 'views_number_results';
  $handler->display->display_options['header']['views_number_results']['empty'] = TRUE;
  $handler->display->display_options['path'] = 'groups/all/csv/export';
  $handler->display->display_options['displays'] = array(
    'page_1' => 'page_1',
    'default' => 0,
    'page' => 0,
    'block' => 0,
    'block_1' => 0,
  );

  /* Display: JSON */
  $handler = $view->new_display('page', 'JSON', 'page_2');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_json';
  $handler->display->display_options['style_options']['plaintext_output'] = 1;
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['path'] = 'groups/all/export/json';
  $translatables['all_groups'] = array(
    t('Master'),
    t('All Groups'),
    t('See All'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Title'),
    t('URL'),
    t('Email'),
    t('Updated/commented date'),
    t('Edit link'),
    t('Name'),
    t('Content: Type'),
    t('Page'),
    t('more'),
    t('Edit'),
    t('Added By'),
    t('Recently Added'),
    t('Number of Groups'),
    t('Recently Added Groups'),
    t('CSV'),
    t('Categories'),
    t('Description'),
    t('Activity Level'),
    t('Neighborhood'),
    t('District'),
    t('Region'),
    t('City'),
    t('State'),
    t('Area Code'),
    t('Contact'),
    t('Location'),
    t('Ownership'),
    t('Type'),
    t('Source'),
    t('Updated date'),
    t('GroupCounter'),
    t('Group Counter'),
    t('Data export'),
    t('JSON'),
  );
  $export['all_groups'] = $view;

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
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
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

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $translatables['categories'] = array(
    t('Master'),
    t('Categories'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Page'),
    t('Block'),
  );
  $export['categories'] = $view;

  $view = new view;
  $view->name = 'datawiki_community_groupss';
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
  /* Field: Content: Neighborhood */
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
  /* Field: Content: Region */
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
  /* Field: Content: State */
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
  /* Field: Content: City */
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
  /* Field: Content: URL */
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
  /* Field: Content: URL */
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
  /* Field: Content: Categories */
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
  /* Field: Content: Ownership */
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
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_type_datawiki_community_groups']['id'] = 'field_type_datawiki_community_groups';
  $handler->display->display_options['fields']['field_type_datawiki_community_groups']['table'] = 'field_data_field_type_datawiki_community_groups';
  $handler->display->display_options['fields']['field_type_datawiki_community_groups']['field'] = 'field_type_datawiki_community_groups';
  $handler->display->display_options['fields']['field_type_datawiki_community_groups']['label'] = '';
  $handler->display->display_options['fields']['field_type_datawiki_community_groups']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_type_datawiki_community_groups']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_type_datawiki_community_groups']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_type_datawiki_community_groups']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_type_datawiki_community_groups']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_type_datawiki_community_groups']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_type_datawiki_community_groups']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_type_datawiki_community_groups']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_type_datawiki_community_groups']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_type_datawiki_community_groups']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_type_datawiki_community_groups']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_type_datawiki_community_groups']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_type_datawiki_community_groups']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_type_datawiki_community_groups']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_type_datawiki_community_groups']['empty_zero'] = 0;
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
  $handler->display->display_options['style_options']['top_child_object'] = 'datawiki_community_groups';
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
  /* Field: Content: URL */
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
  /* Field: Content: Neighborhood */
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
  /* Field: Content: Region */
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
  /* Field: Content: City */
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
  /* Field: Content: State */
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
  /* Field: Content: Categories */
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
  /* Field: Content: Ownership */
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
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_type_datawiki_community_groups']['id'] = 'field_type_datawiki_community_groups';
  $handler->display->display_options['fields']['field_type_datawiki_community_groups']['table'] = 'field_data_field_type_datawiki_community_groups';
  $handler->display->display_options['fields']['field_type_datawiki_community_groups']['field'] = 'field_type_datawiki_community_groups';
  $handler->display->display_options['fields']['field_type_datawiki_community_groups']['label'] = 'type';
  $handler->display->display_options['fields']['field_type_datawiki_community_groups']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_type_datawiki_community_groups']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_type_datawiki_community_groups']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_type_datawiki_community_groups']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_type_datawiki_community_groups']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_type_datawiki_community_groups']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_type_datawiki_community_groups']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_type_datawiki_community_groups']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_type_datawiki_community_groups']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_type_datawiki_community_groups']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_type_datawiki_community_groups']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_type_datawiki_community_groups']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_type_datawiki_community_groups']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_type_datawiki_community_groups']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_type_datawiki_community_groups']['empty_zero'] = 0;
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
  $translatables['datawiki_community_groupss'] = array(
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
  $export['datawiki_community_groupss'] = $view;

  return $export;
}
