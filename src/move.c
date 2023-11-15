/*
** EPITECH PROJECT, 2022
** bsradar
** File description:
** mover
*/

#include "my.h"

void move(sfVector2f planepositionfinal, sfSprite *plane,
sfRectangleShape *rectangle, int speed)
{
    sfVector2f C = sfSprite_getPosition(plane);
    if (C.x != planepositionfinal.x) {
        if (C.x < planepositionfinal.x){
            C.x += speed / 10;
        }
        if (C.x > planepositionfinal.x){
            C.x -= speed / 10;
        }
    }
    if (C.y != planepositionfinal.y) {
        if (C.y < planepositionfinal.y){
            C.y += speed / 10;
        }
        if (C.y > planepositionfinal.y){
            C.y -= speed / 10;
        }
    }
    sfSprite_setPosition(plane, C);
    sfRectangleShape_setPosition(rectangle, C);
}
