/*
** EPITECH PROJECT, 2022
** printf
** File description:
** long putnbr
*/

#include<stdarg.h>

int my_putchar(char c);

int my_long_putnbr(long nb)
{
    int counter = 0;

        while (nb != 0) {
        if (nb < 10) {
            my_putchar('0' + (nb));
            return 1;
        }
        if (nb == 0){
            my_putchar('0');
        }
        nb = nb / 10;
        my_putchar('0' + (nb % 10));
    return counter + 1;
    }
    return counter;
}

void my_long_putnbr_my(va_list ap)
{
    my_long_putnbr(va_arg(ap, long));
}
