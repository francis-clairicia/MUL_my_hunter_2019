/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** manage_gameplay.c
*/

#include "my_hunter.h"

static int duck_out_of_screen(list_t *duck_list, int check_hit)
{
    duck_t *duck;
    int count = 0;

    while (duck_list != NULL) {
        duck = (duck_t *)(duck_list->data);
        if (check_hit)
            count += (duck->out_of_screen && duck->hit_value == 0);
        else
            count += (duck->out_of_screen);
        duck_list = duck_list->next;
    }
    return (count);
}

static void reset_all_ducks(list_t *duck_list)
{
    while (duck_list != NULL) {
        duck_fly((duck_t *)(duck_list->data));
        duck_list = duck_list->next;
    }
}

int manage_gameplay(pointers_t *ptrs)
{
    int duck_out = duck_out_of_screen(ptrs->duck_list, 0);
    int duck_not_touch = duck_out_of_screen(ptrs->duck_list, 1);

    if (duck_out == my_list_size(ptrs->duck_list)) {
        reset_all_ducks(ptrs->duck_list);
        set_remaining_shots(ptrs->shot, 3);
    }
    if (ptrs->life->nb_lifes)
        ptrs->life->nb_lifes -= duck_not_touch;
    return (ptrs->life->nb_lifes > 0);
}