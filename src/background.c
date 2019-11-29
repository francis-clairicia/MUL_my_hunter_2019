/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** background.c
*/

#include "my_hunter.h"

static const info_t background_info = {
    {383, 5, 256, 240}, {size_window.x, size_window.y}, {0, 0}
};

static const info_t hit_info = {
    {526, 250, 113, 18}, {353, 45}, {196, 516}
};

background_t *init_background(void)
{
    background_t *bg = malloc(sizeof(background_t));

    bg->scenery = create_object(background_info, 1);
    bg->hit_bar = create_object(hit_info, 1);
    return (bg);
}

void destroy_background(background_t *bg)
{
    destroy_object(bg->scenery);
    destroy_object(bg->hit_bar);
    free(bg);
}

void draw_background(sfRenderWindow *window, background_t *bg)
{
    draw_object(window, bg->scenery);
    draw_object(window, bg->hit_bar);
}