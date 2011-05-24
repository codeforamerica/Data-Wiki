<?php
?>
<?php if (isset($pre_item)) { print $pre_item; } ?>
<li<?php if (isset($class)) { print ' class="'. $class .'"'; } ?><?php if (isset($style)) { print ' style="'. $style .'"'; } ?>>
<?php if (isset($pre_link)) { print $pre_link . '&nbsp;'; } ?><?php if (isset($link)) { print $link; } ?><?php if (isset($post_link)) { print $post_link; } ?>
</li>
<?php if (isset($post_item)) { print $post_item; } ?>
