/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** duck.c
*/

#include <my_hunter.h>

static void duck_fly(duck_t *duck)
{
    set_pos_object(duck->object, duck->default_pos.x, duck->default_pos.y);
    duck->object->default_rect = duck->rect_fly;
    duck->object->rect = duck->rect_fly;
    duck->object->index_sprite = 1;
    duck->object->nb_sprites = 3;
    (duck->move).x = 2;
    (duck->move).y = 0;
    duck->status = 0;
}

static void duck_hit(duck_t *duck)
{
    duck->object->default_rect = duck->rect_hit;
    duck->object->rect = duck->rect_hit;
    duck->object->index_sprite = 1;
    duck->object->nb_sprites = 1;
    (duck->move).x = 0;
    (duck->move).y = 0;
    duck->status = 2;
    duck->hit = 0;
}

static void duck_fall(duck_t *duck)
{
    duck->object->default_rect = duck->rect_fall;
    duck->object->rect = duck->rect_fall;
    duck->object->nb_sprites = 3;
    (duck->move).x = 0;
    (duck->move).y = 3;
    duck->status = 3;
}

void init_duck(duck_t *duck, object_t *object)
{
    sfIntRect rect_hit = {239, 175, 31, 32};
    sfIntRect rect_fall = {279, 173, 24, 33};

    duck->object = object;
    duck->default_pos = object->pos;
    duck->rect_fly = object->default_rect;
    duck->rect_hit = rect_hit;
    duck->rect_fall = rect_fall;
    duck_fly(duck);
}

void animate_duck(duck_t *duck)
{
    if (duck->status == 1)
        duck_hit(duck);
    if (duck->status == 2) {
        if (duck->hit == 3)
            duck_fall(duck);
        else
            duck->hit += 1;
    }
    if (duck->status == 3 && duck->object->pos.y >= 600)
        duck_fly(duck);
    animate_object(duck->object);
}