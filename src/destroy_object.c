/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** destroy_object.c
*/

#include "../include/my.h"

void destroy_objects(all_t *window)
{
    sfRenderWindow_destroy(window->window);
}