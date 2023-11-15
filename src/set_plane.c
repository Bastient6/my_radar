/*
** EPITECH PROJECT, 2022
** my radar
** File description:
** set plane
*/

#include "my.h"

void set_delay(radar_t *radar, elementplane *plane)
{
    plane->sprite = 0;
    for (;radar->buffer[radar->i] < '0' ||
        radar->buffer[radar->i] > '9'; radar->i++);
    for (;radar->buffer[radar->i] != '\n'; radar->i++){
        plane->sprite = plane->sprite * 10 + radar->buffer[radar->i] - 48;
    }
    plane->sprite = plane->sprite * 10;
}

void set_plane_final(radar_t *radar, elementplane *plane)
{
    plane->planepositionfinal = (sfVector2f){0, 0};
    plane->speed = 0;
    int xf = 0;
    int yf = 0;
    int speed = 0;
    for (;radar->buffer[radar->i] < '0' ||
        radar->buffer[radar->i] > '9'; radar->i++);
    for (;radar->buffer[radar->i] != ' '; radar->i++)
        xf = xf * 10 + radar->buffer[radar->i] - 48;
    for (;radar->buffer[radar->i] < '0' ||
    radar->buffer[radar->i] > '9'; radar->i++);
    for (;radar->buffer[radar->i] != ' '; radar->i++)
        yf = yf * 10 + radar->buffer[radar->i] - 48;
    for (;radar->buffer[radar->i] < '0' ||
    radar->buffer[radar->i] > '9'; radar->i++);
    for (;radar->buffer[radar->i] != ' '; radar->i++)
        speed = speed * 10 + radar->buffer[radar->i] - 48;
    plane->planepositionfinal = (sfVector2f){xf, yf};
    plane->speed = speed;
    set_delay(radar, plane);
}

void rect(elementplane *plane)
{
    plane->rectangle = sfRectangleShape_create();
    sfRectangleShape_setFillColor(plane->rectangle, sfTransparent);
    sfRectangleShape_setPosition(plane->rectangle, plane->planeposition);
    sfRectangleShape_setOutlineColor
    (plane->rectangle, sfColor_fromRGB(100,0,0));
    sfRectangleShape_setSize
    (plane->rectangle, (sfVector2f){20,20});
    sfRectangleShape_setFillColor(plane->rectangle, sfTransparent);
    sfRectangleShape_setOutlineThickness(plane->rectangle, 2);
}

void plan(elementplane *plane, int x, int y)
{
    plane->planeposition = (sfVector2f){0, 0};
    plane->plane = NULL;
    plane->planetexture = NULL;
    plane->planeposition = (sfVector2f){x, y};
    plane->plane = sfSprite_create();
    plane->planetexture = sfTexture_createFromFile
    ("./src/sprite/plane.png", NULL);
    sfSprite_setTexture(plane->plane, plane->planetexture, sfTrue);
    sfSprite_setPosition(plane->plane, plane->planeposition);
}

void set_plane (radar_t *radar, listeplane *listplane)
{
    elementplane *plane = malloc(sizeof(*plane));
    int x = 0;
    int y = 0;
    for (;radar->buffer[radar->i] < '0' ||
    radar->buffer[radar->i] > '9'; radar->i++);
    for (;radar->buffer[radar->i] != ' '; radar->i++)
        x = x * 10 + radar->buffer[radar->i] - 48;
    for (;radar->buffer[radar->i] < '0' ||
    radar->buffer[radar->i] > '9'; radar->i++);
    for (;radar->buffer[radar->i] != ' '; radar->i++)
        y = y * 10 + radar->buffer[radar->i] - 48;
    set_plane_final(radar, plane);
    plan(plane, x, y);
    rect(plane);
    plane->next = listplane->first_element;
    listplane->first_element = plane;
}
