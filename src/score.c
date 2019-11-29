/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** score.c
*/

#include "my_hunter.h"

static const info_t hit_info = {
    {526, 270, 113, 18}, {353, 45}, {196, 516}
};

score_t *init_score(void)
{
    score_t *score = malloc(sizeof(score_t));

    score->hit_bar = create_object(hit_info, 1);
    score->duck_size = 8;
    score->width = 33;
    set_score(score, 0);
    return (score);
}

void destroy_score(score_t *score)
{
    destroy_object(score->hit_bar);
    free(score);
}

void increase_score(score_t *score, int number)
{
    set_score(score, score->duck_hit + number);
}

void set_score(score_t *score, int number)
{
    int duck_size = score->duck_size;

    if (number > 10)
        return;
    score->duck_hit = number;
    score->hit_bar->rect.width = score->width + (duck_size * score->duck_hit);
    refresh_object(score->hit_bar);
}

void draw_score(sfRenderWindow *window, score_t *score)
{
    draw_object(window, score->hit_bar);
}