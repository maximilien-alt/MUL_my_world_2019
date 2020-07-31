/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** draw_maps.c
*/

#include "../include/my.h"

game_object_t setup_object(char *filepath, sfVector2f pos, \
sfIntRect rect, SPRITES type)
{
    game_object_t object;

    object.type = type;
    object.pos = pos;
    object.rect = rect;
    object.sprite = sfSprite_create();
    object.texture = sfTexture_createFromFile(filepath, NULL);
    object.clock = sfClock_create();
    object.seconds = 0.0;
    object.max = 3840;
    object.speed = get_speed(type);
    sfSprite_setTexture(object.sprite, object.texture, sfTrue);
    sfSprite_setTextureRect(object.sprite, object.rect);
    sfSprite_setPosition(object.sprite, object.pos);
    object.cliked = (type == CLICK) ? 1 : 0;
    return (object);
}

sfVertexArray *create_lines(sfVector2f *point_1, sfVector2f *point_2)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex vertex1 = {.position = *point_1, .color = sfCyan};
    sfVertex vertex2 = {.position = *point_2, .color = sfCyan};

    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_setPrimitiveType(vertex_array, sfLinesStrip);
    return (vertex_array);
}

float check_start(all_t *window)
{
    float check = 10000;

    for (int temp = 0; temp + 1 < window->map_y; temp += 1) {
        for (int new = 0; new < window->map_x; new += 1) {
            if (check > window->pos[0][0].y)
                check = window->pos[0][0].y;
            if (check > window->pos[0][window->map_x - 1].y)
                check = window->pos[0][window->map_x - 1].y;
            if (check > window->pos[window->map_y - 2][0].y)
                check = window->pos[window->map_y - 2][0].y;
            if (check > window->pos[window->map_y - 2][window->map_x - 1].y)
                check = window->pos[window->map_y - 2][window->map_x - 1].y;
        }
    }
    return (check);
}

void draw_2d_map(all_t *window)
{
    float check = check_start(window);

    if (check == window->pos[0][0].y)
        axe_top(window, 1);
    if (check == window->pos[0][window->map_x - 1].y)
        axe_right(window, 2);
    if (check == window->pos[window->map_y - 2][window->map_x - 1].y)
        axe_bottom(window, 3);
    if (check == window->pos[window->map_y - 2][0].y)
        axe_left(window, 4);
}