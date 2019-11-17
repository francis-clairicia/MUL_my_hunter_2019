/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** Event handler
*/

#include <my_hunter.h>

void analyse_events(sfRenderWindow *window, duck_t *duck)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtMouseButtonPressed
        || event.type == sfEvtMouseButtonReleased)
            manage_mouse_click(event.mouseButton, duck);
    }
}
