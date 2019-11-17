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

// Structures
typedef struct object
{
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    sfIntRect default_rect;
    sfVector2f pos;
    sfVector2f size;
    unsigned int index_sprite;
    unsigned int nb_sprites;
} object_t;

typedef struct object_list
{
    object_t *bg;
    object_t *cursor;
    object_t *duck;
    object_t *hit[2];
} object_list_t;

typedef struct duck
{
    object_t *object;
    sfVector2f move;
    sfVector2f default_pos;
    int status;
    int hit;
    sfIntRect rect_fly;
    sfIntRect rect_hit;
    sfIntRect rect_fall;
} duck_t;

typedef struct info
{
    sfIntRect rect;
    sfVector2f size;
    sfVector2f position;
} info_t;

// Constantes
static const sfVector2u window_size = {
    800, 600
};
static const info_t duck_info = {
    {5, 170, 40, 37},
    {90, 90},
    {0, 0}
};
static const info_t background_info = {
    {383, 5, 256, 240},
    {window_size.x, window_size.y},
    {0, 0}
};
static const info_t cursor_info = {
    {469, 259, 25, 23},
    {70, 70},
    {0, 0}
};

static const info_t hit_info[2] = {
    {
        {526, 250, 113, 18},
        {353, 45},
        {196, 516}
    },
    {
        {526, 270, 33, 18},
        {103, 45},
        {196, 516}
    }
};

// Prototypes
void my_hunter(sfRenderWindow *window);
void analyse_events(sfRenderWindow *window, duck_t *duck);
void manage_mouse_click(sfMouseButtonEvent event, duck_t *duck);
object_t *create_object(char const *filepath, info_t info,
    int nb_sprites);
void destroy_object(object_t *object);
void animate_object(object_t *object);
void resize_object(object_t *object, float width, float height);
void move_object(object_t *object, float x_move, float y_move);
void set_pos_object(object_t *object, float x, float y);
void init_duck(duck_t *duck, object_t *object);
void animate_duck(duck_t *duck);

#endif /* !HEADER_MY_HUNTER */
