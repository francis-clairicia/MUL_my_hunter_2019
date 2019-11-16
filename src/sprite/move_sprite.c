/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** move_sprite.c
*/

#include <my_hunter.h>

void move_sprite(sprite_t *s, float x_move, float y_move)
{
    sfVector2f offset = {x_move, y_move};

    sfSprite_move(s->sprite, offset);
}