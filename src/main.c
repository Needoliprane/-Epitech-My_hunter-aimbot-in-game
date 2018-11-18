/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** main
*/

#include <stdlib.h>
#include <time.h>
#include "hunter.h"

char const *cheat = "Sorry i am a noob";

int print_cheat(void)
{
    my_putstr("-----Welcome to my_aimbot-----\n");
    my_putstr("You are a noob, It is nice to admit it !\n");
    my_putstr("Now click on the cloud on the right and enjoy the easy way\n");
    my_putstr("---- Warning -----\n");
    my_putstr("The cheat control your mouse. So impossible to use it");
    my_putstr(", you will need to wait the end of the game to use it");
    my_putstr(" again\n");
    return (0);
}

int print_help(char *str)
{
    if (my_strcmp(str, cheat) == 0)
        return (print_cheat());
    my_putstr("My_hunter\nSomewhere there is a cheat button, will you");
    my_putstr("find it ?\n10 lives\nUnlimited ducks to kill\n");
    my_putstr("Good luck have fun\n");
    my_putstr("if you want to try the cheat launch the binary like that :\n");
    my_putstr("./my_hunter \"Sorry i am a noob\"\n");
    return (0);
}

int main(int ac, char **argv, char **env)
{
    if (ac == 2)
        return (print_help(argv[1]));
    if (error_management(ac, env) == 84)
        return (84);
    srand(time(NULL));
    return (master());
}