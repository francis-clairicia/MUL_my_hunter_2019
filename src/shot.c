/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** shot.c
*/

#include "my_hunter.h"

static const info_t shot_flag_info = {
    {498, 270, 26, 8}, {75, 20}, {75, 540}
};

static const info_t bullets_info = {
    {499, 261, 24, 8}, {20, 20}, {80, 518}
};

shot_t *init_shot(void)
{
    shot_t *shot = malloc(sizeof(shot_t));

    shot->shot_flag = create_object(shot_flag_info, 1);
    shot->bullets = create_object(bullets_info, 3);
    set_remaining_shots(shot, 3);
    return (shot);
}

void destroy_shot(shot_t *shot)
{
    destroy_object(shot->shot_flag);
    destroy_object(shot->bullets);
    free(shot);
}

void draw_shot(sfRenderWindow *window, shot_t *shot)
{
    draw_object(window, shot->bullets);
    draw_object(window, shot->shot_flag);
}

void decrease_bullets(shot_t *shot)
{
    set_remaining_shots(shot, shot->shot_remaining - 1);
}

void set_remaining_shots(shot_t *shot, int nb)
{
    int width = (shot->bullets->default_rect).width;

    if (nb < 0)
        return;
    shot->shot_remaining = nb;
    shot->bullets->rect.width = width * shot->shot_remaining;
    refresh_object(shot->bullets);
}