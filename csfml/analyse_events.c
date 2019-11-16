/*
** EPITECH PROJECT, 2019
** CSFML project
** File description:
** Event handler
*/

#include <csfml.h>

void analyse_events(sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtMouseButtonReleased)
            manage_mouse_click(event.mouseButton);
    }
}
