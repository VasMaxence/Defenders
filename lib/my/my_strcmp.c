/*
** EPITECH PROJECT, 2018
** MY_STRCMP
** File description:
** made by MAXENCE.V
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]) {
        i++;
    }
    return (i);
}

int my_cmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] == s2[i])
        i++;
    return (i);
}
