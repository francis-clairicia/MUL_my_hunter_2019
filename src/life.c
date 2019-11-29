/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** life.c
*/

#include "my_hunter.h"

static const text_info_t life_text_info = {
    "font/retro.ttf", 40, {630, 510}
};

life_t *init_life(int nb_lifes)
{
    life_t *life = malloc(sizeof(life_t));

    life->nb_lifes = nb_lifes;
    life->font = sfFont_createFromFile(life_text_info.font_filepath);
    life->text = sfText_create();
    sfText_setFont(life->text, life->font);
    sfText_setColor(life->text, sfWhite);
    sfText_setCharacterSize(life->text, life_text_info.size);
    sfText_setPosition(life->text, life_text_info.pos);
    return (life);
}

void destroy_life(life_t *life)
{
    sfText_destroy(life->text);
    sfFont_destroy(life->font);
    free(life);
}

void draw_life(sfRenderWindow *window, life_t *life)
{
    char *nb_lifes = my_nbr_to_str(life->nb_lifes);
    char end_of_txt[] = " lifes";
    int text_size = my_strlen(nb_lifes) + my_strlen(end_of_txt);
    char *life_remaining = malloc(sizeof(char) * (text_size + 1));
    int i = 0;

    while (i < text_size) {
        if (i < my_strlen(nb_lifes))
            life_remaining[i] = nb_lifes[i];
        else
            life_remaining[i] = end_of_txt[i - my_strlen(nb_lifes)];
        i += 1;
    }
    if (life->nb_lifes < 2)
        life_remaining[text_size - 1] = ' ';
    life_remaining[text_size] = '\0';
    sfText_setString(life->text, life_remaining);
    sfRenderWindow_drawText(window, life->text, NULL);
    free(nb_lifes);
    free(life_remaining);
}