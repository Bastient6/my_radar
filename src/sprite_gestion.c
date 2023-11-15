/*
** EPITECH PROJECT, 2022
** my radar
** File description:
** sprite gestion
*/

#include "my.h"

void plane_gestion (radar_t *radar, listeplane *listplane)
{
    elementplane *plane = listplane->first_element;
    while (plane != NULL) {
        if (plane->sprite == 0 && radar->sprite == 1)
            sfRenderWindow_drawSprite(radar->window, plane->plane, NULL);
        if (plane->sprite == 0 && radar->circle == 1)
            sfRenderWindow_drawRectangleShape
        (radar->window, plane->rectangle, NULL);
        plane = plane->next;
    }
}

void plane_move(listeplane *listplane, radar_t *radar)
{
    elementplane *plane = listplane->first_element;
    radar->end = 0;
    while (plane != NULL) {
        if (plane->sprite != 0)
            plane->sprite -= 1;
        sfVector2f C = sfSprite_getPosition(plane->plane);
        if ((C.y + 10 >= plane->planepositionfinal.y
        && C.y - 10 <= plane->planepositionfinal.y)
        && (C.x + 10 >= plane->planepositionfinal.x
        && C.x - 10 <= plane->planepositionfinal.x)) {
            plane->sprite = -1;
        }
        if (plane->sprite == 0) {
        move(plane->planepositionfinal, plane->plane,
        plane->rectangle, plane->speed);
        }
        if (plane->sprite >= 0)
            radar->end = 2;
        plane = plane->next;
    }
}

void tower_gestion(radar_t *radar, liste *list)
{
    element *main = list->first_element;
    while (main != NULL) {
        if (radar->sprite == 1)
            sfRenderWindow_drawSprite(radar->window, main->tour, NULL);
        if (radar->circle == 1)
            sfRenderWindow_drawCircleShape
        (radar->window, main->circle, NULL);
        main = main->next;
    }
}

void sprite_gestion(radar_t *radar, liste *list, listeplane *listplane)
{
    sfClock *clock = sfClock_create ();
    sfTime time ;
    float seconds ;
    if (radar->t == 1){
        sfRenderWindow_clear(radar->window, sfBlack);
        sfRenderWindow_drawSprite(radar->window, radar->background, NULL);
        tower_gestion(radar, list);
        plane_gestion(radar, listplane);
        while (seconds < 0.1) {
            radar->timer += 1;
            time = sfClock_getElapsedTime(clock);
            seconds = time.microseconds / 1000000.0;
        }
        plane_move(listplane, radar);
    }
    is_intersecting_rect(listplane, list, radar);
    radar->t = 1;
    sfRenderWindow_display(radar->window);
}
