/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** move_rect.c
*/

#include "../include/my.h"

void update_radius(game_object_t *object, sfVector2i mouse, all_t *window)
{
    if (mouse.y - 90 >= 375 && mouse.y + 90 <= 725) {
        object[RADIUS_BAR].pos.y = mouse.y - 90;
        window->radius = (int)(object[RADIUS_BAR].pos.y - 380) / 5;
    }
    sfSprite_setPosition(object[RADIUS_BAR].sprite, object[RADIUS_BAR].pos);
}

void update_volume_bar(game_object_t *object, sfVector2i mouse, all_t *window)
{
    if (window->status == 7)
        return (update_radius(object, mouse, window));
    if (mouse.x - 90 > 777 && mouse.x + 90 < 1140) {
        object[VOLUME_BAR].pos.x = mouse.x - 90;
        window->volume = (object[VOLUME_BAR].pos.x - (WIDTH / 2 - 90)) + 90;
        if (window->volume > 0 && window->volume < 100)
            sfMusic_setVolume(window->music, window->volume);
    }
    sfSprite_setPosition(object[VOLUME_BAR].sprite, object[VOLUME_BAR].pos);
}

void update_fps_bar(game_object_t *object, sfVector2i mouse, all_t *window)
{
    if (mouse.x - 90 > 777 && mouse.x + 90 < 1140) {
        object[FPS_BAR].pos.x = mouse.x - 90;
        window->fps = (object[VOLUME_BAR].pos.x - (WIDTH / 2 - 90)) + 90;
        sfRenderWindow_setFramerateLimit(window->window, window->fps);
    }
    sfSprite_setPosition(object[FPS_BAR].sprite, object[FPS_BAR].pos);
}

void move_rect(game_object_t *game_object, int offset, \
int max_size, SPRITES type)
{
    game_object[type].rect.left += offset;
    if (game_object[type].rect.left > max_size)
        game_object[type].rect.left = 0;
    sfSprite_setTextureRect(game_object[type].sprite, \
    game_object[type].rect);
}