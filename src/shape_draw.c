/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** shape_draw.c
*/

#include "../include/my.h"

sfVertexArray *shape_top(int i, int j, all_t *window)
{
    sfVertexArray *quad = sfVertexArray_create();
    sfVertex quad1 = {.position = window->pos[i][j], \
    .color = window->color[i][j]};
    sfVertex quad2 = {.position = window->pos[i][j + 1], \
    .color = window->color[i][j + 1]};
    sfVertex quad3 = {.position = window->pos[i + 1][j + 1], \
    .color = window->color[i + 1][j + 1]};
    sfVertex quad4 = {.position = window->pos[i + 1][j], \
    .color = window->color[i + 1][j]};

    sfVertexArray_append(quad, quad1);
    sfVertexArray_append(quad, quad2);
    sfVertexArray_append(quad, quad3);
    sfVertexArray_append(quad, quad4);
    sfVertexArray_setPrimitiveType(quad, sfQuads);
    return (quad);
}

sfVertexArray *shape_right(int i, int j, all_t *window)
{
    sfVertexArray *quad = sfVertexArray_create();
    sfVertex quad1 = {.position = window->pos[i][j], \
    .color = window->color[i][j]};
    sfVertex quad2 = {.position = window->pos[i][j - 1], \
    .color = window->color[i][j - 1]};
    sfVertex quad3 = {.position = window->pos[i + 1][j - 1], \
    .color = window->color[i + 1][j - 1]};
    sfVertex quad4 = {.position = window->pos[i + 1][j], \
    .color = window->color[i + 1][j]};

    sfVertexArray_append(quad, quad1);
    sfVertexArray_append(quad, quad2);
    sfVertexArray_append(quad, quad3);
    sfVertexArray_append(quad, quad4);
    sfVertexArray_setPrimitiveType(quad, sfQuads);
    return (quad);
}

sfVertexArray *shape_bottom(int i, int j, all_t *window)
{
    sfVertexArray *quad = sfVertexArray_create();
    sfVertex quad1 = {.position = window->pos[i][j], \
    .color = window->color[i][j]};
    sfVertex quad2 = {.position = window->pos[i][j - 1], \
    .color = window->color[i][j - 1]};
    sfVertex quad3 = {.position = window->pos[i - 1][j - 1], \
    .color = window->color[i - 1][j - 1]};
    sfVertex quad4 = {.position = window->pos[i - 1][j], \
    .color = window->color[i - 1][j]};

    sfVertexArray_append(quad, quad1);
    sfVertexArray_append(quad, quad2);
    sfVertexArray_append(quad, quad3);
    sfVertexArray_append(quad, quad4);
    sfVertexArray_setPrimitiveType(quad, sfQuads);
    return (quad);
}

sfVertexArray *shape_left(int i, int j, all_t *window)
{
    sfVertexArray *quad = sfVertexArray_create();
    sfVertex quad1 = {.position = window->pos[i][j], \
    .color = window->color[i][j]};
    sfVertex quad2 = {.position = window->pos[i][j + 1], \
    .color = window->color[i][j + 1]};
    sfVertex quad3 = {.position = window->pos[i - 1][j + 1], \
    .color = window->color[i - 1][j + 1]};
    sfVertex quad4 = {.position = window->pos[i - 1][j], \
    .color = window->color[i - 1][j]};

    sfVertexArray_append(quad, quad1);
    sfVertexArray_append(quad, quad2);
    sfVertexArray_append(quad, quad3);
    sfVertexArray_append(quad, quad4);
    sfVertexArray_setPrimitiveType(quad, sfQuads);
    return (quad);
}