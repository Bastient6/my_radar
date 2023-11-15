/*
** EPITECH PROJECT, 2022
** my hunter
** File description:
** lib
*/

#ifndef MY_H_
    #define MY_H_
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <time.h>
    #include <math.h>
    #include <sys/types.h>
    #include <sys/stat.h>

    typedef struct element element;
    struct element {
        sfSprite *tour;
        sfVector2f tourposition;
        sfTexture *tourtexture;
        sfCircleShape *circle;
        int radius;
        element *next;
    };

    typedef struct elementplane elementplane;
    struct elementplane {
        sfSprite *plane;
        int R;
        int G;
        int B;
        int zone;
        int is_tower;
        sfRectangleShape *rectangle;
        sfVector2f planeposition;
        sfVector2f planepositionfinal;
        sfTexture *planetexture;
        int speed;
        int sprite;
        int end;
        elementplane *next;
    };

    typedef struct listeplane listeplane;
    struct listeplane {
        elementplane *first_element;
    };

    typedef struct liste liste;
    struct liste {
        element *first_element;
    };

    typedef struct radar{
    int i;
    int j;
    int t;
    int end;
    sfRenderWindow *window;
    sfEvent event;
    sfVector2f position;
    float radius;
    sfSprite *background;
    sfVector2f backgroundposition;
    sfIntRect rectbackground;
    sfTexture *backgroundtexture;
    char *buffer;
    int circle;
    int sprite;
    int timer;
    } radar_t;

    sfRenderWindow* open_window(radar_t *radar);
    void pollevent (radar_t *radar, liste *list, listeplane *listplane);
    void analyse_events(radar_t *radar, liste *list, listeplane *listplane);
    void move(sfVector2f planepositionfinal, sfSprite *plane,
    sfRectangleShape *rectangle, int speed);
    void print_framerate(void);
    void sprite_gestion(radar_t *radar, liste *list, listeplane *listplane);
    void set_background (radar_t *radar);
    void set_tour (radar_t *radar, liste *list);
    void set_plane (radar_t *radar, listeplane *listplane);
    void init (radar_t *radar, char **argv, liste *list, listeplane *listplane);
    void flag_h(void);
    int my_printf(const char * format , ...);
    char *read_file(char const * filepath);
    int is_intersecting_rect(listeplane *listplane, liste *list,
    radar_t *radar);
    int close_window(listeplane *listplane, liste *list, radar_t *radar);
    int create_zone(elementplane *plane);

#endif /* !MY_H_ */
