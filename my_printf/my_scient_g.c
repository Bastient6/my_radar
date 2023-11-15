/*
** EPITECH PROJECT, 2022
** printf
** File description:
** eE
*/

#include<stdarg.h>

int my_putchar(char c);
int my_put_nbr(int nb);

int test1(double j, char signe)
{
    if (signe == '+') {
        j = j * 100000;
    } else {
        j = j * 100;
    }
    if (j / 1000000 < 1) {
        j = j + 1;
    }
    return 0;
}

int print1 (double nb, char signe, int p)
{
    int counter = 0;
    int i = nb;
    double j = nb - i;
    test1(j, signe);
    counter += my_put_nbr (i);
    my_putchar('.');
    counter ++;
    counter += my_put_nbr (j);
    my_putchar ('e');
    counter ++;
    my_putchar (signe);
    counter ++;
    if (p <= 9) {
        counter += my_putchar('0');
    }
    counter += my_put_nbr (p);
    return counter;
}

int my_scient_g (double nb)
{
    int counter = 0;
    char signe;
    int p = 0;
    if (nb < 1) {
        signe = '-';
    } else {
        signe = '+';
    }
    while ( nb > 9){
        nb = nb / 10;
        p++;
    }
    while ( nb < 1){
        nb = nb * 10;
        p++;
    }
    counter += print1(nb, signe, p);
    return counter;
}
