/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** doing_buttons.c
*/

#include "../include/my.h"

void spe_rect(game_object_t *object, all_t *window)
{
    object[TICK].rect.left += 100;
    window->parallax = 0;
    if (object[TICK].rect.left > 100) {
        object[TICK].rect.left = 0;
        window->parallax = 1;
    }
    sfSprite_setTextureRect(object[TICK].sprite, object[TICK].rect);
}

void manage_click_on_options(all_t *window, sfVector2i \
mouse, game_object_t *object)
{
    if (mouse.x >= 1807 && mouse.x <= 1898 && \
    mouse.y >= 921 && mouse.y <= 1009)
        window->status = 0;
    if (mouse.x >= object[FPS_BAR].pos.x && mouse.x <= \
    object[FPS_BAR].pos.x + 180 && mouse.y >= object[FPS_BAR].pos.y && \
    mouse.y <= object[FPS_BAR].pos.y + 50)
        window->status = 5;
    if (mouse.x >= object[VOLUME_BAR].pos.x && mouse.x <= \
    object[VOLUME_BAR].pos.x + 180 && mouse.y >= object[VOLUME_BAR].pos.y && \
    mouse.y <= object[VOLUME_BAR].pos.y + 50)
        window->status = 6;
    if (mouse.x >= 918 && mouse.x <= 1009 && mouse.y >= 822 && mouse.y <= 908)
        spe_rect(object, window);
}

void update_3d_map(all_t *window, sfVector2i check, int radius, int offset)
{
    for (int index = check.y - radius; index <= check.y + radius; index += 1) {
        if (index < window->map_y && index >= 0) {
            for (int temp = check.x - radius; temp <= \
            check.x + radius; temp += 1)
                window->map[index][temp] += \
                (temp < window->map_x && temp > 0) ? offset : 0;
        window->map[index][check.x] += offset;
        }
    }
}

void terraforming(all_t *window, \
sfVector2i mouse, int offset)
{
    int check_x = -5.0;
    int check_y = -5.0;
    float diff = 0;
    float save = -5.0;

    for (int y = 0; y < window->map_y; y += 1) {
        for (int x = 0; x < window->map_x; x += 1) {
            diff = sqrtf(powf(window->pos[y][x].x - mouse.x, 2) + \
            powf(window->pos[y][x].y - mouse.y, 2));
            if (diff < save || save < 0) {
                save = diff;
                check_x = x;
                check_y = y;
            }
        }
    }
    update_3d_map(window, (sfVector2i){check_x, check_y}, \
    window->radius, offset);
}

void check_but(game_object_t *object, all_t *window, \
sfVector2i mouse, angle_t *deltas)
{
    if (object[CLICK].cliked == 1) {
        window->status = 10;
        window->ref = mouse;
    }
    if (object[LOAD].cliked == 1)
        get_new_map(window);
    if (object[UP].cliked == 1)
        window->status = 11;
    if (object[DOWN].cliked == 1)
        window->status = 12;
    if (object[FILL].cliked == 1) {
        for (int y = 0; y < window->map_y; y += 1) {
            for (int x = 0; x < window->map_x; x += 1)
                window->map[y][x] = 0;
        }

    }
    update_map(window, deltas);
}