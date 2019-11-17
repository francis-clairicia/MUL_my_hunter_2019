/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** main.c
*/

#include <my_hunter.h>

static int print_usage(void)
{
    my_putstr("Bienvenue dans My Hunter !!\n\n");
    my_putstr("Êtes vous prêts pour la chasse ? Dans ce cas let's go !\n\n");
    my_putstr("Le but du jeu est toucher le plus de canards possible afin ");
    my_putstr("d'avoir le meilleur score.\n");
    my_putstr("Attention, vous n'avez droit qu'à 3 échecs !\n");
    return (0);
}

int main(int ac, char **av)
{
    sfRenderWindow *window;

    if (ac >= 2) {
        if (my_strcmp(av[1], "-h") == 0)
            return (print_usage());
    }
    window = create_window("My hunter", window_size.x, window_size.y);
    my_hunter(window);
    sfRenderWindow_destroy(window);
    return (0);
}