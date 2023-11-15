/*
** EPITECH PROJECT, 2022
** printf
** File description:
** my putnbr base o #
*/

#include<stdarg.h>

unsigned int my_unsigned_len(char const *str);
int my_putchar(char c);

int my_putnbr_base_o_h(unsigned int nb)
{
    char *base = "01234567";
    unsigned int counter = 0;
    static int t = 0;
    if ( t == 0){
        my_putchar('0');
        t = 1;
    }
    if (nb < my_unsigned_len(base)) {
        my_putchar(base[nb]);
        return counter + 1;
    }
    counter += my_putnbr_base_o_h(nb / my_unsigned_len(base));
    my_putchar(base[nb % my_unsigned_len(base)]);
    return counter + 1;
}

void my_putnbr_base_o_h_my(va_list ap)
{
    my_putnbr_base_o_h(va_arg(ap, int));
}
