/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** analyse_events.c
*/

#include "../include/my.h"

void check_button(game_object_t *object, sfVector2i mouse)
{
    int index = 0;

    for (index = CLICK; index < MOUSE; index += 1) {
        if (mouse.x >= object[index].pos.x - 50 && \
        mouse.x <= object[index].pos.x + 50 && \
        mouse.y >= object[index].pos.y - 50 && \
        mouse.y <= object[index].pos.y + 50 && object[index].cliked == 0) {
            object[index].cliked = 1;
            object[index].rect.left = 200;
            sfSprite_setTextureRect(object[index].sprite, object[index].rect);
            break;
        }
    }
    for (int temp = CLICK; temp < MOUSE; temp += 1) {
        if (object[temp].cliked == 1 && temp != index) {
            object[temp].cliked = 0;
            object[temp].rect.left = 0;
            sfSprite_setTextureRect(object[temp].sprite, object[temp].rect);
        }
    }
}

void manage_click_on_game(all_t *window, angle_t *deltas, \
sfVector2i mouse, game_object_t *object)
{
    if (mouse.x >= 1805 && mouse.x <= 1909 && \
    mouse.y >= 32 && mouse.y <= 117) {
        get_this_save(window, deltas);
        window->status = 1;
        return;
    }
    check_but(object, window, mouse, deltas);
    if (mouse.x >= object[CLICK].pos.x - 50 && \
    mouse.x <= object[MOUSE - 1].pos.x + 50 && \
    mouse.y >= object[CLICK].pos.y - 50 && \
    mouse.y <= object[DOWN].pos.y + 50)
        check_button(object, mouse);
}

void manage_click_on_save(all_t *window, sfVector2i mouse, angle_t *deltas)
{
    if (mouse.x >= 53 && mouse.x <= 947 && \
    mouse.y >= 347 && mouse.y <= 534) {
        window->status = 2;
        window->filepath = "saves/save_1";
        window->pos = read_save(window, deltas);
    }
    if (mouse.x >= 55 && mouse.x <= 956 && \
    mouse.y >= 582 && mouse.y <= 774) {
        window->status = 2;
        window->filepath = "saves/save_2";
        window->pos = read_save(window, deltas);
    }
    if (mouse.x >= 54 && mouse.x <= 949 && \
    mouse.y >= 815 && mouse.y <= 1014) {
        window->status = 2;
        window->filepath = "saves/save_3";
        window->pos = read_save(window, deltas);
    }
    if (mouse.x >= 1807 && mouse.x <= 1898 && \
    mouse.y >= 921 && mouse.y <= 1009)
        window->status = 0;
}

void object_on_save_screen(game_object_t \
*object, sfVector2i mouse)
{
    if (mouse.x >= 53 && mouse.x <= 947 && \
    mouse.y >= 347 && mouse.y <= 534) {
        sfSprite_setTextureRect(object[SAVES].sprite, \
        (sfIntRect){1920, 0, 1920, 1080});
        return;
    }
    if (mouse.x >= 55 && mouse.x <= 956 && \
    mouse.y >= 582 && mouse.y <= 774) {
        sfSprite_setTextureRect(object[SAVES].sprite, \
        (sfIntRect){3840, 0, 1920, 1080});
        return;
    }
    if (mouse.x >= 54 && mouse.x <= 949 && \
    mouse.y >= 815 && mouse.y <= 1014) {
        sfSprite_setTextureRect(object[SAVES].sprite, \
        (sfIntRect){5760, 0, 1920, 1080});
        return;
    }
    sfSprite_setTextureRect(object[SAVES].sprite, \
    (sfIntRect){0, 0, 1920, 1080});
}

void analyse_events(all_t *window, angle_t *deltas, \
game_object_t *object)
{
    if (window->event.type == sfEvtClosed || \
    sfKeyboard_isKeyPressed(sfKeyEscape))
        sfRenderWindow_close(window->window);
    if (window->event.type == sfEvtMouseWheelScrolled && window->status == 2)
        manage_zoom(window, window->event.mouseWheel.x, deltas);
    if (window->event.type == sfEvtMouseButtonPressed)
        manage_mouse_click(window, deltas, object);
    if (window->event.type == sfEvtMouseButtonReleased && window->status == 10)
        window->status = 2;
    if (window->event.type == sfEvtMouseMoved)
        manage_mouse_moved(window, deltas, object);
    if (window->event.type == sfEvtKeyPressed)
        manage_key_pressed(window, &window->event, deltas, object);
    if (window->event.type == sfEvtMouseButtonReleased && \
    (window->status == 11 || window->status == 12))
        window->status = 2;
    if ((window->status >= 5 && window->status <= 6) && \
    window->event.type == sfEvtMouseButtonReleased)
        window->status = 4;
    if (window->status == 7 && window->event.type == sfEvtMouseButtonReleased)
        window->status = 2;
}