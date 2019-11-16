/*
** EPITECH PROJECT, 2019
** My Hunter
** File description:
** Header for My hunter
*/

#include <my.h>
#include <csfml.h>

#ifndef HEADER_MY_HUNTER
#define HEADER_MY_HUNTER

typedef struct sprite
{
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    unsigned int default_left;
    unsigned int default_top;
    unsigned int index_sprite;
    unsigned int nb_sprites;
} sprite_t;

typedef struct sprite_list
{
    sprite_t *bg;
    sprite_t *cursor;
    sprite_t *duck;
} sprite_list_t;

typedef struct info
{
    sfIntRect rect;
    sfVector2f size;
} info_t;

static const info_t duck_info = {
    {7, 170, 40, 40},
    {90, 90}
};
static const info_t background_info = {
    {383, 5, 256, 240},
    {800, 600}
};
static const info_t cursor_info = {
    {469, 259, 25, 23},
    {70, 70}
};

void my_hunter(sfRenderWindow *window);
sprite_t *create_sprite(char const *filepath, info_t info,
    int nb_sprites);
void destroy_sprite(sprite_t *s);
void animate_sprite(sprite_t *s);
void resize_sprite(sprite_t *s, float width, float height);
void move_sprite(sprite_t *s, float x_move, float y_move);

#endif /* !HEADER_MY_HUNTER */
