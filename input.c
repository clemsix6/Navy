/*
** EPITECH PROJECT, 2021
** B
** File description:
** input.c
*/

#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

bool check_position(int x, int y, char *error_message)
{
    if (x >= 0 && x <= 7 && y >= 0 && y <= 7)
        return true;
    my_putstr(error_message);
    return false;
}

char *read_position(void)
{
    char *input = malloc(2);
    int size = 0;

    while (size != 2)
        size = read(1, input, 2);
    return input;
}

char *input_position(char *prefix, char *error_message, int *x, int *y)
{
    char *input;

    do {
        my_putstr(prefix);
        input = read_position();
        *x = input[0] - 'A';
        *y = input[1] - '1';
    } while (!check_position(*x, *y, error_message));
    return input;
}
