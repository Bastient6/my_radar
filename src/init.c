/*
** EPITECH PROJECT, 2022
** radar
** File description:
** init
*/

#include "my.h"

void init (radar_t *radar, char **argv, liste *list, listeplane *listplane)
{
    radar->end = 1;
    open_window(radar);
    radar->buffer = read_file(argv[1]);
    radar->i = 0;
    set_background(radar);
    for (; radar->buffer[radar->i] != 0; radar->i++){
        if (radar->buffer[radar->i] == 'T') {
            radar->radius = 0;
            set_tour(radar, list);
        }
        if (radar->buffer[radar->i] == 'A')
            set_plane(radar, listplane);
    }
}
