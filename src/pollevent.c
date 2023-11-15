/*
** EPITECH PROJECT, 2022
** radar
** File description:
** pollevent
*/

#include "my.h"

void pollevent (radar_t *radar, liste *list, listeplane *listplane)
{
    if (radar->end == 0){
        close_window(listplane, list, radar);
    }
    while (sfRenderWindow_pollEvent(radar->window, &radar->event))
        analyse_events(radar, list, listplane);
}
