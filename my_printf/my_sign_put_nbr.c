/*
** EPITECH PROJECT, 2022
** printf
** File description:
** sign putnbr
*/

#include<stdarg.h>

int my_putchar(char c);

int my_sign_put_nbr(int nb)
{
    int counter = 0;
    static int t = 0;
    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
        t = 1;
        counter ++;
    } else {
    if ( t == 0){
        my_putchar('+');
        t = 1;
    }
    }
    if (nb < 10) {
        my_putchar('0' + (nb));
        return 1;
    }
    counter += my_sign_put_nbr(nb / 10);
    my_putchar('0' + (nb % 10));
    return counter + 1;
}

void my_sign_put_nbr_my(va_list ap)
{
    my_sign_put_nbr(va_arg(ap, int));
}
