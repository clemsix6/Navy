/*
** EPITECH PROJECT, 2021
** Navy
** File description:
** com.h
*/

#ifndef NAVY_COM_H
#define NAVY_COM_H

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct com_handler_s {
    int count;
    int loop;
    pid_t sender_pid;
} com_handler_t;

typedef struct com_result_s {
    pid_t sender_pid;
    char *buffer;
} com_result_t;

void send(pid_t pid, char *buffer);
com_result_t receive(void);
char *receive_from(pid_t pid);
int test_for_enemy_win(char **map, pid_t remote);
int test_for_remote_win(pid_t remote);
int test_for_end(char **map, pid_t remote, bool turn);
bool test_map(char **map);
void print_my_position(char **map);
void print_enemy_position(char **shoot_map);

#endif //NAVY_COM_H
