/*
** EPITECH PROJECT, 2022
** Navy
** File description:
** start.c
*/

#include <stdlib.h>
#include <stdbool.h>
#include "include/navy.h"
#include "include/start.h"

char **try_load_map(char *file)
{
    char **map = initialize_map(file);

    if (map == NULL)
        return 84;
    return map;
}

int start_player_1(char **av, char ***map, pid_t *pid, bool *turn)
{
    if (av[1][0] == '-' && av[1][1] == 'h'){
        help();
        return 0;
    }
    *map = try_load_map(av[1]);
    *pid = listen();
    *turn = true;
    return 0;
}

int start_player_2(char **av, char ***map, pid_t *pid, bool *turn)
{
    *map = try_load_map(av[1]);
    if (*map == NULL)
        return 84;
    *pid = (int)my_atoi(av[2]);
    *turn = false;
    connect(*pid);
    return 0;
}