/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** duck_speed.c
*/

#include "my_hunter.h"

void set_duck_speed(duck_t *duck, int speed)
{
    duck->speed = speed;
    duck->move.x = speed;
}

void set_all_ducks_speed(list_t *duck_list, int speed)
{
    while (duck_list != NULL) {
        set_duck_speed((duck_t *)(duck_list->data), speed);
        duck_list = duck_list->next;
    }
}