/*
** EPITECH PROJECT, 2019
** Main window
** File description:
** Main for window
*/

#include <my_hunter.h>

static object_list_t *init_all_objects(char const *spritesheet)
{
    object_list_t *s = malloc(sizeof(object_list_t));

    s->duck = create_object(spritesheet, duck_info, 3);
    s->bg = create_object(spritesheet, background_info, 1);
    s->cursor = create_object(spritesheet, cursor_info, 1);
    s->hit[0] = create_object(spritesheet, hit_info[0], 1);
    s->hit[1] = create_object(spritesheet, hit_info[1], 1);
    return (s);
}

static void draw_all_objects(sfRenderWindow *window, object_list_t *object_list)
{
    sfColor bg_color = {94, 204, 236, 255};

    sfRenderWindow_clear(window, bg_color);
    sfRenderWindow_drawSprite(window, object_list->duck->sprite, NULL);
    sfRenderWindow_drawSprite(window, object_list->bg->sprite, NULL);
    sfRenderWindow_drawSprite(window, object_list->hit[0]->sprite, NULL);
    sfRenderWindow_drawSprite(window, object_list->hit[1]->sprite, NULL);
    sfRenderWindow_drawSprite(window, object_list->cursor->sprite, NULL);
    sfRenderWindow_display(window);
}

static void destroy_all_objects(object_list_t *object_list)
{
    destroy_object(object_list->duck);
    destroy_object(object_list->bg);
    destroy_object(object_list->cursor);
    destroy_object(object_list->hit[0]);
    destroy_object(object_list->hit[1]);
    free(object_list);
}

static void move_cursor(sfRenderWindow *window, object_t *cursor)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(window);
    float cursor_x = pos.x - (cursor_info.size.x / 2);
    float cursor_y = pos.y - (cursor_info.size.y / 2);
    sfVector2f cursor_pos = {cursor_x, cursor_y};

    sfSprite_setPosition(cursor->sprite, cursor_pos);
}

void my_hunter(sfRenderWindow *window)
{
    object_list_t *object_list = init_all_objects("img/spritesheet.png");
    duck_t duck;
    sfClock *clock = sfClock_create();

    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    init_duck(&duck, object_list->duck);
    while (sfRenderWindow_isOpen(window)) {
        move_cursor(window, object_list->cursor);
        analyse_events(window, &duck);
        draw_all_objects(window, object_list);
        move_object(object_list->duck, duck.move.x, duck.move.y);
        if (elapsed_time(100, clock))
            animate_duck(&duck);
    }
    destroy_all_objects(object_list);
}
