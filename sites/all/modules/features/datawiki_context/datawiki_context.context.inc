<?php
/**
 * @file
 * datawiki_context.context.inc
 */

/**
 * Implementation of hook_context_default_contexts().
 */
function datawiki_context_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'citygroups_home';
  $context->description = '';
  $context->tag = 'datawiki';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'citygroups_sub-citygroups_sub_facebook_like' => array(
          'module' => 'citygroups_sub',
          'delta' => 'citygroups_sub_facebook_like',
          'region' => 'sidebar_second',
          'weight' => '-33',
        ),
        'citygroups_sub-citygroups_sub_projects' => array(
          'module' => 'citygroups_sub',
          'delta' => 'citygroups_sub_projects',
          'region' => 'sidebar_second',
          'weight' => '-32',
        ),
        'datawiki-datawiki_welcome' => array(
          'module' => 'datawiki',
          'delta' => 'datawiki_welcome',
          'region' => 'content_bottom',
          'weight' => '-10',
        ),
        'datawiki-datawiki_home_menu' => array(
          'module' => 'datawiki',
          'delta' => 'datawiki_home_menu',
          'region' => 'content_bottom',
          'weight' => '-9',
        ),
        'datawiki-datawiki_add_data' => array(
          'module' => 'datawiki',
          'delta' => 'datawiki_add_data',
          'region' => 'content_bottom',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('datawiki');
  $export['citygroups_home'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'datawiki_main';
  $context->description = '';
  $context->tag = 'datawiki';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
        'map' => 'map',
        'list' => 'list',
        'about' => 'about',
        'contact' => 'contact',
        'topics' => 'topics',
        'get-involved' => 'get-involved',
        'community-data-api' => 'community-data-api',
        'node/add/community-group' => 'node/add/community-group',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'search-form' => array(
          'module' => 'search',
          'delta' => 'form',
          'region' => 'header_gap',
          'weight' => '-10',
        ),
        'datawiki-datawiki_header_menu' => array(
          'module' => 'datawiki',
          'delta' => 'datawiki_header_menu',
          'region' => 'preface',
          'weight' => '-10',
        ),
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-10',
        ),
        'datawiki-datawiki_navigation_menu' => array(
          'module' => 'datawiki',
          'delta' => 'datawiki_navigation_menu',
          'region' => 'footer_top',
          'weight' => '-10',
        ),
        'datawiki-datawiki_branding_footer' => array(
          'module' => 'datawiki',
          'delta' => 'datawiki_branding_footer',
          'region' => 'footer_bottom',
          'weight' => '-10',
        ),
        'system-powered-by' => array(
          'module' => 'system',
          'delta' => 'powered-by',
          'region' => 'footer_bottom',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('datawiki');
  $export['datawiki_main'] = $context;

  return $export;
}
