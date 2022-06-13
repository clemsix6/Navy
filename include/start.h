/*
** EPITECH PROJECT, 2022
** Navy
** File description:
** start.h
*/

#ifndef NAVY_START_H
#define NAVY_START_H

void help(void);
void print_pid(void);
pid_t listen(void);
void connect(pid_t pid);
int start_player_1(char **av, char ***map, pid_t *pid, bool *turn);
int start_player_2(char **av, char ***map, pid_t *pid, bool *turn);

#endif //NAVY_START_H
