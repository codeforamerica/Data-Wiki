<?php
/**
 * @file
 * web_resource.context.inc
 */

/**
 * Implementation of hook_context_default_contexts().
 */
function web_resource_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'Home';
  $context->description = '';
  $context->tag = '';
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
        'block-2' => array(
          'module' => 'block',
          'delta' => 2,
          'region' => 'content',
          'weight' => '-9',
        ),
        'views--exp-neighborhood-page' => array(
          'module' => 'views',
          'delta' => '-exp-neighborhood-page',
          'region' => 'content',
          'weight' => '-8',
        ),
        'block-3' => array(
          'module' => 'block',
          'delta' => 3,
          'region' => 'content',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['Home'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'Search';
  $context->description = '';
  $context->tag = 'search';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'search*' => 'search*',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('search');
  $export['Search'] = $context;

  return $export;
}
