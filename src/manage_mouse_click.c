/*
** EPITECH PROJECT, 2019
** CSFML project
** File description:
** Manage mouse click
*/

#include "my_hunter.h"

static void print_mouse_pos(sfMouseButtonEvent event)
{
    my_putstr("Mouse x = ");
    my_put_nbr(event.x);
    my_putstr(", y = ");
    my_put_nbr(event.y);
    my_putchar('\n');
}

static int mouse_collision(object_t *object, sfMouseButtonEvent event)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(object->sprite);
    int left = rect.left;
    int right = rect.left + rect.width;
    int top = rect.top;
    int bottom = rect.top + rect.height;

    if (event.x >= left && event.x <= right
    && event.y >= top && event.y <= bottom)
        return (1);
    return (0);
}

void manage_mouse_click(sfMouseButtonEvent event, pointers_t *ptrs)
{
    list_t *duck_list = ptrs->duck_list;
    duck_t *duck;

    print_mouse_pos(event);
    while (duck_list != NULL) {
        duck = (duck_t *)(duck_list->data);
        if (mouse_collision(duck->object, event) && duck->status == 0) {
            duck->status = 1;
            return;
        }
        duck_list = duck_list->next;
    }
}
