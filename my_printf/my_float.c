/*
** EPITECH PROJECT, 2022
** printf
** File description:
** float
*/

#include<stdio.h>
#include<stdarg.h>

int my_putchar(char c);
int my_put_nbr(int);

int my_float(float ap)
{
    int counter = 0;
    int nb = ap;
    counter += my_put_nbr(nb);
    my_putchar('.');
    counter ++;
    nb = nb * 1000000;
    int result = nb;
    counter += my_put_nbr(result);
    return 0;
}

void my_float_my(va_list ap)
{
    my_float(va_arg(ap, int));
}
