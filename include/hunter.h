/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** hunter
*/

#ifndef HUNTER_H_
#define HUNTER_H_

/* include */

#include <stdbool.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>

/* STRUCT */

typedef struct tool_s {
    int state_d;
    int live;
    int duck_k;
    int point;
    bool cheat;
    sfSprite *game_over;
    sfRenderWindow *window;
    sfVector2f pos;
    sfTexture **te_flappy;
    sfSprite *sprite;
    sfEvent event;
    sfSprite *blood;
    sfSprite *background;
    sfSprite **flappy;
    sfClock *clock;
    bool duck_a;
} tool_t;

/* FUNCTIONS */

int master(void);
void check_for_cheat(tool_t *tool);
void cheat_activited(tool_t *tool);
void kill_duck(tool_t *tool);
void duck_value(tool_t *tool);
void create_ducks(tool_t *tool);

/* Game Over */

void screen_game_over(tool_t *tool);
int load_game_over(tool_t *tool);

/* ERROR MANAGE */

int error_management(int ac, char **env);

/* Load ressources */

int master_load(tool_t *tool);

/* LIB */

int my_strcmp(char const *s1, char const *s2);
void my_putstr(char *str);

#endif /* !HUNTER_H_ */
