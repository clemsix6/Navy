/*
** EPITECH PROJECT, 2021
** B-PSU-101-MPL-1-1-navy-quentin.aumas
** File description:
** communication.c
*/

#include "include/com.h"

com_handler_t handler_data;

void send(pid_t pid, char *buffer)
{
    for (int i = 0; buffer[i] != 0; i++) {
        kill(pid, SIGUSR1);
        usleep(1000);
    }
    kill(pid, SIGUSR2);
    usleep(1000);
    for (int i = 0; buffer[i] != 0; i++) {
        for (int j = 0; j < buffer[i]; j++) {
            kill(pid, SIGUSR1);
            usleep(1000);
        }
        kill(pid, SIGUSR2);
        usleep(1000);
    }
}

void signal_handler(int signo, siginfo_t *siginfo,
                    __attribute__ ((unused)) void *context)
{
    if (signo == SIGUSR1)
        handler_data.count++;
    else if (signo == SIGUSR2)
        handler_data.loop = 1;
    handler_data.sender_pid = siginfo->si_pid;
}

int get_value(void)
{
    int tmp;
    struct sigaction s;

    handler_data.loop = 0;
    handler_data.count = 0;
    s.sa_flags = SA_SIGINFO;
    s.sa_sigaction = signal_handler;
    if (sigaction(SIGUSR1, &s, NULL) == -1 ||
        sigaction(SIGUSR2, &s, NULL) == -1)
        exit(84);
    while (handler_data.loop == 0) { }
    tmp = handler_data.count;
    return tmp;
}

com_result_t receive(void)
{
    com_result_t result;
    int size = get_value();
    char *str = malloc(size + 2);
    int i = 0;

    for (; i < size; i++)
        str[i] = (char)get_value();
    str[i] = 0;
    result.buffer = str;
    result.sender_pid = handler_data.sender_pid;
    usleep(1000);
    return result;
}

char *receive_from(pid_t pid)
{
    com_result_t result;

    do {
        result = receive();
    } while (result.sender_pid != pid);
    return result.buffer;
}