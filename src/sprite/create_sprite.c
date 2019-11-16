/*
** EPITECH PROJECT, 2019
** My Hunter
** File description:
** Sprite objects
*/

#include <my_hunter.h>

sprite_t *create_sprite(char const *filepath, info_t info,
    int nb_sprites)
{
    sprite_t *s = malloc(sizeof(sprite_t));

    s->texture = sfTexture_createFromFile(filepath, NULL);
    s->sprite = sfSprite_create();
    sfSprite_setTexture(s->sprite, s->texture, sfFalse);
    sfSprite_setTextureRect(s->sprite, info.rect);
    s->rect = info.rect;
    s->default_left = info.rect.left;
    s->default_top = info.rect.top;
    s->index_sprite = 1;
    s->nb_sprites = nb_sprites;
    resize_sprite(s, info.size.x, info.size.y);
    return (s);
}

void destroy_sprite(sprite_t *s)
{
    sfTexture_destroy(s->texture);
    sfSprite_destroy(s->sprite);
    free(s);
}