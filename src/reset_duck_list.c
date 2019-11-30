/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** reset_duck_list.c
*/

#include "my_hunter.h"

void reset_all_ducks(list_t *duck_list)
{
    while (duck_list != NULL) {
        duck_fly((duck_t *)(duck_list->data));
        duck_list = duck_list->next;
    }
}