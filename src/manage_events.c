/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** manage_events.c
*/

#include "../include/my.h"

void manage_mouse_moved(all_t *window, angle_t *deltas, \
game_object_t *object)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window->window);

    if (window->status == 0)
        object_on_menu(object, mouse);
    if (window->status == 1)
        object_on_save_screen(object, mouse);
    if (window->status == 2)
        object_on_game(object, mouse);
    if (window->status == 11) {
        terraforming(window, mouse, -10);
        update_map(window, deltas);
    }
    if (window->status == 12) {
        terraforming(window, mouse, 10);
        update_map(window, deltas);
    }
    if (window->status == 5)
        update_fps_bar(object, mouse, window);
    if (window->status == 6 || window->status == 7)
        update_volume_bar(object, mouse, window);
    sfSprite_setPosition(object[MOUSE].sprite, (sfVector2f){mouse.x, mouse.y});
}

void manage_mouse_click(all_t *window, angle_t *deltas, game_object_t *object)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window->window);

    if (window->status == 2)
        manage_click_on_game(window, deltas, mouse, object);
    if (window->status == 1)
        manage_click_on_save(window, mouse, deltas);
    if (window->status == 0) {
        if (mouse.x >= 200 && mouse.x <= 334 && \
        mouse.y >= 390 && mouse.y <= 448)
            window->status = 1;
        if (mouse.x >= 208 && mouse.x <= 437 && \
        mouse.y >= 616 && mouse.y <= 660)
            window->status = 4;
        if (mouse.x >= 210 && mouse.x <= 337 && \
        mouse.y >= 838 && mouse.y <= 880)
            sfRenderWindow_close(window->window);
    }
    if (window->status == 4)
        manage_click_on_options(window, mouse, object);
    if (object[UP].cliked || object[DOWN].cliked)
        manage_click_on_radius(window, object, mouse);
}

void manage_key_pressed(all_t *window, sfEvent *event, \
angle_t *deltas, game_object_t *object)
{
    (void)object;
    if (window->status == 2) {
        if (event->key.code == sfKeyUp) {
            if (deltas->angle_y < 0.05)
                deltas->angle_y -= 0;
            else
                deltas->angle_y -= 0.07;
        }
        if (event->key.code == sfKeyDown) {
            if (deltas->angle_y > 1.5)
                deltas->angle_y += 0;
            else
                deltas->angle_y += 0.07;
        }
        if (event->key.code == sfKeyLeft)
            deltas->delta_z -= 0.01;
        if (event->key.code == sfKeyRight)
            deltas->delta_z += 0.01;
        update_map(window, deltas);
    }
}

void manage_drag(all_t *window, angle_t *deltas, game_object_t *object)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window->window);
    int dif_x = mouse.x - window->ref.x;
    int dif_y = mouse.y - window->ref.y;

    deltas->delta_y += dif_y;
    deltas->delta_x += dif_x;
    for (int index = 1; index <= STARS; index += 1) {
        object[index].pos.y += dif_y / 5;
        move_rect(object, dif_x / 5, object[index].max, index);
        sfSprite_setPosition( object[index].sprite,  object[index].pos);
    }
    update_map(window, deltas);
    window->ref = sfMouse_getPositionRenderWindow(window->window);
}

void manage_zoom(all_t *window, int delta, angle_t *deltas)
{
    if (delta < 0)
        deltas->zoom += 3;
    else {
        if (deltas->zoom > 3)
            deltas->zoom -= 3;
    }
    update_map(window, deltas);
}