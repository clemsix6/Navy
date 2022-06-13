/*
** EPITECH PROJECT, 2021
** navy
** File description:
** navy's main file
*/

#include <stdlib.h>
#include <stdbool.h>
#include "navy.h"
#include "com.h"
#include "start.h"

void help(void)
{
    my_putstr("USAGE\n"
    "./navy [first_player_pid] navy_positions\n"
    "DESCRIPTION\n"
    "first_player_pid: only for the 2nd player. "
    "pid of the first player.\n"
    "navy_positions: file representing the positions of the ships.");
}

void print_pid(void)
{
    pid_t pid = getpid();

    my_putstr("my_pid: ");
    my_put_nbr((int)pid);
    my_putchar('\n');
}

pid_t listen(void)
{
    com_result_t result;
    char buffer[] = "6";

    print_pid();
    my_putstr("waiting for enemy connection...\n\n");
    do {
        result = receive();
        usleep(100);
    } while (result.buffer[0] != '6');
    usleep(1000);
    send(result.sender_pid, buffer);
    my_putstr("enemy connected\n\n");
    return result.sender_pid;
}

void connect(pid_t pid)
{
    com_result_t result;
    char buffer[] = "6";

    print_pid();
    do {
        send(pid, buffer);
        result = receive();
    } while (result.buffer[0] != '6');
    my_putstr("successfully connected\n\n");
}


int main(int argc, char **argv)
{
    int ret = 0;
    char **map;
    pid_t pid;
    bool turn;

    if (argc < 2 || argc > 3)
        return(84);
    if (argc == 2)
        ret = start_player_1(argv, &map, &pid, &turn);
    else
        ret = start_player_2(argv, &map, &pid, &turn);
    if (ret != 0)
        return ret;
    return loop(map, pid, turn);
}