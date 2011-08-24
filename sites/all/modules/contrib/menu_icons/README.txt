$Id: README.txt,v 1.3 2010/05/05 12:38:04 skilip Exp $

Menu Icons Module
================================================================================

DESCRIPTION:
--------------------------------------------------------------------------------
This module allows you to upload an image in the menu-item's configuration form.
The uploaded image is added as an background image to the menu item.

USAGE:
--------------------------------------------------------------------------------
After installing the module you can configure it's global settings by navigating
to: admin/settings/menu_icons. Uploading an image for a menu-item can be done at
the menu items settings form (e.g.: admin/build/menu/item/1/edit).

The text of the menu item cal be hidden by the adding the following CSS code to
your theme's stylesheet:

.menu_icon {
  display: block;
  overflow: hidden;
  padding-left: 100%;
}