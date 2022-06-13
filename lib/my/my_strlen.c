/*
** EPITECH PROJECT, 2021
** my_strlen
** File description:
** my_strlen
*/

int my_strlen(char const *str)
{
    if (str[0] == '\0'){
        return 0;
    }
    return 1 + my_strlen(str + 1);
}