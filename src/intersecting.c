/*
** EPITECH PROJECT, 2022
** radar
** File description:
** intersecting
*/

#include "my.h"

int verrif_tower(sfVector2f planeposition, elementplane *plane, liste *list)
{
    plane->is_tower = 0;
    element *tower = list->first_element;
    while (tower != NULL) {
        if (pow((plane->planeposition.x - tower->tourposition.x),2) +
        pow((plane->planeposition.y - tower->tourposition.y),2)
        <= pow(tower->radius,2))
            plane->is_tower = 1;
        tower = tower->next;
    }
}

int set(sfVector2f planeposition, sfVector2f planepositionnext,
elementplane *plane, elementplane *planenext)
{
    if ( planenext->sprite < 0 || plane->sprite < 0 )
        planenext->is_tower = 1;
    if (plane->is_tower == 0 && planenext->is_tower == 0 && plane != planenext){
        if ((((planeposition.x - planepositionnext.x)
        * (planeposition.x - planepositionnext.x)) +
        ((planeposition.y - planepositionnext.y) * (planeposition.y
        - planepositionnext.y))) <= (22 * 22)) {
            plane->sprite = -1;
            planenext->sprite = -1;
        }
    }
}

int verrif_zone (elementplane *plane, elementplane *planenext,  liste *list)
{
    if (plane->zone == planenext->zone){
        sfVector2f planeposition = (sfVector2f){0,0};
        sfVector2f planepositionnext = (sfVector2f) {0,0};
        planeposition = sfSprite_getPosition(plane->plane);
        planepositionnext = sfSprite_getPosition(planenext->plane);
        verrif_tower(planeposition, plane, list);
        verrif_tower(planepositionnext, planenext, list);
        set(planeposition, planepositionnext, plane, planenext);
    }
}

int is_intersecting_rect(listeplane *listplane, liste *list, radar_t *radar)
{
    elementplane *plane = listplane->first_element;
    while (plane != NULL) {
        elementplane *planenext = listplane->first_element;
        while (planenext != NULL) {
            create_zone(plane);
            create_zone(planenext);
            verrif_zone(plane, planenext, list);
            planenext = planenext->next;
        }
        plane = plane->next;
    }
    return 0;
}
