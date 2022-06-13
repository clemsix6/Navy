/*
** EPITECH PROJECT, 2021
** print
** File description:
** print
*/

#include "include/navy.h"
#include "include/com.h"
#include "include/map.h"

void print_my_position(char **map)
{
    my_putstr("my positions:\n");
    print_map(map);
    my_putstr("\n\n");
}

void print_enemy_position(char **shoot_map)
{
    my_putstr("enemy’s positions:\n");
    print_map(shoot_map);
    my_putstr("\n\n");
}

void print_map_char(char *file_content)
{
    for (int i = 0; i < 8; i++){
        my_putchar(file_content[i]);
        my_putchar(' ');
    }
}

void print_map(char **map)
{
    my_putstr(" |A B C D E F G H\n");
    my_putstr("-+---------------\n");
    my_putstr("1|");
    print_map_char(map[0]);
    my_putstr("\n2|");
    print_map_char(map[1]);
    my_putstr("\n3|");
    print_map_char(map[2]);
    my_putstr("\n4|");
    print_map_char(map[3]);
    my_putstr("\n5|");
    print_map_char(map[4]);
    my_putstr("\n6|");
    print_map_char(map[5]);
    my_putstr("\n7|");
    print_map_char(map[6]);
    my_putstr("\n8|");
    print_map_char(map[7]);
}