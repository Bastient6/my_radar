/*
** EPITECH PROJECT, 2022
** src
** File description:
** float_f
*/

#include<stdarg.h>

int my_putchar(char c);
int my_put_nbr(int nb);

int my_float_f(double nb)
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

void my_float_f_my(va_list ap)
{
    my_float_f(va_arg(ap, double));
}
