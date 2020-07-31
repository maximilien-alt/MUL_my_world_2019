/*
** EPITECH PROJECT, 2019
** hope
** File description:
** manage_rotate.c
*/

#include "../include/my.h"

void update_map(all_t *window, angle_t *deltas)
{
    float temp_x = 0;
    float save_x = 0;
    float temp_y = 0;

    for (int x = 0; x < window->map_y; x += 1) {
        for (int y = 0; y < window->map_x; y += 1) {
            temp_x = x * deltas->zoom;
            save_x = temp_x;
            temp_y = y * deltas->zoom;
            temp_x = (save_x - ((window->map_x / 2) * deltas->zoom)) * \
            cosf(deltas->delta_z) + (temp_y - ((window->map_y / 2) * \
            deltas->zoom)) * sinf(deltas->delta_z);
            temp_y = (temp_y - ((window->map_y / 2) * deltas->zoom)) * \
            cosf(deltas->delta_z) - (save_x - ((window->map_x / 2) * \
            deltas->zoom)) * sinf(deltas->delta_z);
            window->pos[x][y] = project_iso_point(temp_x, temp_y, \
            window->map[x][y] * deltas->zoom * 0.02, deltas);
        }
    }
}