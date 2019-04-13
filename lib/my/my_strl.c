/*
** EPITECH PROJECT, 2018
** my_strl
** File description:
** made by MAXENCE.V : 10/10/2018
*/

int my_strl(char const *str)
{
    int n = 0;

    while (str[n] != '\0') {
        n++;
    }
    return (n);
}
