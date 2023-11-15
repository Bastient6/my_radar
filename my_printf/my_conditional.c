/*
** EPITECH PROJECT, 2022
** printf
** File description:
** conditional
*/
#include<stdarg.h>
int disp2(const char *format, int i, va_list ap);
int lib(const char *format, int i, va_list ap);
int disp(const char *format, int i, va_list ap);
int my_putchar(char c);

int conditional(const char *format, va_list ap)
{
    int counter = 0;
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%'){
            disp2(format, i, ap); i++; continue;
        }
        if (format[i] == '%') {
            disp(format, i, ap); i++; continue;
        }
        if (format[i] == '%') {
            counter += lib(format, i, ap); continue;
        }
        if (format[i - 2] == '%' && (format[i - 1] == '#'
        || format[i - 1] == 'l' || format[i - 1] == '+')){
        } else {
            my_putchar(format[i]); counter ++;
        }
    }
    return counter;
}
