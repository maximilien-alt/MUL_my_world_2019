/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** setup_color_z_axe.c
*/

#include "../include/my.h"

void update_tab_color(all_t *window)
{
    for (int y = 0; y < window->map_y; y += 1) {
        for (int x = 0; x < window->map_x; x += 1) {
            if (window->map[y][x] <= -50 && window->map[y][x] > -100)
                window->color[y][x] = sfColor_fromRGBA(0, 169, 204, 255);
            if (window->map[y][x] <= -100 && window->map[y][x] > -200)
                window->color[y][x] = sfColor_fromRGBA(6, 119, 144, 255);
            if (window->map[y][x] <= -200)
                window->color[y][x] = sfColor_fromRGBA(3, 34, 74, 255);
            if (window->map[y][x] > 200)
                window->color[y][x] = sfWhite;
            update_tab_color_2(window, x, y);
        }
    }
}

void update_tab_color_2(all_t *window, int x, int y)
{
    if (window->map[y][x] > -50 && window->map[y][x] <= 0)
        window->color[y][x] = sfColor_fromRGBA(52, 201, 36, 255);
    if (window->map[y][x] > 0 && window->map[y][x] <= 50)
        window->color[y][x] = sfColor_fromRGBA(34, 120, 15, 255);
    if (window->map[y][x] > 50 && window->map[y][x] <= 100)
        window->color[y][x] = sfColor_fromRGBA(9, 82, 40, 255);
    if (window->map[y][x] > 100 && window->map[y][x] <= 150)
        window->color[y][x] = sfColor_fromRGBA(85, 91, 97, 255);
    if (window->map[y][x] > 150 && window->map[y][x] <= 200)
        window->color[y][x] = sfColor_fromRGBA(195, 195, 195, 255);
}

sfColor **setup_tab_color(all_t *window)
{
    sfColor **color = malloc(sizeof(sfColor *) * window->map_y);

    for (int y = 0; y < window->map_y; y++) {
        color[y] = malloc(sizeof(sfColor) * window->map_x);
        for (int x = 0; x < window->map_x; x += 1) {
            if (x <= 0)
                color[y][x] = sfBlue;
            if (x > 200)
                color[y][x] = sfWhite;
            if (x > 0 && x <= 200)
                color[y][x] = sfGreen;
        }
    }
    return (color);
}