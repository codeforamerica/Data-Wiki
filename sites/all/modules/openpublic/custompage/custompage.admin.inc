<?php
/**
 * @file custompage.admin.inc
 */


function custompage_settings() {
  $form = array();
  $form["custompage_inline_edit"] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable Inline Edit'),
    '#default_value' => variable_get("custompage_inline_edit", FALSE),
    '#description' => t('This will enable an edit link on each tile to the editor of the specific resource (view, menu, block, etc.)'),
  );

  $form["custompage_theme_prefix"] = array(
    '#type' => 'textfield',
    '#title' => t('Theme Prefix'),
    '#default_value' => variable_get("custompage_theme_prefix", ''),
    '#description' => t('Configures the prefix to use on tpl files and theme functions. This should only contain alpha-numeric characters and underscores (don\'t use hyphens). For example, if you specify <em>custompage</em>, then your theme function will be <em>custompage_key</em> and your template will be <em>custompage-key.tpl.php</em>.'),
  );

  return system_settings_form($form);
}
