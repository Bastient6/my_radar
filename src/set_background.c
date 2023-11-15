/*
** EPITECH PROJECT, 2022
** my radar
** File description:
** set background
*/

#include "my.h"

void set_background (radar_t *radar)
{
    radar->background = NULL;
    radar->backgroundtexture = NULL;
    radar->backgroundposition = (sfVector2f) {-50, -50};
    radar->background = sfSprite_create();
    radar->backgroundtexture = sfTexture_createFromFile
    ("./src/sprite/fond.png", NULL);
    sfSprite_setTexture(radar->background, radar->backgroundtexture, sfFalse);
    sfSprite_setPosition(radar->background, radar->backgroundposition);
}
