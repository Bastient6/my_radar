/*
** EPITECH PROJECT, 2022
** src
** File description:
** float_f
*/

#include<stdarg.h>
#include<stdio.h>
int my_putchar(char c);
int my_put_nbr(int nb);

int power3(double nb)
{
    int p = 0;
    while ( nb > 0){
        nb = nb / 10;
        p++;
    }
    return p;
}

int my_float_g(double nb)
{
    int counter = 0;
    int i = nb;
    nb = nb - i;
    int e = nb * 10000000;
    counter += my_put_nbr(i);
    counter += my_putchar('.');
    if (nb == 0) {
        for (int o = 1; o <= 6; o++) {
        my_putchar('0');
        }
    }
    if (nb > 0){
        e += 1;
        counter += my_put_nbr(e / 10);
    }
    if (nb < 0){
        e -= 1;
        counter += my_put_nbr(-e / 10);
    }
    return counter;
}
