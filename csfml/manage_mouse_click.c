/*
** EPITECH PROJECT, 2019
** CSFML project
** File description:
** Manage mouse click
*/

#include <my.h>
#include <csfml.h>

void manage_mouse_click(sfMouseButtonEvent event)
{
    my_putstr("Mouse x = ");
    my_put_nbr(event.x);
    my_putstr(" y = ");
    my_put_nbr(event.y);
    my_putchar('\n');
}
