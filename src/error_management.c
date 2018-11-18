/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** error_management
*/

#include "hunter.h"

char const *display = "DISPLAY=:1";

int error_management(int ac, char **env)
{
    int check = 0;

    if (ac != 1)
        return (84);
    for (int i = 0; env[i]; i++)
        if (my_strcmp(display, env[i]) == 0)
            check++;
    if (check == 0)
        return (84);
    return (0);
}