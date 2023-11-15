/*
** EPITECH PROJECT, 2022
** my radar
** File description:
** set tour
*/

#include "my.h"

void circle(element *tour, radar_t *radar, int x, int y)
{
    tour->circle = sfCircleShape_create();
    sfCircleShape_setFillColor(tour->circle, sfTransparent);
    sfCircleShape_setRadius(tour->circle, radar->radius);
    sfCircleShape_setPosition(tour->circle, (sfVector2f)
    {x - radar->radius + 25, y - radar->radius + 25});
    sfCircleShape_setOutlineThickness(tour->circle, 2);
    sfCircleShape_setOutlineColor(tour->circle, sfBlue);
    tour->radius = radar->radius;
}

void tower(element *tour, int x, int y)
{
    tour->tourtexture = NULL;
    tour->tour = sfSprite_create();
    tour->tourposition = (sfVector2f){x, y};
    tour->tourtexture = sfTexture_createFromFile("src/sprite/tour.png", NULL);
    sfSprite_scale(tour->tour,(sfVector2f){0.5, 0.5});
    sfSprite_setTexture(tour->tour, tour->tourtexture, sfTrue);
    sfSprite_setPosition(tour->tour, tour->tourposition);

}

void set_tour (radar_t *radar, liste *list)
{
    element *tour = malloc(sizeof(*tour));
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
    for (;radar->buffer[radar->i] < '0' ||
    radar->buffer[radar->i] > '9'; radar->i++);
    for (;radar->buffer[radar->i] != '\n'
    && radar->buffer[radar->i] != 0; radar->i++)
        radar->radius = radar->radius * 10 + radar->buffer[radar->i] - 48;
    tower(tour, x, y);
    circle(tour,radar, x, y);
    tour->next = list->first_element;
    list->first_element = tour;
}
