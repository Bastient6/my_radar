/*
** EPITECH PROJECT, 2022
** csfml
** File description:
** analyse_event
*/

#include "my.h"

void analyse_events(radar_t *radar, liste *list, listeplane *listplane)
{
    if (radar->event.type == sfEvtClosed) {
        close_window(listplane, list, radar);
    }
    if (radar->event.type == sfEvtKeyPressed
    && radar->event.key.code == sfKeyEscape) {
        close_window(listplane, list, radar);
    }
    if ((radar->event.type == sfEvtKeyPressed
    && radar->event.key.code == sfKeyL))
        radar->circle ^= 1;
    if ((radar->event.type == sfEvtKeyPressed
    && radar->event.key.code == sfKeyS))
        radar->sprite ^= 1;
}
