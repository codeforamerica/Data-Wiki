<?php
?>
<div<?php if ($class) { print ' class="'. $class .'"'; } ?>>
<h3><?php print $title ?></h3>
<?php if ($is_list): ?>
    <ul>
<?php endif; ?>
    <?php print $content ?>
<?php if ($is_list): ?>
    </ul>
<?php endif; ?>
</div>