/*
** EPITECH PROJECT, 2022
** printf
** File description:
** my_float_scient
*/

#include<stdarg.h>
#include<stdio.h>

int my_float_g(double nb);
int my_scient_g(double nb);

int power (double nb)
{
    int p = 0;
    while ( nb > 9){
        nb = nb / 10;
        p++;
    }
    while ( nb < 1){
        nb = nb * 10;
        p++;
    }
    return p;
}

int my_float_scient(double nb)
{
    int counter = 0;
    int p = 0;
    p += power(nb);
    if ( p <= 5) {
        counter += my_float_g(nb);
    } else {
        counter += my_scient_g(nb);
    }
    return counter;
}

void my_float_scient_my(va_list ap)
{
    my_float_scient(va_arg(ap, double));

}
