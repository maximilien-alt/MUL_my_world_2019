/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** different_draw_axes.c
*/

#include "../include/my.h"

void    axe_top(all_t *window, int select_col)
{
    sfVertexArray *quad;

    (void)select_col;
    for (int i = 0; i + 1 < window->map_y; i++) {
        for (int j = 0; j + 1 < window->map_x; j++) {
            quad = shape_top(i, j, window);
            sfRenderWindow_drawVertexArray(window->window, quad, NULL);
            sfVertexArray_destroy(quad);
        }
    }
}

void    axe_right(all_t *window, int select_col)
{
    sfVertexArray *quad;

    (void)select_col;
    for (int i = 0; i + 1 < window->map_y; i++) {
        for (int j = window->map_x - 2; j - 1 > -1; j--) {
            quad = shape_right(i, j, window);
            sfRenderWindow_drawVertexArray(window->window, quad, NULL);
            sfVertexArray_destroy(quad);
        }
    }
}

void    axe_bottom(all_t *window, int select_col)
{
    sfVertexArray *quad;

    (void)select_col;
    for (int i = window->map_y - 2; i - 1 > -1; i--) {
        for (int j = window->map_x - 2; j - 1 > -1; j--) {
            quad = shape_bottom(i, j, window);
            sfRenderWindow_drawVertexArray(window->window, quad, NULL);
            sfVertexArray_destroy(quad);
        }
    }
}

void    axe_left(all_t *window, int select_col)
{
    sfVertexArray *quad;

    (void)select_col;
    for (int i = window->map_y - 2; i - 1 > -1; i--) {
        for (int j = 0; j + 1 < window->map_x; j++) {
            quad = shape_left(i, j, window);
            sfRenderWindow_drawVertexArray(window->window, quad, NULL);
            sfVertexArray_destroy(quad);
        }
    }
}