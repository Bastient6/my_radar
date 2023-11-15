/*
** EPITECH PROJECT, 2022
** printf
** File description:
** flag.h
*/

#include<stdarg.h>
#ifndef FLAG_H_
    #define FLAG_H_
int my_putnbr_base_b_my(va_list ap);
int my_putnbr_base_x_my(va_list ap);
int my_putnbr_base_o_my(va_list ap);
int my_putnbr_base_u_my(va_list ap);
int my_put_nbr_my(va_list ap);
int my_putstr_my(va_list ap);
int my_putchar_my(va_list ap);
int my_putstr_not_my(va_list ap);
int my_float_f_my(va_list ap);
int my_scient_my(va_list ap);
int my_float_scient_my(va_list ap);
int my_putchar_p_my(va_list ap);
int my_long_putnbr_my(va_list ap);
int my_putnbr_base_o_h_my(va_list ap);
int my_long_putnbr_base_x_my(va_list ap);
int my_long_putnbr_base_o_my(va_list ap);
int my_long_putnbr_base_u_my(va_list ap);
int my_putnbr_base_x_h_my(va_list ap);
int my_putnbr_base_xx_h_my(va_list ap);
int my_sign_put_nbr_my(va_list ap);

typedef struct flag_s {
    char c;
    int (*ptr)(va_list);
}flag_t;

#endif
