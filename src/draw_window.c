/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** draw_window.c
*/

#include "../include/my.h"

int usage_print(void)
{
    my_printf("Welcome to our world !\n\
USAGE\n\
    ./my_world -h (print this usage)\n\
    ./my_world (start the game)\n\
\n\
USER INTERACTIONS\n\
    KEY_UP rotate the map up, \n\
    KEY_DOWN rotate the map down, \n\
    KEY_RIGHT rotate the map to the right, \n\
    KEY_LEFT rotate the map to the left.\n\
Your modifcations are saved automatically\n");
    return (0);
}

void object_on_game(game_object_t *object, sfVector2i mouse)
{
    int index = 0;

    for (index = CLICK; index < MOUSE; index += 1) {
        if (mouse.x >= object[index].pos.x - 50 && \
        mouse.x <= object[index].pos.x + 50 && \
        mouse.y >= object[index].pos.y - 50 && \
        mouse.y <= object[index].pos.y + 50 && object[index].cliked == 0) {
            object[index].rect.left = 100;
            sfSprite_setTextureRect(object[index].sprite, object[index].rect);
            return;
        }
    }
    for (index = CLICK; index < MOUSE; index += 1) {
        if (object[index].cliked == 0) {
            object[index].rect.left = 0;
            sfSprite_setTextureRect(object[index].sprite, object[index].rect);
        }
    }
}

void draw_menu(all_t *window, game_object_t *object)
{
    if (window->status == 0) {
        for (int index = 0; index <= QUIT; index += 1)
            sfRenderWindow_drawSprite(window->window, \
            object[index].sprite, NULL);
        sfRenderWindow_drawSprite(window->window, object[MOUSE].sprite, NULL);
    } else {
        for (int index = 0; index < STARS; index += 1)
            sfRenderWindow_drawSprite(window->window, \
            object[index].sprite, NULL);
        for (int index = FPS_BAR; index <= PARAMS; index += 1)
            sfRenderWindow_drawSprite(window->window, \
            object[index].sprite, NULL);
        sfRenderWindow_drawSprite(window->window, object[BACK].sprite, NULL);
        sfRenderWindow_drawSprite(window->window, object[MOUSE].sprite, NULL);
    }
}

void draw_saves(all_t *window, game_object_t *object)
{
    sfSprite_setPosition(object[BACK].sprite, object[BACK].pos);
    for (int index = 0; index <= STARS; index += 1)
        sfRenderWindow_drawSprite(window->window, object[index].sprite, NULL);
    sfRenderWindow_drawSprite(window->window, object[SAVES].sprite, NULL);
    sfRenderWindow_drawSprite(window->window, object[BACK].sprite, NULL);
    sfRenderWindow_drawSprite(window->window, object[MOUSE].sprite, NULL);
}

void draw_window(all_t *window, angle_t *deltas, \
framebuffer_t *fb, game_object_t *object)
{
    if (window->status == 10)
        manage_drag(window, deltas, object);
    if (window->status == 0 || (window->status >= 4 && window->status <= 6))
        draw_menu(window, object);
    if (window->status == 1)
        draw_saves(window, object);
    if (window->status == 2 || window->status >= 10 || window->status == 7)
        draw_game(window, object);
    refresh_pixel(fb, window->window);
    clear_fade(fb, 30);
}