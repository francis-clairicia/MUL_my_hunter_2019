/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** duck_pos.c
*/

#include "my_hunter.h"

void default_duck_pos(duck_t *duck)
{
    sfVector2f position;

    position.x = (duck->fly->rect).width * (-1) * duck->id;
    position.y = rand() % 130;
    set_pos_object(duck->object, position);
}