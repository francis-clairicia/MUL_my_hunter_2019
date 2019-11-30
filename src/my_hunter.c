/*
** EPITECH PROJECT, 2019
** Main window
** File description:
** Main for window
*/

#include "my_hunter.h"
#include <stdio.h>

static pointers_t *init_all_pointers(game_t game)
{
    pointers_t *ptrs = malloc(sizeof(pointers_t));

    ptrs->bg = init_background();
    ptrs->cursor = init_cursor();
    ptrs->duck_list = my_list(1, (long)init_duck(game.duck_speed, 1));
    ptrs->score = init_score();
    ptrs->life = init_life(game.default_nb_lifes);
    return (ptrs);
}

static void defeated(sfRenderWindow *window)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("font/retro.ttf");
    char msg[] = "LOOOOSE !!!";
    int size_character = 80;
    sfVector2f pos = {300, 100};

    sfText_setFont(text, font);
    sfText_setString(text, msg);
    sfText_setCharacterSize(text, size_character);
    sfText_setPosition(text, pos);
    sfRenderWindow_drawText(window, text, NULL);
    sfText_destroy(text);
    sfFont_destroy(font);
}

static void draw_all_objects(sfRenderWindow *window, pointers_t *ptrs,
    int stop)
{
    sfRenderWindow_clear(window, sfColor_fromRGB(94, 204, 236));
    if (!stop)
        draw_duck_list(window, ptrs->duck_list);
    draw_background(window, ptrs->bg);
    draw_score(window, ptrs->score);
    draw_life(window, ptrs->life);
    if (stop)
        defeated(window);
    draw_cursor(window, ptrs->cursor);
}

static void destroy_all_pointers(pointers_t *ptrs)
{
    destroy_background(ptrs->bg);
    destroy_cursor(ptrs->cursor);
    destroy_duck_list(ptrs->duck_list);
    destroy_score(ptrs->score);
    destroy_life(ptrs->life);
    free(ptrs);
}

void my_hunter(sfRenderWindow *window)
{
    game_t game = {1, 2, 2, 3, 0, 1};
    pointers_t *ptrs = init_all_pointers(game);
    sfClock *clock = sfClock_create();

    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    while (sfRenderWindow_isOpen(window)) {
        draw_all_objects(window, ptrs, game.stop);
        sfRenderWindow_display(window);
        if (elapsed_time(100, clock))
            animate_duck_list(ptrs->duck_list);
        analyse_events(window, ptrs, &game);
        if (!game.stop)
            manage_gameplay(ptrs, &game);
    }
    sfClock_destroy(clock);
    destroy_all_pointers(ptrs);
}
