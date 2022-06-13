/*
** EPITECH PROJECT, 2021
** Navy
** File description:
** map.h
*/

#ifndef NAVY_MAP_H
#define NAVY_MAP_H

char **initialize_map(char *path_name);
void print_map(char **map);
char **map_with_point(void);
void print_map(char **map);
char *load_file_in_mem_read(int fd);
char *load_file_in_mem(int fd);
char **load_pos_map(char *path_name);
char **map_to_array(char *file_content, int line_count, int column_count);

#endif //NAVY_MAP_H
