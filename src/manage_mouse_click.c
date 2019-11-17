/*
** EPITECH PROJECT, 2019
** CSFML project
** File description:
** Manage mouse click
*/

#include <my_hunter.h>

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
    sfTexture const *texture;
    sfImage *image;
    sfColor pixel;
    int left = (object->pos).x;
    int right = (object->pos).x + (object->size).x;
    int top = (object->pos).y;
    int bottom = (object->pos).y + (object->size).y;

    if (event.x >= left && event.x <= right
    && event.y >= top && event.y <= bottom) {
        texture = sfSprite_getTexture(object->sprite);
        image = sfTexture_copyToImage(texture);
        pixel = sfImage_getPixel(image, event.x - left, event.y - top);
        return (pixel.a >= 127);
    }
    return (0);
}

void manage_mouse_click(sfMouseButtonEvent event, duck_t *duck)
{
    print_mouse_pos(event);
    if (mouse_collision(duck->object, event) && duck->status == 0)
        duck->status = 1;
}
