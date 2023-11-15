/*
** EPITECH PROJECT, 2022
** printf
** File description:
** my putchar %
*/

#include<unistd.h>
#include<stdarg.h>

int my_putchar_p(char c)
{
    int counter = 0;
    write (1, &c, 1);
    counter ++;
    return counter;
}

void my_putchar_p_my(char c)
{
    (void) c;
    my_putchar_p('%');
}
