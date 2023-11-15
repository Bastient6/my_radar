/*
** EPITECH PROJECT, 2022
** printf
** File description:
** my putnbr base
*/

#include<stdarg.h>

unsigned int my_unsigned_len(char const *str);
int my_putchar(char c);

int my_putnbr_base_u(unsigned int nb)
{
    char *base = "0123456789";
    unsigned int counter = 0;

    if (nb < my_unsigned_len(base)) {
        my_putchar(base[nb]);
        return counter + 1;
    }
    counter += my_putnbr_base_u(nb / my_unsigned_len(base));
    my_putchar(base[nb % my_unsigned_len(base)]);
    return counter + 1;
}

void my_putnbr_base_u_my(va_list ap)
{
    my_putnbr_base_u(va_arg(ap, int));
}
