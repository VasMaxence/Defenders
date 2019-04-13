/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** made by MAXENCE.V : 11/10/2018
*/

#ifndef MY_HEADERS

#define MY_HEADERS

void print_usage(char *folder);
int binary(int nb);
int hexadecimal_maj(int nb);
int hexadecimal_min(int nb);
int purcent(int);
void my_putchar_print(int);
int adress(unsigned long adress);
int octal(int nb);
int non_printable(char *str);
int my_putstr_print(char *str);
int my_put_nbr_print(int nb);
int nbr_unsigned(unsigned int nb);
int my_sign_str(char *str);
void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
int my_printf(char *, ...);

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#endif
