/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** game_over
*/

#include "hunter.h"

int load_game_over(tool_t *tool)
{
    sfTexture *texture;
    const sfIntRect area = {790, 115, 200, 45};

    texture = sfTexture_createFromFile("./sprite/sprite_sheet.png", &area);
    tool->game_over = sfSprite_create();
    sfSprite_setTexture(tool->game_over, texture, sfTrue);
    return (0);
}

void screen_game_over(tool_t *tool)
{
    sfVector2f pos;
    pos.x = 800;
    pos.y = 550;
    sfRenderWindow_display(tool->window);
    sfRenderWindow_drawSprite(tool->window, tool->background, NULL);
    sfSprite_setPosition(tool->game_over, pos);
    sfRenderWindow_drawSprite(tool->window, tool->game_over, NULL);
    if (sfMouse_isButtonPressed(sfMouseLeft) == true) {
        tool->live = 10;
        tool->cheat = false;
    }
}