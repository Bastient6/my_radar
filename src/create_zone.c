/*
** EPITECH PROJECT, 2023
** B-MUL-100-MPL-1-1-myradar-bastien.tiffy
** File description:
** create_zone
*/

#include "my.h"
int zone_1(elementplane *plane, sfVector2f planeposition)
{
    if (planeposition.x <= 480)
        plane->zone = 1;
    if (planeposition.x > 480 && planeposition.x <= 960)
        plane->zone = 2;
    if (planeposition.x > 960 && planeposition.x <= 1440 )
        plane->zone = 3;
    if (planeposition.x > 1440 && planeposition.x <= 1920 )
        plane->zone = 4;
}

int zone_2(elementplane *plane, sfVector2f planeposition)
{
    if (planeposition.x <= 480)
        plane->zone = 5;
    if (planeposition.x > 480 && planeposition.x <= 960)
        plane->zone = 6;
    if (planeposition.x > 960 && planeposition.x <= 1440 )
        plane->zone = 7;
    if (planeposition.x > 1440 && planeposition.x <= 1920 )
        plane->zone = 8;
}

int zone_3(elementplane *plane, sfVector2f planeposition)
{
    if (planeposition.x <= 480)
        plane->zone = 9;
    if (planeposition.x > 480 && planeposition.x <= 960)
        plane->zone = 10;
    if (planeposition.x > 960 && planeposition.x <= 1440 )
        plane->zone = 11;
    if (planeposition.x > 1440 && planeposition.x <= 1920 )
        plane->zone = 12;
}

int zone_4(elementplane *plane, sfVector2f planeposition)
{
    if (planeposition.x <= 480)
        plane->zone = 13;
    if (planeposition.x > 480 && planeposition.x <= 960)
        plane->zone = 14;
    if (planeposition.x > 960 && planeposition.x <= 1440 )
        plane->zone = 15;
    if (planeposition.x > 1440 && planeposition.x <= 1920 )
        plane->zone = 16;
}

int create_zone(elementplane *plane)
{
    sfVector2f planeposition = (sfVector2f){0,0};
    planeposition = sfSprite_getPosition(plane->plane);
    if (planeposition.y <= 270)
        zone_1(plane, planeposition);
    if (planeposition.y > 270 && planeposition.y <= 540)
        zone_2(plane, planeposition);
    if (planeposition.y > 540 && planeposition.y <= 810)
        zone_3(plane, planeposition);
    if (planeposition.y > 810 && planeposition.y <= 1080)
        zone_4(plane, planeposition);
}
