/*
** EPITECH PROJECT, 2021
** my_strcmp
** File description:
** my_strcmp
*/

int my_strlen(char const *str);

int my_strcmp ( char const * s1 , char const * s2)
{
    for (int a = 0; a < my_strlen(s1); a++){
        if (s1[a] < s2[a])
        {
            return -1;
        }
        if (s1[a] > s2[a])
        {
            return 1;
        }
    }
    return 0;
}