/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** pixels.c
*/

#include "../include/my.h"

void draw_game(all_t *window, game_object_t *object)
{
    update_tab_color(window);
    sfSprite_setPosition(object[BACK].sprite, (sfVector2f){1810, 10});
    for (int index = MENU; index <= STARS; index += 1)
        sfRenderWindow_drawSprite(window->window, \
        object[index].sprite, NULL);
    draw_2d_map(window);
    if (object[UP].cliked || object[DOWN].cliked) {
        sfRenderWindow_drawSprite(window->window, \
        object[RADIUS_SCROLL].sprite, NULL);
        sfRenderWindow_drawSprite(window->window, \
        object[RADIUS_BAR].sprite, NULL);
    }
    sfRenderWindow_drawSprite(window->window, object[BACK].sprite, NULL);
    for (int index = CLICK; index < TOTAL; index += 1)
        sfRenderWindow_drawSprite(window->window, \
        object[index].sprite, NULL);
}

void clear_fade(framebuffer_t *fb, int alpha)
{
    const int position = fb->height * fb->width * 4;

    for (int i = 0; i < position; i += 4) {
        fb->pixels[i] = 0;
        fb->pixels[i + 1] = 0;
        fb->pixels[i + 2] = 0;
        fb->pixels[i + 3] = alpha;
    }
}

void refresh_pixel(framebuffer_t *fb, sfRenderWindow *window)
{
    sfTexture_updateFromPixels(fb->texture, fb->pixels, WIDTH, HEIGHT, 0, 0);
    sfSprite_setTexture(fb->sprite, fb->texture, sfFalse);
    sfRenderWindow_drawSprite(window, fb->sprite, NULL);
}

framebuffer_t *create_buffer(int width, int height)
{
    framebuffer_t *fb = malloc(sizeof(framebuffer_t));

    fb->width = width;
    fb->height = height;
    fb->pixels = malloc((width * height * 32) / 8);
    fb->texture = sfTexture_create(WIDTH, HEIGHT);
    fb->sprite = sfSprite_create();
    return (fb);
}

void put_pixel(framebuffer_t *fb, unsigned int x, \
unsigned int y, sfColor col)
{
    int position = (x * 4) + (y * fb->width * 4);

    if (x >= WIDTH || y >= HEIGHT)
        return;
    fb->pixels[position] = col.r;
    fb->pixels[position + 1] = col.g;
    fb->pixels[position + 2] = col.b;
    fb->pixels[position + 3] = col.a;
}