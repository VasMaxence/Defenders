/*
** EPITECH PROJECT, 2018
** MY_STRSTR
** File description:
** made by MAXENCE.V
*/

char *my_strstr(char *str, char const *to_find)
{
    char *str_find;
    int i = 0;
    int j = 0;
    int a = 0;

    while (str[i] != '\0') {
        while (str[i] == to_find[j] && str[i] != '\0') {
            str_find[a] = str[i];
            j++;
            i++;
            a++;
        }
        if (to_find[j] == '\0') {
            return (&str[(i - j)]);
        }
        i++;
    }
}
