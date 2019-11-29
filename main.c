/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** main.c
*/

#include "my_hunter.h"

static int print_usage(void)
{
    my_putstr("Bienvenue dans My Hunter !!\n\n");
    my_putstr("Êtes vous prêts pour la chasse ? Dans ce cas let's go !\n\n");
    my_putstr("Le but du jeu est toucher le plus de canards possible afin ");
    my_putstr("d'avoir le meilleur score.\n");
    my_putstr("Attention, vous n'avez droit qu'à 3 échecs !\n");
    return (0);
}

static int valid_environment(char **envp)
{
    int i = 0;

    if (envp[0] == NULL)
        return (0);
    while (envp[i] != NULL) {
        if (my_strncmp(envp[i], "DISPLAY", my_strlen("DISPLAY")) == 0)
            return (1);
        i += 1;
    }
    return (0);
}

int main(int ac, char **av, char **envp)
{
    sfRenderWindow *window;

    if (!valid_environment(envp))
        return (84);
    if (ac >= 2) {
        if (my_strcmp(av[1], "-h") == 0)
            return (print_usage());
    }
    window = create_window("My hunter", size_window.x, size_window.y);
    my_hunter(window);
    sfRenderWindow_destroy(window);
    return (0);
}