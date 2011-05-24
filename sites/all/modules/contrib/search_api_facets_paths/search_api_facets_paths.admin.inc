<?php
/**
 * @file
 * Settings form for Pretty paths
 *
 * (C)2011 Michael Moritz miiimooo/at/drupal.org
 */
function search_api_facets_paths_settings_form($form, &$form_state) {

  $form['search_api_facets_paths'] = array(
    '#type' => 'fieldset',
    '#collapsible' => FALSE,
    '#tree' => TRUE,
    '#title' => t('Contexts'),
    '#description' => t('Facets Paths Rewriting is like Clean URLs for Search API
    facets. The rewriting replaces the filter fragments (<em>filter[field_name]=
    "Taxonomy term name"</em>) with clean, SEO and user friendly paths. Currently,
    this works for <strong>taxonomy term names</strong>.
     The idea of facets paths started in <a href="@url">
      this Drupal.org discussion thread</a>.', array("@url" => url("http://drupal.org/node/1025402"))),
  );
  $contexts = variable_get('search_api_facets_paths', array());
  $pathtypes = module_invoke_all('search_api_facets_paths_pathtypes');
  $contexts[] = array('path' => '', 'pathtype' => '');
  foreach($contexts as $idx => $context) {
    $form['search_api_facets_paths'][$idx] = array(
      '#type' => 'fieldset',
      '#title' => t('Context #@idx', array('@idx' => $idx))
    );
    $form['search_api_facets_paths'][$idx]['path'] = array(
      '#type' => 'textfield',
      '#title' => t('Path'),
      '#default_value' => $context['path'],
      '#description' => 'The path (usually the base path of a view) where the
        path rewriting will take place. Leave empty to delete.',
    );
    $form['search_api_facets_paths'][$idx]['pathtype'] = array(
      '#type' => 'select',
      '#title' => 'Pathtype',
      '#default_value' => $context['pathtype'],
      '#options' => $pathtypes,
      '#description' => t('The way paths are being rewritten. For instance,
        <em>vocabulary-name/term-name</em> means that vocabulary and term names
        will be converted to lower case and spaces replaced with hyphens.<br />
        Multiple facets will be connected with forward slashes.<br />
        Other modules may implement their own pathtypes. In order to be
        available to the user here they need to implement <em>hook_search_api_facets_paths_pathtypes</em>.'),
    );
  }
  $form['#submit'][] = 'search_api_facets_paths_settings_form_submit';
  return system_settings_form($form);
}
function search_api_facets_paths_settings_form_submit($form, &$form_state) {
  foreach($form_state['values']['search_api_facets_paths'] as $key => $v) {
    $path = trim($v['path']);
    if (strlen($path) == 0 ) {
      unset($form_state['values']['search_api_facets_paths'][$key]);
    }
  }
}
