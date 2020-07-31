/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** loop_game.c
*/

#include "../include/my.h"

int get_speed(int type)
{
    if (type == PLANET_1)
        return (1);
    if (type == PLANET_2)
        return (3);
    if (type == PLANET_3)
        return (5);
    if (type == STARS)
        return (7);
    return (0);
}

void manage_clock(all_t *window, game_object_t *object)
{
    (void)window;
    object[MENU].time = sfClock_getElapsedTime(object[MENU].clock);
    object[MENU].seconds = object[MENU].time.microseconds / 1000000.0;
    if (object[MENU].seconds > 0.02 && window->parallax == 1) {
        for (int index = 1; index <= STARS; index += 1)
            move_rect(object, object[index].speed, object[index].max, index);
        sfClock_restart(object[MENU].clock);
    }
}

void loop_game(all_t *window, framebuffer_t *fb, \
angle_t *deltas, game_object_t *object)
{
    while (sfRenderWindow_isOpen(window->window)) {
        while (sfRenderWindow_pollEvent(window->window, &window->event))
            analyse_events(window, deltas, object);
        sfRenderWindow_clear(window->window, sfBlack);
        manage_clock(window, object);
        draw_window(window, deltas, fb, object);
        sfRenderWindow_display(window->window);
    }
    if (window->status == 2)
        get_this_save(window, deltas);
    destroy_objects(window);
}