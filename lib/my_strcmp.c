/*
** EPITECH PROJECT, 2018
** nf.sh
** File description:
** nf
*/

#include <unistd.h>

int my_strcmp(char const *s1, char const *s2)
{
    for (int i = 0; s1[i] && s2[i]; i++) {
        if (s1[i] != s2[i])
            return (s2[i] - s1[i]);
    }
    return (0);
}

void my_putstr(char *str)
{
    int i = 0;

    for (; str[i]; i++);
    write(1, str, i);
}