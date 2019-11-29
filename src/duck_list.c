/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** duck_list.c
*/

#include "my_hunter.h"

void add_duck_to_list(list_t *duck_list, int duck_speed)
{
    my_put_in_list(&duck_list, (long)init_duck(duck_speed));
}

void move_duck_list(list_t *duck_list, sfVector2u window_size)
{
    duck_t *duck;

    while (duck_list != NULL) {
        duck = (duck_t *)(duck_list->data);
        if (!duck->out_of_screen)
            move_duck(duck, window_size);
        duck_list = duck_list->next;
    }
}

void animate_duck_list(list_t *duck_list)
{
    duck_t *duck;

    while (duck_list != NULL) {
        duck = (duck_t *)(duck_list->data);
        if (!duck->out_of_screen)
            animate_duck(duck);
        duck_list = duck_list->next;
    }
}

void draw_duck_list(sfRenderWindow *window, list_t *duck_list)
{
    duck_t *duck;

    while (duck_list != NULL) {
        duck = (duck_t *)(duck_list->data);
        if (!duck->out_of_screen)
            draw_duck(window, duck);
        duck_list = duck_list->next;
    }
}

void destroy_duck_list(list_t *duck_list)
{
    list_t *node = duck_list;

    while (node != NULL) {
        destroy_duck((duck_t *)(node->data));
        node = node->next;
    }
    my_free_list(&duck_list, 0);
}