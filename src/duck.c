/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** duck.c
*/

#include "my_hunter.h"

static const info_t duck_info_fly = {
    {5, 170, 120, 37}, {90, 90}, {0, 0}
};

static const info_t duck_info_hit = {
    {239, 175, 31, 32}, {90, 90}, {0, 0}
};

static const info_t duck_info_fall = {
    {279, 173, 96, 33}, {65, 90}, {0, 0}
};

duck_t *init_duck(int speed, int id)
{
    duck_t *duck = malloc(sizeof(duck_t));

    duck->fly = create_object(duck_info_fly, 3);
    duck->hit = create_object(duck_info_hit, 1);
    duck->fall = create_object(duck_info_fall, 4);
    duck->sound = sfMusic_createFromFile("sound/duck.ogg");
    sfMusic_setLoop(duck->sound, sfTrue);
    duck->speed = speed;
    duck->id = id;
    duck_fly(duck);
    return (duck);
}

void destroy_duck(duck_t *duck)
{
    destroy_object(duck->fly);
    destroy_object(duck->hit);
    destroy_object(duck->fall);
    sfMusic_destroy(duck->sound);
    free(duck);
}

void animate_duck(duck_t *duck)
{
    if (duck->status == 2) {
        if (duck->hit_value >= 3)
            duck_fall(duck);
        else
            duck->hit_value += 1;
    }
    if (duck->status == 1)
        duck_hit(duck);
    animate_object(duck->object);
}

void move_duck(duck_t *duck, sfVector2u window_size)
{
    move_object(duck->object, (duck->move).x, (duck->move).y);
    if (duck->object->pos.x >= window_size.x) {
        duck->status = 4;
        duck_stop(duck);
    }
    if (duck->object->pos.y >= window_size.y)
        duck_stop(duck);
}

void draw_duck(sfRenderWindow *window, duck_t *duck)
{
    draw_object(window, duck->object);
}