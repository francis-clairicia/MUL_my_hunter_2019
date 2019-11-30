/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** manage_gameplay.c
*/

#include "my_hunter.h"

static int duck_out_of_screen(list_t *duck_list, int check_hit, life_t *life)
{
    duck_t *duck;
    int count = 0;

    while (duck_list != NULL) {
        duck = (duck_t *)(duck_list->data);
        if (check_hit)
            count += (duck->out_of_screen && duck->status == 4);
        else
            count += (duck->out_of_screen);
        if (check_hit && duck->out_of_screen && duck->status == 4) {
            life->nb_lifes -= 1;
            duck->status = 3;
        }
        duck_list = duck_list->next;
    }
    return (count);
}

static void set_level(game_t *game)
{
    game->level += 1;
    if (game->level % 2 == 1 && game->level < 10)
        game->duck_nb += 1;
    if (game->level % 2 == 0 && game->level > 0 && game->level <= 10)
        game->duck_speed += 1;
}

int manage_gameplay(pointers_t *ptrs, game_t *game)
{
    int duck_out = duck_out_of_screen(ptrs->duck_list, 0, ptrs->life);

    duck_out_of_screen(ptrs->duck_list, 1, ptrs->life);
    if (duck_out == my_list_size(ptrs->duck_list)) {
        set_level(game);
        set_score(ptrs->score, game->level);
        reset_all_ducks(ptrs->duck_list);
    }
    if (((duck_t *)(ptrs->duck_list->data))->speed < game->duck_speed)
        set_all_ducks_speed(ptrs->duck_list, game->duck_speed);
    while (my_list_size(ptrs->duck_list) < game->duck_nb)
        add_duck_to_list(ptrs->duck_list, game->duck_speed);
    if (ptrs->life->nb_lifes < 0)
        ptrs->life->nb_lifes = 0;
    game->stop = (ptrs->life->nb_lifes == 0);
    return (0);
}