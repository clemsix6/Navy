/*
** EPITECH PROJECT, 2021
** my getnbr
** File description:
** my getnbr
*/

void my_putchar(char c);

int my_getnbr(char const *str)
{
    int i = 0;
    while (str[i] != 0){
        i += 1;
        if (47 < str[i] && str[i] < 57){
            my_putchar(str[i]);
        }
    }

    return (0);
}