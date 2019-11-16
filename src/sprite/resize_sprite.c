/*
** EPITECH PROJECT, 2019
** My Hunter
** File description:
** Sprite objects
*/

#include <my_hunter.h>

void resize_sprite(sprite_t *s, float width, float height)
{
    float x_scale = width / (s->rect).width;
    float y_scale = height / (s->rect).height;
    sfVector2f scale = {x_scale, y_scale};

    sfSprite_scale(s->sprite, scale);
}