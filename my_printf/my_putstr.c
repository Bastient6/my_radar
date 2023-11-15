/*
** EPITECH PROJECT, 2022
** printf
** File description:
** my putstr
*/

#include<stdarg.h>
#include<stdio.h>

int my_strlen(char const *str);
int my_putchar(char c);

int my_putstr(char *str)
{
    int counter = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        my_putchar (str [i]);
    }
    counter = my_strlen(str);
    return counter;
}

void my_putstr_my(va_list ap)
{
    my_putstr(va_arg(ap, char *));
}
