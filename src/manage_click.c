/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** manage_click.c
*/

#include "../include/my.h"

void manage_click_on_radius(all_t *window, game_object_t \
*object, sfVector2i mouse)
{
    if (mouse.x >= object[RADIUS_BAR].pos.x && mouse.x <= \
    object[RADIUS_BAR].pos.x + 50 && mouse.y >= object[RADIUS_BAR].pos.y && \
    mouse.y <= object[RADIUS_BAR].pos.y + 180)
        window->status = 7;
}