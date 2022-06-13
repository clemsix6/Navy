/*
** EPITECH PROJECT, 2021
** navy
** File description:
** navy
*/

#ifndef navy
#define navy

#include "my.h"
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

char *load_map(char *filename);
int map_count_lines(char *buffer, char const *filepath);
int map_count_columns(char *buffer);
char ** mem_alloc_2d_array(int nb_rows, int nb_cols);
char ** load_2d_arr_from_file (char *buffer, int nb_rows, int nb_cols);
char *input_position(char *prefix, char *error_message, int *x, int *y);
char **initialize_map(char *path_name);
int loop(char **map, pid_t remote, bool turn);
int my_atoi(char const *str);

#endif /* !navy */
