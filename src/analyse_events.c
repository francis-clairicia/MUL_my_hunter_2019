/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** Event handler
*/

#include "my_hunter.h"

void analyse_events(sfRenderWindow *window, pointers_t *ptrs)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtMouseButtonPressed)
            manage_mouse_click(event.mouseButton, ptrs);
    }
    move_duck_list(ptrs->duck_list, sfRenderWindow_getSize(window));
    move_cursor(ptrs->cursor, sfMouse_getPositionRenderWindow(window));
}
