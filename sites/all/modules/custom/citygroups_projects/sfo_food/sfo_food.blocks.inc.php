<?php

/**
 * Implements hook_block_info().
 */
function sfo_food_block_info() {
  $blocks['sfo_food_welcome'] = array(
    'info' => t('Bay Area food: Welcome Message'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  $blocks['sfo_food_home_content'] = array(
    'info' => t('Bay Area food: Home Content'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  $blocks['sfo_food_about'] = array(
    'info' => t('Bay Area food: About'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  return $blocks;
}

/**
 * Implements hook_block_view().
 */
function sfo_food_block_view($delta = '') {
  switch ($delta) {
    case 'sfo_food_welcome':
      $block['subject'] = '';
      $block['content'] = sfo_food_contents('welcome');
      break; 

    case 'sfo_food_home_content':
      $block['subject'] = '';
      $block['content'] = sfo_food_contents('home_content');
      break;

    case 'sfo_food_about':
      $block['subject'] = '';
      $block['content'] = sfo_food_contents('about');
      break; 
  }
  return $block;
}

/**
 * Block placeholder content
 */
function sfo_food_contents($type) {
  $output = '';
  $add_variables = '?section=food&destination=food';
  // $add_variables = "?category=Block Watch, Crime Prevention&title=Add a Food System Group&instructions=List Food System Group or Block Watch Group.&map_instructions=Where is this Block Watch?";
    
  switch ($type) {
    case 'welcome':
      $output .= '<h4>' . variable_get('sfo_food_slogan') .'</h4>';
      $output .= '<p>' . variable_get('sfo_food_content_tagline') .'</p>';
      break;
      
      case 'home_content':
        $output .= "
          <div class=\"grid_16 sections\">
            <div class=\"grid_6 add-new-group section alpha\">"
              . variable_get('sfo_food_content_add_new_group') .  "
            </div>
            <div class=\"grid_6 push_1 view-data section omega\">"
              . variable_get('sfo_food_content_groups') .
              
              /*
              "<div id=\"search-map\" class=\"form-input\">
              <input placeholder=\"Enter your address or zipcode here.\" class=\"form-item\" />
              <input type=\"image\" src=\"" . base_path() . path_to_theme() . "/images/search_button.png\" id=\"search-links-submit\" class=\"search_btn\" value=\"Search\" alt=\"Search\">
              </div> 
              */
/*               "Over <strong>" . variable_get('citygroups_stats_groups_published') . " groups</strong> in " . variable_get('citygroups_city_name') . "." . */
              
              "<div class=\"button\"><a href=\"food/map\">Map view</a></div>
              <div class=\"button\"><a href=\"food/list\">List view</a></div>
            </div>
          </div>
          <div class=\"clear\"></div>
          <div class=\"grid_16 sections\">
            <div class=\"grid_6 news section alpha\">"
              . variable_get('sfo_food_content_news') .  "                          
            </div>    
            <div class=\"grid_6 push_1 promote section omega\">" 
            . variable_get('sfo_food_content_promote')
/*             . citygroups_promote() */
            . "</div>      
          </div>
        ";
      break;  
  
      case 'about':
      
        $facebook = '<img src="' . base_path() . path_to_theme() . '/images/groups_icons/icon_bw_facebook.png" title="Facebook" alt="Facebook" />';
        $yahoo = '<img src="' . base_path() . path_to_theme() . '/images/groups_icons/icon_bw_yahoo_groups.png" title="Yahoo Groups" alt="Yahoo Groups" />';
        $google = '<img src="' . base_path() . path_to_theme() . '/images/groups_icons/icon_bw_google_groups.png" title="Google Groups" alt="Google Groups" />';
        $meetup = '<img src="' . base_path() . path_to_theme() . '/images/groups_icons/icon_bw_meetup.png" title="Meetup Groups" alt="Meetup Groups" />';
        $mailinglist = '<img src="' . base_path() . path_to_theme() . '/images/groups_icons/icon_bw_email.png" title="Email" alt="Email" />';
        $twitter = '<img src="' . base_path() . path_to_theme() . '/images/groups_icons/icon_bw_twitter.png" title="Twitter" alt="Twitter" />';
        $blog = '<img src="' . base_path() . path_to_theme() . '/images/groups_icons/icon_bw_blogs.png" title="Community Blogs" alt="Community Blogs" />';
        $mail = '<img src="' . base_path() . path_to_theme() . '/images/groups_icons/icon_bw_mail.png" title="Personal Email" alt="Personal Email" />';
  
        $links = $facebook . $google . $meetup . $mailinglist . $twitter . $blog . $yahoo . $mail /*. $ning */;

        $output .= '
        <div class="grid_16 postscript-content alpha omega">
          <div class="grid_6 about alpha">'
          . variable_get('sfo_food_content_about') .
          '</div>
  
          <div class="grid_4 push_1 participate">'
          . variable_get('sfo_food_content_about_participate') .
          '</div>

          <div class="grid_4 push_1 local omega">'
          . variable_get('sfo_food_content_about_local') .
          '</div>
        </div>        
        ';
      break;      

  }
  
  return $output;
}