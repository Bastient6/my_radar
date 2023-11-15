/*
** EPITECH PROJECT, 2023
** B-MUL-100-MPL-1-1-myradar-bastien.tiffy
** File description:
** close_window
*/

#include"my.h"

void destroy_plane(listeplane *listplane)
{
    elementplane *plane = listplane->first_element;
    elementplane *tmp;
    while (plane != NULL) {
        sfTexture_destroy(plane->planetexture);
        sfSprite_destroy(plane->plane);
        sfRectangleShape_destroy(plane->rectangle);
        tmp = plane;
        plane = plane->next;
        free(tmp);
    }
}

void destroy_tower(liste *list)
{
    element *tower = list->first_element;
    element *tmp;
    while (tower != NULL) {
        sfTexture_destroy(tower->tourtexture);
        sfSprite_destroy(tower->tour);
        sfCircleShape_destroy(tower->circle);
        tmp = tower;
        tower = tower->next;
        free(tmp);
    }
}

int close_window(listeplane *listplane, liste *list, radar_t *radar)
{
    radar->t = 0;
    destroy_plane(listplane);
    destroy_tower(list);
    sfSprite_destroy(radar->background);
    sfTexture_destroy(radar->backgroundtexture);
    sfRenderWindow_close(radar->window);
    sfRenderWindow_destroy(radar->window);
    return 0;
}
