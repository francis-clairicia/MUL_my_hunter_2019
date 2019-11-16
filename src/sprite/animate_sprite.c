/*
** EPITECH PROJECT, 2019
** My Hunter
** File description:
** Sprite objects
*/

#include <my_hunter.h>

void animate_sprite(sprite_t *s)
{
    if (s->index_sprite < s->nb_sprites) {
        (s->rect).left += (s->rect).width;
        s->index_sprite += 1;
    } else {
        (s->rect).left = s->default_left;
        s->index_sprite = 1;
    }
    sfSprite_setTexture(s->sprite, s->texture, sfFalse);
    sfSprite_setTextureRect(s->sprite, s->rect);
}