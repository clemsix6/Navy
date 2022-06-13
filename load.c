/*
** EPITECH PROJECT, 2021
** load
** File description:
** load
*/

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "include/map.h"
#include "include/my.h"

char *load_file_in_mem_read(int fd)
{
    char *buffer = malloc(sizeof(char) * 32);
    int index;
    index = read(fd, buffer, 32);
    if (index == -1){
        return NULL;
    }
    buffer[index] = 0;
    return buffer;
}

char *load_file_in_mem(int fd)
{
    char *buffer;

    buffer = load_file_in_mem_read(fd);
    if (buffer == NULL){
        return NULL;
    }
    return buffer;
}

char **load_pos_map(char *path_name)
{
    int fd = open(path_name, O_RDONLY);
    char *file_content = load_file_in_mem(fd);
    if (file_content == NULL){
        return NULL;
    }
    char **map_result = map_to_array(file_content, 4, 7);
    return map_result;
}