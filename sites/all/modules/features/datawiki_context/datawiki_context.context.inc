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
        'datawiki_blocks-datawiki_branding_header' => array(
          'module' => 'datawiki_blocks',
          'delta' => 'datawiki_branding_header',
          'region' => 'header_top',
          'weight' => '-10',
        ),
        'logintoboggan-logintoboggan_logged_in' => array(
          'module' => 'logintoboggan',
          'delta' => 'logintoboggan_logged_in',
          'region' => 'header_signin',
          'weight' => '-10',
        ),
        'datawiki_blocks-datawiki_facebook_like' => array(
          'module' => 'datawiki_blocks',
          'delta' => 'datawiki_facebook_like',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'datawiki_blocks-datawiki_welcome' => array(
          'module' => 'datawiki_blocks',
          'delta' => 'datawiki_welcome',
          'region' => 'content_bottom',
          'weight' => '-10',
        ),
        'datawiki_blocks-datawiki_home_menu' => array(
          'module' => 'datawiki_blocks',
          'delta' => 'datawiki_home_menu',
          'region' => 'content_bottom',
          'weight' => '-9',
        ),
        'datawiki_blocks-datawiki_add_data' => array(
          'module' => 'datawiki_blocks',
          'delta' => 'datawiki_add_data',
          'region' => 'content_bottom',
          'weight' => '-7',
        ),
        'datawiki_collection-datawiki_branding_footer' => array(
          'module' => 'datawiki_collection',
          'delta' => 'datawiki_branding_footer',
          'region' => 'footer_bottom',
          'weight' => '-10',
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
        '*' => '*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'system-main-menu' => array(
          'module' => 'system',
          'delta' => 'main-menu',
          'region' => 'header_menu',
          'weight' => '-10',
        ),
        'search-form' => array(
          'module' => 'search',
          'delta' => 'form',
          'region' => 'header_gap',
          'weight' => '-10',
        ),
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-10',
        ),
        'system-navigation' => array(
          'module' => 'system',
          'delta' => 'navigation',
          'region' => 'footer_top',
          'weight' => '-10',
        ),
        'system-powered-by' => array(
          'module' => 'system',
          'delta' => 'powered-by',
          'region' => 'footer_bottom',
          'weight' => '-10',
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
