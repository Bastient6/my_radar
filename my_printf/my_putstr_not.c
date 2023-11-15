/*
** EPITECH PROJECT, 2022
** printf
** File description:
** my putstr not my
*/

#include<stdarg.h>
#include<stdio.h>

int my_strlen(char const *str);
int my_putchar(char c);
int my_putnbr_base_o(int nb);
int my_put_nbr(int nb);
int my_putstr(char *str);

int my_putstr_not(char *str)
{
    int counter = 0;
    for (int i = 0;str[i] != '\0'; i++) {
        if ( str[i] < 8) {
            counter += my_putstr("\\00");
            counter += my_putnbr_base_o(str[i]);
        }
        if (str[i] < 32 && str[i] >= 8) {
            counter += my_putstr("\\0");
            counter += my_putnbr_base_o(str[i]);
        }
        if (str[i] >= 127){
            counter += my_putchar('\\');
            counter += my_putnbr_base_o(str[i]);
        }
        if (str[i] >= 32 && str[i] < 127){
            my_putchar(str[i]);
            counter ++;
        }
    }
    return counter;
}

void my_putstr_not_my(va_list ap)
{
    my_putstr_not(va_arg(ap, char *));
}
