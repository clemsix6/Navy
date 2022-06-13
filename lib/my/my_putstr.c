/*
** EPITECH PROJECT, 2021
** my putstr
** File description:
** my putstr
*/

void my_putchar(char c);

int my_putstr(char const *str)
{
    if (str[0] == '\0'){
        return 0;
    }
    my_putchar(str[0]);
    return my_putstr(str + 1);
}