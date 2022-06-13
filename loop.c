/*
** EPITECH PROJECT, 2021
** B-PSU-101-MPL-1-1-navy-quentin.aumas
** File description:
** loop.c
*/

#include <stdbool.h>
#include "include/navy.h"
#include "include/com.h"
#include "include/map.h"

void local_play(pid_t remote, char **shoot_map)
{
    char error_message[] = "wrong position\n";
    char prefix[] = "attack: ";
    char *input;
    char *response;
    int x = 0;
    int y = 0;

    input = input_position(prefix, error_message, &x, &y);
    send(remote, input);
    response = receive_from(remote);
    my_putstr(input);
    my_putstr(": ");
    my_putstr(response);
    if (my_strcmp(response, "missed\n\n") == 0)
        shoot_map[y][x] = 'o';
    else
        shoot_map[y][x] = 'x';
}

void remote_play(pid_t remote, char **map)
{
    char hit[] = "hit\n\n";
    char missed[] = "missed\n\n";
    char *input;
    int x;
    int y;

    my_putstr("waiting for enemy’s attack...\n");
    input = receive_from(remote);
    x = input[0] - 'A';
    y = input[1] - '1';
    my_putstr(input);
    my_putstr(": ");
    if (map[y][x] != '.') {
        map[y][x] = 'x';
        my_putstr(hit);
        send(remote, hit);
    } else {
        map[y][x] = 'o';
        my_putstr(missed);
        send(remote, missed);
    }
}

bool test_map(char **map)
{
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (map[j][i] != '.' && map[j][i] != 'x' && map[j][i] != 'o')
                return false;
        }
    }

    return true;
}

int loop(char **map, pid_t remote, bool turn)
{
    char **shoot_map = map_with_point();
    int win;

    while (1) {
        print_my_position(map);
        print_enemy_position(shoot_map);
        win = test_for_end(map, remote, turn);
        if (win != -1)
            return win;
        if (turn) {
            local_play(remote, shoot_map);
            remote_play(remote, map);
        }
        else {
            remote_play(remote, map);
            local_play(remote, shoot_map);
        }
    }
}