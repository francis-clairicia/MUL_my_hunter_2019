/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** duck_status.c
*/

#include "my_hunter.h"

static void change_duck(duck_t *duck, object_t *object)
{
    sfVector2f pos = sfSprite_getPosition(duck->object->sprite);

    duck->object = object;
    set_pos_object(duck->object, pos);
}

void duck_fly(duck_t *duck)
{
    duck->out_of_screen = 0;
    duck->object = duck->fly;
    default_duck_pos(duck);
    sfMusic_play(duck->sound);
    (duck->move).x = duck->speed;
    (duck->move).y = 0;
    duck->status = 0;
    duck->hit_value = 0;
}

void duck_hit(duck_t *duck)
{
    change_duck(duck, duck->hit);
    sfMusic_stop(duck->sound);
    (duck->move).x = 1;
    (duck->move).y = 0;
    duck->status = 2;
    duck->hit_value = 1;
}

void duck_fall(duck_t *duck)
{
    change_duck(duck, duck->fall);
    (duck->move).x = 0;
    (duck->move).y = 5;
    duck->status = 3;
}

void duck_stop(duck_t *duck)
{
    (duck->move).x = 0;
    (duck->move).y = 0;
    duck->out_of_screen = 1;
    sfMusic_stop(duck->sound);
}