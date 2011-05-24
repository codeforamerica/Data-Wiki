<?php
/**
 * @file
 * datawiki_resources.context.inc
 */

/**
 * Implementation of hook_context_default_contexts().
 */
function datawiki_resources_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'All Pages';
  $context->description = '';
  $context->tag = '';
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
        'search-form' => array(
          'module' => 'search',
          'delta' => 'form',
          'region' => 'header_gap',
          'weight' => '-10',
        ),
        'system-main-menu' => array(
          'module' => 'system',
          'delta' => 'main-menu',
          'region' => 'footer',
          'weight' => '-17',
        ),
        'datawiki_blocks-datawiki_branding_footer' => array(
          'module' => 'datawiki_blocks',
          'delta' => 'datawiki_branding_footer',
          'region' => 'footer',
          'weight' => '-16',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['All Pages'] = $context;

  return $export;
}
