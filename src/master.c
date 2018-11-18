/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** master
*/

#include <stdlib.h>
#include "hunter.h"

void print_duck(tool_t *tool)
{
    if (sfTime_asMicroseconds(sfClock_getElapsedTime(tool->clock)) > 75000) {
        create_ducks(tool);
        duck_value(tool);
        sfClock_restart(tool->clock);
    }
    sfSprite_setPosition(tool->flappy[tool->state_d], tool->pos);
    sfRenderWindow_drawSprite(tool->window, tool->flappy[tool->state_d], NULL);
}

void screen(tool_t *tool)
{
    sfRenderWindow_display(tool->window);
    sfRenderWindow_drawSprite(tool->window, tool->background, NULL);
    print_duck(tool);
    kill_duck(tool);
    if (tool->cheat == false)
        check_for_cheat(tool);
    if (tool->cheat == true)
        cheat_activited(tool);
    while (sfRenderWindow_pollEvent(tool->window, &tool->event))
            if (tool->event.type == sfEvtClosed)
                sfRenderWindow_close(tool->window);
}

int master(void)
{
    tool_t *tool = malloc(sizeof(tool_t));
    sfMusic* music = sfMusic_createFromFile("./Music/NyanCatoriginal.ogg");

    if (tool == NULL || music == NULL || master_load(tool) == 84)
        return (84);
    sfVideoMode mode = {1920, 1080, 32};
    tool->window = sfRenderWindow_create(mode, "CSFML = cancer",
            sfResize | sfClose, NULL);
    sfWindow_setFramerateLimit(tool->window, 60);
    sfMusic_play(music);
    while (sfRenderWindow_isOpen(tool->window)) {
        if (tool->live >= 0)
            screen(tool);
        else
            screen_game_over(tool);
    }
    sfMusic_destroy(music);
    free(tool);
    return (0);
}