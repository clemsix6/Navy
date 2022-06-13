/*
** EPITECH PROJECT, 2021
** test_loop
** File description:
** test_loop
*/

#include <stdbool.h>
#include "include/navy.h"
#include "include/com.h"

int test_for_enemy_win(char **map, pid_t remote)
{
    usleep(1000);
    if (test_map(map)) {
        my_putstr("Enemy won\n\n");
        send(remote, "1");
        return 1;
    }
    send(remote, "0");
    return -1;
}

int test_for_remote_win(pid_t remote)
{
    char *result = receive_from(remote);

    if (result[0] == '1') {
        my_putstr("I won\n\n");
        return 0;
    }
    return -1;
}

int test_for_end(char **map, pid_t remote, bool turn)
{
    int ret_0;
    int ret_1;

    if (turn) {
        ret_0 = test_for_enemy_win(map, remote);
        ret_1 = test_for_remote_win(remote);
    } else {
        ret_1 = test_for_remote_win(remote);
        ret_0 = test_for_enemy_win(map, remote);
    }

    if (ret_0 == 1)
        return 1;
    if (ret_1 == 0)
        return 0;
    return -1;
}