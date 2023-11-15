/*
** EPITECH PROJECT, 2022
** my radar
** File description:
** main
*/

#include "my.h"

liste *init1(void)
{
    liste *liste = malloc(sizeof(*liste));
    liste->first_element = NULL;
    return liste;
}

listeplane *init2(void)
{
    listeplane *listeplane = malloc(sizeof(*listeplane));
    listeplane->first_element = NULL;
    return listeplane;
}

int error(void)
{
    my_printf("./my_radar: bad arguments: 0 given but 84 is required");
    my_printf("\nretry with -h\n");
    return 84;
}

int main(int argc, char **argv)
{
    liste *list = init1();
    listeplane *listplane = init2();
    struct radar radar;
    radar.circle = 1;
    radar.sprite = 1;
    if (argc == 1)
        return error();
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h'){
        flag_h();
        return 0;
    }
    if (argc == 2){
        init(&radar, argv, list, listplane);
        while (sfRenderWindow_isOpen(radar.window)) {
            pollevent(&radar, list, listplane);
            sprite_gestion(&radar, list, listplane);
        }
        return 0;
    }
    return 84;
}
