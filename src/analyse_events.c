/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** Event handler
*/

#include "my_hunter.h"

static void manage_key_press(sfKeyEvent event, pointers_t *ptrs, game_t *game)
{
    if (event.code == sfKeySpace && game->stop) {
        reset_all_ducks(ptrs->duck_list);
        ptrs->life->nb_lifes = game->default_nb_lifes;
        set_score(ptrs->score, 1);
        destroy_duck_list(ptrs->duck_list);
        ptrs->duck_list = my_list(1, (long)init_duck(game->default_speed, 1));
        game->duck_nb = 1;
        game->duck_speed = game->default_speed;
        game->stop = 0;
        game->level = 1;
    }
}

void analyse_events(sfRenderWindow *window, pointers_t *ptrs, game_t *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtMouseButtonPressed)
            manage_mouse_click(event.mouseButton, ptrs);
        if (event.type == sfEvtKeyPressed)
            manage_key_press(event.key, ptrs, game);
    }
    move_duck_list(ptrs->duck_list, sfRenderWindow_getSize(window));
    move_cursor(ptrs->cursor, sfMouse_getPositionRenderWindow(window));
}
