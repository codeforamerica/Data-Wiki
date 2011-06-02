<?php

// @file relevance.admin.inc


/**
 * Copyleft (C) 2008 by Fernao Lopes
 * Author(s): Fernao Lopes
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY. See the LICENSE.txt file for more details.
 *
 **/


function relevance_settings_form() {

  // definition of variables
  $stats_enabled = module_exists('statistics');
  
  // Taxonomies
  $content_types = relevance_get_taxonomy();
  
  // help
  $form[] = array(
    '#type' => 'fieldset',
    '#title' => t('how to configure relevance'),
    '#description' => t('For each content type, you can configure it\'s taxonomy relevance factors, date and statistics.')
  );
  
  // for each content, list the fields and enable 
  foreach ($content_types as $content_type => $content_fields) {
    
    $default_ratio = relevance_get_settings('taxonomy', $content_types);
    
    $form[$content_type] = array(
      '#type' => 'fieldset',
      '#title' => t('Content type: ') . $content_type,
      '#description' => t('Configurations for this content type. You should enable a taxonomy term for a content type and then set it\'s multiplier relevance factor. Values: 1-9. <p><em>NOTE: When the vocabularies are enabled, the content is filtered by those content that has at least one of the terms. So, any content that has no term of an enabled vocalubary would not show any related link.</em></p>'),
      '#collapsible' => false,
      '#collapsed' => FALSE,
    );
    
    $form[$content_type]['taxonomy'] = array(
      '#type' => 'item',
      '#title' => t('Taxonomy'),
      '#description' => '',
    );
    
    $form[$content_type]['table_init'] = array(
      '#prefix' => '<table class="config_relevance">',
    );    
    $form[$content_type]['table_head'] = array(
      '#prefix' => '<tr><th class="th_1">' . t('Field') . '</th><th>' . t('Relevance') . '</th></tr>',
    );    
    
    foreach ($content_fields as $field) {
      
      $field_obj = field_info_instance('node', $field, $content_type);
      
      // forms
      $form[$content_type]['table_rw_init_' . $field] = array(
        '#prefix' => '<tr>',
      );
      
      $form[$content_type]['relevance_' . $content_type . '_tax_' . $field . '_enabled'] = array(
        '#type' => 'checkbox',
	'#title' => $field_obj['label'],
	'#prefix' => '<td class="td_1">',
	'#suffix' => '</td>',
        '#default_value' => $default_ratio['relevance_' . $content_type . '_tax_' . $field . '_enabled'],
      );
      
      $form[$content_type]['relevance_' . $content_type . '_tax_' . $field . '_ratio'] = array(
        '#type' => 'textfield',
        '#size' => 1,
        '#maxlength' => 3,
	'#prefix' => '<td class="td_2">',
	'#suffix' => '</td>',
        '#default_value' => $default_ratio['relevance_' . $content_type . '_tax_' . $field . '_ratio'],
      );

      $form[$content_type]['table_rw_end_' . $field] = array(
        '#suffix' => '</tr>',
      );
    }
    
    $form[$content_type]['table_end'] = array(
      '#suffix' => '</table>',
    );
    
    // stats  
    if ($stats_enabled) {
      $default_stats = relevance_get_settings('stats', $content_types);
      
      $form[$content_type]['stats_table_init'] = array(
        '#prefix' => '<table class="config_relevance">',
      );    
      
      $form[$content_type]['stats_table_head'] = array(
        '#prefix' => '<tr><th class="th_1">' . t('Configuration') . '</th><th>' . t('Relevance') . '</th></tr>',
      );
      
      $form[$content_type]['stats'] = array(
        '#type' => 'item',
	'#title' => t('Statistics'),
	'#description' => t('Configuration for statistics for this content type.'),
      );
      
      $form[$content_type]['relevance_' . $content_type . '_stats_enabled'] = array(
        '#type' => 'checkbox',
	'#title' => t('Enable statistics'),
 	'#default_value' => $default_stats['relevance_' . $content_type . '_stats_enabled'],
        '#prefix' => '<td class="td_1">',
        '#suffix' => '</td>',
      );

      $form[$content_type]['relevance_' . $content_type . '_stats_ratio'] = array(
        '#type' => 'textfield',
	'#size' => 1,
	'#maxlength' => 1,
	'#default_value' => $default_stats['relevance_' . $content_type . '_stats_ratio'],
        '#prefix' => '<td class="td_2">',
        '#suffix' => '</td>',
      );

      $form[$content_type]['stat_table_rw_end'] = array(
        '#suffix' => '</tr>',
      );

      $form[$content_type]['stat_table_end'] = array(
        '#suffix' => '</table>',
      );

    } else {
      // if statistics is not enabled
      $form[$content_type]['stat'] = array(
        '#type' => 'item',
	'#title' => t('Statistics'),
	'#description' => t('The module statistics is not enabled. If you want to use statistics for generating relevance, please !link.', array('!link' => l('enabled the module', 'admin/modules', array('fragment' => 'edit-modules-core-statistics-enablecs', 'html' => TRUE)))),
      );
    }
    
    
    // Dates
    $form[$content_type]['date_title'] = array(
      '#type' => 'item',
      '#title' => t('Dates'),
      '#description' => t('Configuration for periods. You should enable the granularity of it, by setting different periods of time and their importance, by the setting factor (1-9).'),
    );

    $form[$content_type]['date_table_init'] = array(
      '#prefix' => '<table class="config_relevance">',
    );    
    $form[$content_type]['date_table_head'] = array(
      '#prefix' => '<tr><th class="th_1">' . t('Period') . '</th><th>' . t('Relevance') . '</th></tr>',
    );
    
    $dates = relevance_get_settings('date', $content_types);
    
    foreach ($dates as $period => $date_values) {
      
      // forms
      $form[$content_type]['date_table_rw_init_' . $period] = array(
        '#prefix' => '<tr>',
      );
      
      $form[$content_type]['relevance_' . $content_type . '_date_' . $period . '_enabled'] = array(
        '#type' => 'checkbox',
	'#title' => $period,
	'#default_value' => $date_values['relevance_' . $content_type . '_date_' . $period . '_enabled'],
	'#prefix' => '<td class="td_1">',
	'#suffix' => '</td>',
      );
      
      $form[$content_type]['relevance_' . $content_type . '_date_' . $period . '_ratio'] = array(
        '#type' => 'textfield',
	'#size' => 1,
        '#maxlength' => 1,
	'#default_value' => $date_values['relevance_' . $content_type . '_date_' . $period . '_ratio'],
	'#prefix' => '<td class="td_2">',
	'#suffix' => '</td>',
      );
      
      $form[$content_type]['date']['table_rw_end_' . $period] = array(
        '#suffix' => '</tr>',
      );
    }

    $form[$content_type]['date_table_end'] = array(
      '#suffix' => '</table>',
    );
    
    
    // Exclude list 
    $values_exclude = relevance_get_settings('exclude', $content_types);
    
    $form[$content_type]['exclude'] = array(
      '#type' => 'item',
      '#title' => t('Exclude List'),
      '#description' => t('You can exclude specific pages, that you not appear in the related terms.'),
    );
    
    $form[$content_type]['relevance_' . $content_type . '_exclude_list'] = array(
      '#type' => 'textarea',
      '#title' => t('Nodes to be excluded:'),
      '#description' => t('One node per line, without commas. For example: \'node/300\'.'),
      '#cols' => 60,
      '#rows' => 3,
      '#default_value' => $values_exclude['relevance_' . $content_type . '_exclude_list'],
    );
    
    
    // Display
    $values_display = relevance_get_settings('display', $content_types);
    $form[$content_type]['display'] = array(
      '#type' => 'item',
      '#title' => t('Display options'),
      '#description' => t('General options for display'),
    );

    $form[$content_type]['relevance_' . $content_type . '_display_itens_to_show'] = array(
      '#type' => 'textfield',
      '#title' => t('Itens to show:'),
      '#size' => 1,
      '#maxlength' => 2,
      '#description' => t('1 to 10'),
      '#default_value' => $values_display['relevance_' . $content_type . '_display_itens_to_show'],
    );
    
    $form[$content_type]['relevance_' . $content_type . '_display_score'] = array(
      '#type' => 'checkbox',
      '#title' => t('Display relevance score'),
      '#default_value' => $values_display['relevance_' . $content_type . '_display_score'],
    );
    
    $form[$content_type]['relevance_' . $content_type . '_display_timer'] = array(
      '#type' => 'checkbox',
      '#title' => t('Display a timer to check the performance of your relevance settings.'),
      '#default_value' => $values_display['relevance_' . $content_type . '_display_timer'],
    );

  }
  
  
  return system_settings_form($form);
}

/**
 * Form validator
 */
function relevance_settings_form_validate($form, $form_state) {
  
  $content_types = relevance_get_taxonomy();
  foreach ($content_types as $content_type => $content_fields) {
    foreach ($content_fields as $field) {
      $form_field = $form_state['values']['relevance_' . $content_type . '_tax_' . $field . '_ratio'];
      
      if (intval($form_field) > 9 || intval($form_field) < 1) {
        form_set_error('relevance_' . $content_type . '_tax_' . $field . '_ratio', t('Enter a value between 1 and 9'));
      }
    }            
  }
}
