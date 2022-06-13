/*
** EPITECH PROJECT, 2021
** my put nbr
** File description:
** my put nbr
*/

void my_putchar(char c);

void my_put_nbr(int nb)
{
    int tmp;
    tmp = nb;

    if (tmp < 0){
        nb = -tmp;
        my_putchar('-');
    }
    if (nb > 9){
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    }else{
        my_putchar(nb + '0');
    }
}