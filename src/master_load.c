/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** master_load
*/

#include <stdlib.h>
#include <stdio.h>
#include "hunter.h"

int load_blood(tool_t *tool)
{
    sfTexture *texture;
    const sfIntRect area = {242, 42, 50, 50};

    texture = sfTexture_createFromFile("./sprite/Blood.png", &area);
    tool->blood = sfSprite_create();
    sfSprite_setTexture(tool->blood, texture, sfTrue);
    return (0);
}

int fill_flappy_n(tool_t *tool)
{
    tool->flappy = malloc(sizeof(sfSprite *) * 3);
    if (tool->flappy == NULL)
        return (84);
    tool->flappy[0] = sfSprite_create();
    tool->flappy[1] = sfSprite_create();
    tool->flappy[2] = sfSprite_create();
    sfSprite_setTexture(tool->flappy[0], tool->te_flappy[0], sfTrue);
    sfSprite_setTexture(tool->flappy[1], tool->te_flappy[1], sfTrue);
    sfSprite_setTexture(tool->flappy[2], tool->te_flappy[2], sfTrue);
    return (0);
}

int fill_flappy(tool_t *tool)
{
    const sfIntRect area1 = {0, 980, 50, 50};
    const sfIntRect area2 = {50, 980, 50, 50};
    const sfIntRect area3 = {100, 980, 50, 50};

    tool->te_flappy = malloc(sizeof(sfTexture *) * 3);
    if (tool->te_flappy == NULL)
        return (84);
    tool->te_flappy[0] = sfTexture_createFromFile("./sprite/sprite_sheet.png",
            &area1);
    tool->te_flappy[1] = sfTexture_createFromFile("./sprite/sprite_sheet.png",
            &area2);
    tool->te_flappy[2] = sfTexture_createFromFile("./sprite/sprite_sheet.png",
            &area3);
    if (fill_flappy_n(tool) == 84)
        return (84);
    return (0);
}

void my_memset(tool_t *tool)
{
    tool->duck_a = false;
    tool->cheat = false;
    tool->state_d = 0;
    tool->duck_k = 0;
    tool->live = 2;
}

int master_load(tool_t *tool)
{
    my_memset(tool);
    tool->clock = sfClock_create();
    sfTexture *text = sfTexture_createFromFile("./sprite/Background.png", NULL);
    if (fill_flappy(tool) == 84)
        return (84);
    tool->background = sfSprite_create();
    sfSprite_setTexture(tool->background, text, sfTrue);
    if (load_blood(tool) == 84 || load_game_over(tool) == 84)
        return (84);
    return (0);
}