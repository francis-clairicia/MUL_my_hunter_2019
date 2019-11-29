/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** duck_speed.c
*/

#include "my_hunter.h"

void set_duck_speed(duck_t *duck, int speed)
{
    duck->speed = speed;
    duck->move.x = speed;
}