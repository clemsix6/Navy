/*
** EPITECH PROJECT, 2021
** map_loading
** File description:
** map_loading
*/

#include <stdlib.h>
#include <unistd.h>
#include "include/my.h"
#include "include/map.h"

char **allocate_array(int l, int c)
{
    char **arr = malloc(sizeof(char *) * l);

    for (int i = 0; i < l; i++) {
        arr[i] = malloc(c);
    }
    return arr;
}

char **map_to_array(char *file_content, int line_count, int column_count)
{
    char **arr = allocate_array(line_count, column_count);
    int i = 0;
    int x = 0;
    int y = 0;
    for (; file_content[i] != 0; i++) {
        arr[y][x] = file_content[i];
        x++;
        if (file_content[i] == '\n') {
            x = 0;
            y++;
        }
    }
    free(file_content);
    return arr;
}

void map_initialize(char **map, char *pos_map)
{
    int x1 = pos_map[2] - 'A';
    int y1 = pos_map[3] - '0' - 1;
    int x2 = pos_map[5] - 'A';
    int y2 = pos_map[6] - '0' - 1;
    int nb_boat = pos_map[0];

    for (int i = y1; i <= y2; i++){
        for (int j = x1; j <= x2; j++){
            map[i][j] = nb_boat;
        }
    }
}

char **map_with_point(void)
{
    char **map_with_point = malloc(sizeof(char *)* 8);
    for (int i = 0; i < 8; i++){
        map_with_point[i] = malloc(sizeof(char)* 8);
        for (int j = 0; j < 8; j++){
            map_with_point[i][j] = '.';
        }
    }

    return map_with_point;
}

char **initialize_map(char *path_name)
{
    char **pos_map = load_pos_map(path_name);
    if (pos_map == NULL){
        return NULL;
    }
    char **map_result = map_with_point();

    for (int i = 0; i < 4; i++){
        map_initialize(map_result, pos_map[i]);
    }
    return map_result;
}