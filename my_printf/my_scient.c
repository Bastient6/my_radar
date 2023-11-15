/*
** EPITECH PROJECT, 2022
** printf
** File description:
** eE
*/

#include<stdarg.h>

int my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char *str);

int print (double nb, char signe, int p)
{
    int counter = 0;
    int i = nb;
    double j = nb - i;
    j = j * 1000000;
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

int my_scient (double nb)
{
    int counter = 0, p = 0;;
    char signe = '+';
    if (nb == 0) {
        counter += my_putstr("0.000000e+00");
        return 0;
    }
    if (nb < 1)
        signe = '-';
    while ( nb > 9){
        nb = nb / 10;
        p++;
    }
    while ( nb < 1){
        nb = nb * 10;
        p++;
    }
    counter += print(nb, signe, p);
    return counter;
}

void my_scient_my(va_list ap)
{
    my_scient(va_arg(ap, double));
}
