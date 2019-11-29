/*
** EPITECH PROJECT, 2019
** My Hunter
** File description:
** Sprite objects
*/

#include "my_hunter.h"

static const char *spritesheet = "img/spritesheet.png";

object_t *create_object(info_t info, int nb_sprites)
{
    object_t *object = malloc(sizeof(object_t));
    sfIntRect rect = {0, 0, info.rect.width / nb_sprites, info.rect.height};

    object->texture = sfTexture_createFromFile(spritesheet, &(info.rect));
    object->sprite = sfSprite_create();
    object->rect = rect;
    object->default_rect = object->rect;
    object->pos = info.position;
    object->size = info.size;
    object->index_sprite = 1;
    object->nb_sprites = nb_sprites;
    refresh_object(object);
    resize_object(object, object->size.x, object->size.y);
    sfSprite_setPosition(object->sprite, object->pos);
    return (object);
}

void destroy_object(object_t *object)
{
    sfTexture_destroy(object->texture);
    sfSprite_destroy(object->sprite);
    free(object);
}