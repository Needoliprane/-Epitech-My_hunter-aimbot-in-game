/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** duck
*/

#include <stdlib.h>
#include "hunter.h"

void check_for_cheat(tool_t *tool)
{
    sfVector2i posi;

    if (sfMouse_isButtonPressed(sfMouseLeft) == true ||
                sfMouse_isButtonPressed(sfMouseRight) == true) {
        posi = sfMouse_getPosition(tool->window);
        if (posi.x >= 1332 && posi.x <= 1400 && posi.y >= 500 &&
                posi.y <= 570) {
            tool->cheat = true;
            tool->live = 2;
        }
    }
}
void cheat_activited(tool_t *tool)
{
    int x = tool->pos.x;
    int y = tool->pos.y;
    sfVector2i pos;

    pos.x = x + 10;
    pos.y = y + 10;
    sfMouse_setPosition(pos, tool->window);
}

void duck_value(tool_t *tool)
{
    if (tool->duck_a == true)
        tool->pos.x += 25;
    tool->state_d++;
    if (tool->state_d >= 3)
        tool->state_d = 0;
    if (tool->pos.x >= 1920) {
        tool->live--;
        tool->duck_a = false;
    }
    if ((rand() % 10) % 2 == 0)
        tool->pos.y -= 25;
    else
        tool->pos.y += 25;
}

void create_ducks(tool_t *tool)
{
    if (tool->duck_a == false) {
        tool->pos.x = 0;
        tool->pos.y = rand() % 650;
        tool->pos.y += 50;
        tool->duck_a = true;
    }
}