/*
** EPITECH PROJECT, 2022
** printf
** File description:
** my putchar
*/

#include<unistd.h>
#include<stdarg.h>

int my_putchar(char c)
{
    int counter = 0;
    write (1, &c, 1);
    counter ++;
    return counter;
}

void my_putchar_my(va_list ap)
{
    my_putchar(va_arg(ap, int));
}
