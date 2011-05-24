<?php
/**
 * @file
 * datawiki_community_groups.context.inc
 */

/**
 * Implementation of hook_context_default_contexts().
 */
function datawiki_community_groups_context_default_contexts() {
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
        'datawiki_blocks-datawiki_welcome' => array(
          'module' => 'datawiki_blocks',
          'delta' => 'datawiki_welcome',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views--exp-neighborhood-page' => array(
          'module' => 'views',
          'delta' => '-exp-neighborhood-page',
          'region' => 'content',
          'weight' => '-9',
        ),
        'datawiki_blocks-datawiki_add_data' => array(
          'module' => 'datawiki_blocks',
          'delta' => 'datawiki_add_data',
          'region' => 'content',
          'weight' => '-8',
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
