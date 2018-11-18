/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** kill_duck
*/

#include <stdio.h>
#include "hunter.h"

void kill_duck(tool_t *tool)
{
    sfVector2i posi;
    int right_pos = tool->pos.x + 50;
    int left = tool->pos.x;
    int top = tool->pos.y;
    int down_pos = tool->pos.y + 50;

    if (sfMouse_isButtonPressed(sfMouseLeft) == true ||
                sfMouse_isButtonPressed(sfMouseRight) == true) {
        posi = sfMouse_getPosition(tool->window);
        if (posi.x >= left && posi.y <= right_pos && posi.y >= top &&
                posi.y <= down_pos) {
            sfSprite_setPosition(tool->blood, tool->pos);
            sfRenderWindow_drawSprite(tool->window, tool->blood, NULL);
            tool->duck_a = false;
            tool->duck_k++;
        }
    }
}