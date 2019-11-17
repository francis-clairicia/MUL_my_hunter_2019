/*
** EPITECH PROJECT, 2019
** My Hunter
** File description:
** Sprite objects
*/

#include <my_hunter.h>

object_t *create_object(char const *filepath, info_t info,
    int nb_sprites)
{
    object_t *object = malloc(sizeof(object_t));

    object->texture = sfTexture_createFromFile(filepath, NULL);
    object->sprite = sfSprite_create();
    object->rect = info.rect;
    object->default_rect = info.rect;
    object->pos = info.position;
    object->size = info.size;
    object->index_sprite = 1;
    object->nb_sprites = nb_sprites;
    sfSprite_setTexture(object->sprite, object->texture, sfFalse);
    sfSprite_setTextureRect(object->sprite, info.rect);
    resize_object(object, info.size.x, info.size.y);
    sfSprite_setPosition(object->sprite, info.position);
    return (object);
}

void destroy_object(object_t *object)
{
    sfTexture_destroy(object->texture);
    sfSprite_destroy(object->sprite);
    free(object);
}