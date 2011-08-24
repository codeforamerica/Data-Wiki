<?php
// $Id: menu_icons_css_item.tpl.php,v 1.3 2010/02/15 15:35:48 skilip Exp $

/**
 * @file
 *
 * Template file for generating the CSS file used for the menu-items
 */

/**
 * Variables:
 * $mlid
 * $path
 *
 * @author dylan@opensourcery.com
 */
?>
.menu-<?php print $mlid ?>, ul.links li.menu-<?php print $mlid ?> {
  background-image: url(<?php print $path ?>);
  padding-<?php print "$pos:$size"?>px;
  background-repeat: no-repeat;
  background-position: <?php print $pos?>;
  height: <?php print $size?>px;
}

