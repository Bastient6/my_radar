/*
** EPITECH PROJECT, 2022
** radar
** File description:
** open window
*/

#include "my.h"

sfRenderWindow* open_window(radar_t *radar)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow* window = NULL;
    radar->window = sfRenderWindow_create
    (mode, "My Fisrt Window", sfResize | sfClose, NULL);
    return window;
}
