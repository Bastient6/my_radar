/*
** EPITECH PROJECT, 2022
** printf
** File description:
** putnbr n
*/

#include<stdarg.h>
#include<stdio.h>

int my_putchar(char c);

int my_putnbr_n(int counter, va_list ap, int i)
{
    i++;
    int *e = va_arg(ap, int *);
    *e = counter;
    return i;
}
