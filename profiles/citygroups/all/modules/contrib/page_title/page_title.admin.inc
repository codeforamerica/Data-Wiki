<?php
// $Id: page_title.admin.inc,v 1.4.4.5 2010/11/01 23:30:32 njt1982 Exp $

/**
 * @file
 * Admin include file.
 */

/**
 * Displays the form for the standard settings tab.
 *
 * @return
 *   array A structured array for use with Forms API.
 */
function page_title_admin_settings() {
  // Set the page title - the page is a local task now.
  drupal_set_title(t('Page titles'));

  // Define a default looking 'form element' for setting.
  $showfield_form_element = array('#type' => 'checkbox', '#title_display' => 'invisible');


  // Define a default looking 'form element' for setting.
  $pattern_form_element = array(
    '#type' => 'textfield',
    '#size' => 60,
    '#maxlength' => 256,
    '#element_validate' => array('token_element_validate_token_context'),
    '#token_types' => array(),
  );


  // Define the basic scope column values
  $form['patterns']['scope'] = array(
    'page_title_default'             => array('#markup' => t('Global'),),
    'page_title_front'               => array('#markup' => t('Global'),),
    'page_title_comment_reply'       => array('#markup' => t('Node'), ),
    'page_title_comment_child_reply' => array('#markup' => t('Node') .'<br />'. t('Comment'), ),
    'page_title_pager_pattern'       => array('#markup' => t('Global'), ),
    'page_title_user'                => array('#markup' => t('User'),),
  );


  // Define the 'default' token patterns
  $form['patterns']['pattern'] = array(
    //Define the default pattern - this is a "fallback" pattern.
    'page_title_default' => array(
      '#title' => t('Default'),
      '#default_value' => variable_get('page_title_default', '[current-page:page-title] | [site:name]'),
      '#description' => t('This pattern will be used as a <em>fallback</em> (ie, when no other pattern is defined)'),
      '#required' => TRUE,
    ) + $pattern_form_element,

    // Define the frontpage pattern. This is use on <front>
    'page_title_front' => array(
      '#title' => t('Frontpage'),
      '#default_value' => variable_get('page_title_front', '[site:name] | [site:slogan]'),
      '#description' => t('This pattern will be used for the site frontpage'),
    ) + $pattern_form_element,

    // Define the pager pattern. This is appended to any page requests containing 'page=[0-9]+' in the query string
    'page_title_pager_pattern' => array(
      '#title' => t('Pager Suffix'),
      '#default_value' => variable_get('page_title_pager_pattern', ''),
      '#description' => t('This pattern will be appended to a page title for any given page with a pager on it'),
    ) + $pattern_form_element,

    // Define the comment reply pattern. This is used for a root comment reply (ie comment/[0-9]+).
    'page_title_comment_reply' => array(
      '#title' => t('Comment Reply'),
      '#default_value' => variable_get('page_title_comment_reply', ''),
      '#description' => t('This pattern will be used for comment reply pages, where the reply is directly to a "node"'),
      '#token_types' => array('node'),
    ) + $pattern_form_element,

    // Define the comment reply to comment pattern. This is used for a reply to a comment (ie comment/[0-9]+/[0-9]+).
    'page_title_comment_child_reply' => array(
      '#title' => t('Comment Child Reply'),
      '#default_value' => variable_get('page_title_comment_child_reply', ''),
      '#description' => t('This pattern with be used for comment reply pages where the reply is to an existing "comment" (eg a comment thread)'),
      '#token_types' => array('comment'),
    ) + $pattern_form_element,

    // Define the user profile page pattern. This is used on any 'user/[0-9]' pages
    'page_title_user' => array(
      '#title' => t('User Profile'),
      '#default_value' => variable_get('page_title_user', ''),
      '#description' => t('This pattern will be used for any user profile pages'),
      '#token_types' => array('user'),
    ) + $pattern_form_element,
  );


  // Define the "showfield" checkbox for the user profile page
  $form['patterns']['showfield']['page_title_user_showfield'] = array(
    '#title' => t('Show page title field on User Profile edit form'),
    '#default_value' => variable_get('page_title_user_showfield', 0),
  ) + $showfield_form_element;


  // Definate the patterns per-node-type
  $types = node_type_get_types();
  foreach ($types as $type) {
    // Define the node-type key
    $key = 'page_title_type_'. $type->type;

    // Pattern entry
    $form['patterns']['pattern'][$key] = array(
      '#title' => t('Content Type - %type', array('%type' => $type->name)),
      '#default_value' => variable_get($key, ''),
      '#description' => t('This pattern will be used for all %type node-type pages', array('%type' => $type->name)),
      '#token_types' => array('node'),
    ) + $pattern_form_element;

    $form['patterns']['showfield'][$key .'_showfield'] = array(
      '#title' => t('Show page title field on the %type edit form', array('%type' => $type->name)),
      '#default_value' => variable_get($key .'_showfield', 0),
    ) + $showfield_form_element;

    $form['patterns']['scope'][$key] = array('#markup' => t('Node'),);
  }


  // Definate the patterns per-vocab-type - if Taxonomy Module is enabled
  if (module_exists('taxonomy')) {
    $vocabs = taxonomy_get_vocabularies();
    foreach ($vocabs as $vocab) {
      // Define the vocab key
      $key = 'page_title_vocab_'. $vocab->vid;

      // Pattern entry
      $form['patterns']['pattern'][$key] = array(
        '#title' => t('Vocabulary - %vocab_name', array('%vocab_name' => $vocab->name)),
        '#default_value' => variable_get($key, ''),
        '#description' => t('This pattern will be used for all %title term pages', array('%title' => $vocab->name)),
        '#token_types' => array('term'),
      ) + $pattern_form_element;

      $form['patterns']['showfield'][$key .'_showfield'] = array(
        '#title' => t('Show page title field on the %vocab_name term edit form', array('%vocab_name' => $vocab->name)),
        '#default_value' => variable_get($key .'_showfield', 0),
      ) + $showfield_form_element;

      $form['patterns']['scope'][$key] = array('#markup' => t('Taxonomy'),);
    }
  }


  // Add the blog homepage pattern field
  if (module_exists('blog')) {
    $key = 'page_title_blog';
    $form['patterns']['pattern'][$key] = array(
      '#title' => t('Blog Homepage'),
      '#default_value' => variable_get($key, ''),
    ) + $pattern_form_element;

    $form['patterns']['scope'][$key] = array('#markup' => t('User'),);
  }


  // Add the forum root pattern field
  if (module_exists('forum')) {
    $form['patterns']['pattern']['page_title_forum_root_title'] = array(
      '#title' => t('Forum Root'),
      '#default_value' => variable_get('page_title_forum_root_title', ''),
      '#description' => t('This pattern will be used on the forum root page (ie, <code>/forum</code>)'),
      '#token_types' => array('user'),
    ) + $pattern_form_element;
    $form['patterns']['scope']['page_title_forum_root_title'] = array('#type' => 'markup', '#value' => t('Global'));
  }


  // Add the token help to a collapsed fieldset at the end of the configuration page.
  $form['token_help'] = array(
    '#type' => 'fieldset',
    '#title' => t('Available Tokens List'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['token_help']['content'] = array(
    '#theme' => 'token_tree',
    '#token_types' => array('node', 'comment', 'term', 'user'),
  );


  $form = system_settings_form($form);
  unset($form['#theme']);
  return $form;
}


function theme_page_title_admin_settings($variables) {
  $form = $variables['form'];
  $rows = array();
  foreach (element_children($form['patterns']['pattern']) as $key) {
    $title = array(
      '#markup' => $form['patterns']['pattern'][$key]['#title'],
      '#required' => $form['patterns']['pattern'][$key]['#required'],
    );
    unset($form['patterns']['pattern'][$key]['#title']);
    $row = array(
      array('data' => render($title), 'class' => 'page-type'),
      array('data' => render($form['patterns']['scope'][$key]), 'class' => 'scope'),
    );

    if (isset($form['patterns']['showfield'][$key .'_showfield'])) {
      $row[] = array('data' => render($form['patterns']['pattern'][$key]), 'class' => 'pattern');
      $row[] = array('data' => render($form['patterns']['showfield'][$key .'_showfield']), 'class' => 'showfield');
    }
    else {
      $row[] = array('data' => render($form['patterns']['pattern'][$key]), 'colspan' => 2, 'class' => 'pattern');
    }
    $rows[] = $row;
  }

  $output  = theme('table', array('header' => array(t('Page Type'), t('Token Scope'), t('Pattern'), t('Show Field')), 'rows' => $rows));
  $output .= drupal_render_children($form);
  return $output;
}
