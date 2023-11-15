/*
** EPITECH PROJECT, 2022
** B-CPE-101-MPL-1-1-miniprintf-paul.pomaret
** File description:
** mini_printf
*/

#include<stdarg.h>
#include<unistd.h>
#include "flag.h"
#include<stdio.h>

flag_t flag_tab[] = {
    {'c', my_putchar_my},
    {'i', my_put_nbr_my},
    {'d', my_put_nbr_my},
    {'e', my_scient_my},
    {'E', my_scient_my},
    {'o', my_putnbr_base_o_my},
    {'u', my_putnbr_base_u_my},
    {'x', my_putnbr_base_x_my},
    {'X', my_putnbr_base_x_my},
    {'b', my_putnbr_base_b_my},
    {'s', my_putstr_my},
    {'f', my_float_f_my},
    {'F', my_float_f_my},
    {'S', my_putstr_not_my},
    {'g', my_float_scient_my},
    {'G', my_float_scient_my},
    {'%', my_putchar_p_my},
};

flag_t flag_tab2[] = {
    {'i', my_long_putnbr_my},
    {'d', my_long_putnbr_my},
    {'o', my_long_putnbr_base_o_my},
    {'u', my_long_putnbr_base_u_my},
    {'x', my_long_putnbr_base_x_my},
    {'X', my_long_putnbr_base_x_my},
};

flag_t flag_tab3[] = {
    {'o', my_putnbr_base_o_h_my},
    {'x', my_putnbr_base_x_h_my},
    {'X', my_putnbr_base_xx_h_my},
};

int my_putchar(char c);
int lib(const char *format, int i, va_list ap);
int lib2(const char *format, int i, va_list ap);
int lib3(const char *format, int i, va_list ap);
int lib4(const char *format, int i, va_list ap);
int flag_h(const char *format, int i, va_list ap);
int flag_p(const char *format, int i);
int my_putstr(char const *str);
int my_putnbr_n(int counter, va_list ap, const char *format, int i);
int disp2(const char *format, int i, va_list ap);
int conditional(const char *format, va_list ap);

int disp(const char *format, int i, va_list ap)
{
    int counter = 0;
    if (format[i + 1] == 'l') {
        i++;
        counter += lib2(format, i, ap);
        return i;
    }
    if (format[i + 1] == '#'){
        i++;
        counter += lib3(format, i, ap);
        return i;
    }
    if (format[i + 1] == 'n') {
        my_putnbr_n(counter, ap, format, i);
        return i;
    }
    counter += lib(format, i, ap);
    return i;
}

int my_printf(const char * format , ...)
{
    int counter = 0;
    va_list ap;
    va_start(ap, format);
    counter += conditional(format, ap);
    va_end(ap);
    return counter;
}

int lib(const char *format, int i, va_list ap)
{
    int counter = 0;
    for (int f = 0; f <= 17; f++){
        if (flag_tab[f].c == format[i + 1]) {
            return flag_tab[f].ptr(ap);
        }
    }
    my_putstr(format);
    return counter ;
}

int lib2(const char *format, int i, va_list ap)
{
    int counter = 0;
    for (int f = 0; f <= 3; f++){
        if (flag_tab2[f].c == format[i + 1]) {
            return flag_tab2[f].ptr(ap);
        }
    }
    my_putstr(format);
    return counter ;
}

int lib3(const char *format, int i, va_list ap)
{
    int counter = 0;
    for (int f = 0; f <= 3; f++){
        if (flag_tab3[f].c == format[i + 1]) {
            return flag_tab3[f].ptr(ap);
        }
    }
    my_putstr(format);
    return counter ;
}
