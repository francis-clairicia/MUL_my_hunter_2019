/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** cursor.c
*/

#include "my_hunter.h"

static const info_t cursor_info = {
    {469, 259, 25, 23}, {23, 23}, {0, 0}
};

cursor_t *init_cursor(void)
{
    cursor_t *cursor = malloc(sizeof(cursor_t));
    sfVector2f origin;

    cursor->object = create_object(cursor_info, 1);
    origin.x = cursor->object->rect.width / 2;
    origin.y = cursor->object->rect.height / 2;
    sfSprite_setOrigin(cursor->object->sprite, origin);
    return (cursor);
}

void destroy_cursor(cursor_t *cursor)
{
    destroy_object(cursor->object);
    free(cursor);
}

void draw_cursor(sfRenderWindow *window, cursor_t *cursor)
{
    draw_object(window, cursor->object);
}

void move_cursor(cursor_t *cursor, sfVector2i pos)
{
    sfVector2f cursor_pos = {pos.x, pos.y};

    sfSprite_setPosition(cursor->object->sprite, cursor_pos);
}