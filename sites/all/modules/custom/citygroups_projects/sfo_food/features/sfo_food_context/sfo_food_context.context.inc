<?php
/**
 * @file
 * sfo_food_context.context.inc
 */

/**
 * Implementation of hook_context_default_contexts().
 */
function sfo_food_context_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sfo_food_home';
  $context->description = '';
  $context->tag = 'citygroups';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'food' => 'food',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'sfo_food-sfo_food_welcome' => array(
          'module' => 'sfo_food',
          'delta' => 'sfo_food_welcome',
          'region' => 'content_top',
          'weight' => '-10',
        ),
        'sfo_food-sfo_food_home_content' => array(
          'module' => 'sfo_food',
          'delta' => 'sfo_food_home_content',
          'region' => 'content',
          'weight' => '-10',
        ),
        'sfo_food-sfo_food_about' => array(
          'module' => 'sfo_food',
          'delta' => 'sfo_food_about',
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
  $export['sfo_food_home'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sfo_food_main';
  $context->description = '';
  $context->tag = 'citygroups';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'food/*' => 'food/*',
        'node/add/community-group?section=food' => 'node/add/community-group?section=food',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'sfo_food-sfo_food_about' => array(
          'module' => 'sfo_food',
          'delta' => 'sfo_food_about',
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
  $export['sfo_food_main'] = $context;

  return $export;
}
