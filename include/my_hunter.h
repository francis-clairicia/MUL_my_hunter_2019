/*
** EPITECH PROJECT, 2019
** My Hunter
** File description:
** Header for My hunter
*/

#ifndef HEADER_MY_HUNTER
#define HEADER_MY_HUNTER

#include "my.h"
#include "mylist.h"
#include "csfml.h"

typedef struct info
{
    sfIntRect rect;
    sfVector2f size;
    sfVector2f position;
} info_t;

typedef struct text_info
{
    char *font_filepath;
    unsigned int size;
    sfVector2f pos;
} text_info_t;

static const sfVector2u size_window = {800, 600};

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

object_t *create_object(info_t info, int nb_sprites);
void destroy_object(object_t *object);
void draw_object(sfRenderWindow *window, object_t *object);
void animate_object(object_t *object);
void refresh_object(object_t *object);
void resize_object(object_t *object, float width, float height);
void move_object(object_t *object, float x_move, float y_move);
void set_pos_object(object_t *object, sfVector2f position);

typedef struct background
{
    object_t *scenery;
    object_t *hit_bar;
} background_t;

background_t *init_background(void);
void destroy_background(background_t *bg);
void draw_background(sfRenderWindow *window, background_t *bg);

typedef struct duck
{
    object_t *object;
    object_t *fly;
    object_t *hit;
    object_t *fall;
    sfVector2f move;
    int status;
    int hit_value;
    int speed;
    int out_of_screen;
} duck_t;

duck_t *init_duck(int speed);
void destroy_duck(duck_t *duck);
void animate_duck(duck_t *duck);
void move_duck(duck_t *duck, sfVector2u window_size);
void draw_duck(sfRenderWindow *window, duck_t *duck);
void set_duck_speed(duck_t *duck, int speed);
void default_duck_pos(duck_t *duck);
void duck_fly(duck_t *duck);
void duck_hit(duck_t *duck);
void duck_fall(duck_t *duck);
void duck_stop(duck_t *duck);

void add_duck_to_list(list_t *duck_list, int duck_speed);
void move_duck_list(list_t *duck_list, sfVector2u window_size);
void animate_duck_list(list_t *duck_list);
void draw_duck_list(sfRenderWindow *window, list_t *duck_list);
void destroy_duck_list(list_t *duck_list);

typedef struct score
{
    object_t *hit_bar;
    int width;
    int duck_size;
    int duck_hit;
} score_t;

score_t *init_score(void);
void destroy_score(score_t *score);
void draw_score(sfRenderWindow *window, score_t *score);
void increase_score(score_t *score, int number);
void set_score(score_t *score, int number);

typedef struct cursor
{
    object_t *object;
} cursor_t;

cursor_t *init_cursor(void);
void destroy_cursor(cursor_t *cursor);
void draw_cursor(sfRenderWindow *window, cursor_t *cursor);
void move_cursor(cursor_t *cursor, sfVector2i pos);

typedef struct shot
{
    object_t *bullets;
    object_t *shot_flag;
    int shot_remaining;
} shot_t;

shot_t *init_shot(void);
void destroy_shot(shot_t *shot);
void draw_shot(sfRenderWindow *window, shot_t *shot);
void decrease_bullets(shot_t *shot);
void set_remaining_shots(shot_t *shot, int nb);

typedef struct life
{
    int nb_lifes;
    sfFont *font;
    sfText *text;
} life_t;

life_t *init_life(int nb_lifes);
void destroy_life(life_t *life);
void draw_life(sfRenderWindow *window, life_t *life);

typedef struct pointers
{
    background_t *bg;
    cursor_t *cursor;
    list_t *duck_list;
    score_t *score;
    shot_t *shot;
    life_t *life;
} pointers_t;

void my_hunter(sfRenderWindow *window);
void analyse_events(sfRenderWindow *window, pointers_t *ptrs);
void manage_mouse_click(sfMouseButtonEvent event, pointers_t *ptrs);
int manage_gameplay(pointers_t *ptrs);

#endif /* !HEADER_MY_HUNTER */
