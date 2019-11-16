/*
** EPITECH PROJECT, 2019
** CSFML project
** File description:
** Generate a framebuffer
*/

#include <csfml.h>

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
    framebuffer_t *f = malloc(sizeof(framebuffer_t));
    f->width = width;
    f->height = height;
    f->pixels = malloc(width * height * 4);
    f->texture = sfTexture_create(width, height);
    f->sprite = sfSprite_create();
    return (f);
}

void framebuffer_destroy(framebuffer_t *fb)
{
    free(fb->pixels);
    sfTexture_destroy(fb->texture);
    sfSprite_destroy(fb->sprite);
    free(fb);
}