/*
** EPITECH PROJECT, 2018
** MY_SORT_IN_ARRAY
** File description:
** made by MAXENCE.V
*/

#include "my.h"

void my_sort_int_array(int *array, int size)
{
    int n;
    int i;
    int z = 1;

    while (z) {
        i = 0;
        z = 0;
        while (i < size) {
            if (array[i] > array[i + 1]) {
                z = 1;
                my_swap(&array[i], &array[i + 1]);
            }
            i++;
        }
    }
}
