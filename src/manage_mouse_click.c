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

static int check_perfect_collision(object_t *object, int x, int y)
{
    sfImage *image = sfTexture_copyToImage(object->texture);
    sfVector2f scale = sfSprite_getScale(object->sprite);
    sfColor pixel;

    x = ((float)x / scale.x) + ((object->index_sprite - 1) * object->size.x);
    y = (float)y / scale.y;
    pixel = sfImage_getPixel(image, x, y);
    sfImage_destroy(image);
    return (pixel.a > 0);
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
        return (check_perfect_collision(object, event.x - left, event.y - top));
    return (0);
}

void manage_mouse_click(sfMouseButtonEvent event, pointers_t *ptrs)
{
    list_t *duck_list = ptrs->duck_list;
    duck_t *duck;

    print_mouse_pos(event);
    decrease_bullets(ptrs->shot);
    if (ptrs->shot->shot_remaining == 0)
        return;
    while (duck_list != NULL) {
        duck = (duck_t *)(duck_list->data);
        if (mouse_collision(duck->object, event) && duck->status == 0
        && !mouse_collision(ptrs->bg->scenery, event)) {
            duck->status = 1;
            increase_score(ptrs->score, 1);
        }
        duck_list = duck_list->next;
    }
}
