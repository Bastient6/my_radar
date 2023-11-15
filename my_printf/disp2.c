/*
** EPITECH PROJECT, 2022
** printf
** File description:
** disp 2
*/
#include "flag.h"
#include<stdarg.h>

flag_t flag_tab4[] = {
    {'d', my_sign_put_nbr_my},
    {'i', my_sign_put_nbr_my},
};

int flag_h(const char *format, int i, va_list ap);
int my_putstr(char const *str);
int lib(const char *format, int i, va_list ap);
int disp(const char *format, int i, va_list ap);

int lib4(const char *format, int i, va_list ap)
{
    int counter = 0;
    for (int f = 0; f <= 3; f++){
        if (flag_tab4[f].c == format[i + 1]) {
            return flag_tab4[f].ptr(ap);
        }
    }
    my_putstr(format);
    return counter ;
}

int disp2(const char *format, int i, va_list ap)
{
    int counter = 0;
    if (format[i + 1] == '+') {
        i++;
        counter += lib4(format, i, ap);
        return i;
    }
    counter += disp(format, i, ap);
    return i;
}
