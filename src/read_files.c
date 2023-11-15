/*
** EPITECH PROJECT, 2022
** bsq
** File description:
** read files
*/
    #include <stdlib.h>
    #include <sys/types.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <errno.h>
    #include "my.h"

char *read_file(char const * filepath)
{
    struct stat info;
    stat(filepath, &info);
    int fd = open(filepath, O_RDONLY);
    int size = info.st_size;
    char *buffer = malloc((size + 1) * sizeof(char));
    read(fd, buffer, size);
    buffer[size] = '\0';
    return buffer;
}
