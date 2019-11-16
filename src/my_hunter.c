/*
** EPITECH PROJECT, 2019
** Main window
** File description:
** Main for window
*/

#include <my_hunter.h>

static sprite_list_t *init_all_sprites(char const *spritesheet)
{
    sprite_list_t *s = malloc(sizeof(sprite_list_t));

    s->duck = create_sprite(spritesheet, duck_info, 3);
    s->bg = create_sprite(spritesheet, background_info, 1);
    s->cursor = create_sprite(spritesheet, cursor_info, 1);
    return (s);
}

static void draw_all_sprites(sfRenderWindow *window, sprite_list_t *sprite_list)
{
    sfRenderWindow_drawSprite(window, sprite_list->bg->sprite, NULL);
    sfRenderWindow_drawSprite(window, sprite_list->duck->sprite, NULL);
    sfRenderWindow_drawSprite(window, sprite_list->cursor->sprite, NULL);
    sfRenderWindow_display(window);
}

static void destroy_all_sprites(sprite_list_t *sprite_list)
{
    destroy_sprite(sprite_list->duck);
    destroy_sprite(sprite_list->bg);
    destroy_sprite(sprite_list->cursor);
    free(sprite_list);
}

static void move_cursor(sfRenderWindow *window, sprite_t *cursor)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(window);
    sfVector2f cursor_pos = {pos.x - (cursor_info.size.x / 2),
        pos.y - (cursor_info.size.y / 2)};
    
    sfSprite_setPosition(cursor->sprite, cursor_pos);
}

void my_hunter(sfRenderWindow *window)
{
    sprite_list_t *sprite_list = init_all_sprites("img/spritesheet.png");
    sfClock *clock = sfClock_create();

    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    while (sfRenderWindow_isOpen(window)) {
        analyse_events(window);
        draw_all_sprites(window, sprite_list);
        move_sprite(sprite_list->duck, 2, 0);
        move_cursor(window, sprite_list->cursor);
        if (elapsed_time(150, clock))
            animate_sprite(sprite_list->duck);
    }
    destroy_all_sprites(sprite_list);
}
