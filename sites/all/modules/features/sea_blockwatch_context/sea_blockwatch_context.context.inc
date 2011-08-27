<?php
/**
 * @file
 * sea_blockwatch_context.context.inc
 */

/**
 * Implementation of hook_context_default_contexts().
 */
function sea_blockwatch_context_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sea_blockwatch_home';
  $context->description = '';
  $context->tag = 'citygroups';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'blockwatch' => 'blockwatch',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'sea_blockwatch-sea_blockwatch_welcome' => array(
          'module' => 'sea_blockwatch',
          'delta' => 'sea_blockwatch_welcome',
          'region' => 'content_top',
          'weight' => '-10',
        ),
        'sea_blockwatch-sea_blockwatch_home_content' => array(
          'module' => 'sea_blockwatch',
          'delta' => 'sea_blockwatch_home_content',
          'region' => 'content',
          'weight' => '-10',
        ),
        'sea_blockwatch-sea_blockwatch_about' => array(
          'module' => 'sea_blockwatch',
          'delta' => 'sea_blockwatch_about',
          'region' => 'postscript',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('citygroups');
  $export['sea_blockwatch_home'] = $context;

  return $export;
}
