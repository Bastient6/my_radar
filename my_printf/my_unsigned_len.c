/*
** EPITECH PROJECT, 2022
** printf
** File description:
** strlen unsigned
*/

unsigned int my_unsigned_len(char const *str)
{
    unsigned int i = 0;
    for (; str[i] != '\0' ; i ++);
    return i;
}
