/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** move_object.c
*/

#include <my_hunter.h>

void move_object(object_t *object, float x_move, float y_move)
{
    sfVector2f offset = {x_move, y_move};

    sfSprite_move(object->sprite, offset);
    object->pos = sfSprite_getPosition(object->sprite);
}

void set_pos_object(object_t *object, float x, float y)
{
    sfVector2f position = {x, y};

    sfSprite_setPosition(object->sprite, position);
    object->pos = position;
}