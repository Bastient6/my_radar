/*
** EPITECH PROJECT, 2022
** printf
** File description:
** my long putnbr base
*/

#include<stdarg.h>

unsigned int my_unsigned_len(char const *str);
int my_putchar(char c);

int my_long_putnbr_base_x(unsigned long nb)
{
    char *base = "0123456789ABCDEF";
    unsigned int counter = 0;

    if (nb < my_unsigned_len(base)) {
        my_putchar(base[nb]);
        return counter + 1;
    }
    counter += my_long_putnbr_base_x(nb / my_unsigned_len(base));
    my_putchar(base[nb % my_unsigned_len(base)]);
    return counter + 1;
}

void my_long_putnbr_base_x_my(va_list ap)
{
    my_long_putnbr_base_x(va_arg(ap, int));
}
