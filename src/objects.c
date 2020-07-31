/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** objects.c
*/

#include "../include/my.h"

void object_on_menu(game_object_t *object, sfVector2i mouse)
{
    if (mouse.x >= 200 && mouse.x <= 334 && \
    mouse.y >= 390 && mouse.y <= 448) {
        sfSprite_setTextureRect(object[PLAY].sprite, \
        (sfIntRect){1920, 0, 1920, 1080});
        return;
    }
    if (mouse.x >= 208 && mouse.x <= 437 && \
    mouse.y >= 616 && mouse.y <= 660) {
        sfSprite_setTextureRect(object[OPTIONS].sprite, \
        (sfIntRect){1920, 0, 1920, 1080});
        return;
    }
    if (mouse.x >= 210 && mouse.x <= 337 && \
    mouse.y >= 838 && mouse.y <= 880) {
        sfSprite_setTextureRect(object[QUIT].sprite, \
        (sfIntRect){1920, 0, 1920, 1080});
        return;
    }
    sfSprite_setTextureRect(object[PLAY].sprite, object[PLAY].rect);
    sfSprite_setTextureRect(object[OPTIONS].sprite, object[OPTIONS].rect);
    sfSprite_setTextureRect(object[QUIT].sprite, object[QUIT].rect);
}

game_object_t create_object(char *filepath, sfVector2f pos, \
sfIntRect rect, SPRITES type)
{
    game_object_t object = setup_object(filepath, pos, rect, type);

    if (type == MOUSE)
        sfSprite_setOrigin(object.sprite, (sfVector2f){16, 16});
    if (type >= CLICK && type < MOUSE)
        sfSprite_setOrigin(object.sprite, (sfVector2f){50, 50});
    return (object);
}

void my_create_game_object_three(game_object_t *game_object)
{
    game_object[RADIUS_BAR] = create_object("assets/bar_down.png", \
    (sfVector2f){1920 - 90, HEIGHT / 2}, \
    (sfIntRect){0, 0, 50, 180}, RADIUS_BAR);
    game_object[MOUSE] = create_object("assets/mouse.png", \
    (sfVector2f){WIDTH / 2, HEIGHT / 2}, (sfIntRect){0, 0, 32, 32}, MOUSE);
    game_object[CLICK] = create_object("assets/buttons.png", \
    (sfVector2f){800, 960}, (sfIntRect){200, 0, 100, 100}, CLICK);
    game_object[UP] = create_object("assets/buttons.png", \
    (sfVector2f){900, 960}, (sfIntRect){0, 100, 100, 100}, UP);
    game_object[DOWN] = create_object("assets/buttons.png", \
    (sfVector2f){1000, 960}, (sfIntRect){0, 200, 100, 100}, DOWN);
    game_object[LOAD] = create_object("assets/buttons.png", \
    (sfVector2f){1100, 960}, (sfIntRect){0, 300, 100, 100}, LOAD);
    game_object[FILL] = create_object("assets/buttons.png", \
    (sfVector2f){1200, 960}, (sfIntRect){0, 400, 100, 100}, FILL);
}

void my_create_game_object_next(game_object_t *game_object)
{
    game_object[FPS_BAR] = create_object("assets/bar.png", \
    (sfVector2f){WIDTH / 2 - 90, 232}, (sfIntRect){0, 0, 180, 50}, FPS_BAR);
    game_object[FPS_SCROLL] = create_object("assets/scroll.png", \
    (sfVector2f){WIDTH / 2 - 256, 0}, (sfIntRect){0, 0, 512, 512}, FPS_SCROLL);
    game_object[VOLUME_BAR] = create_object("assets/bar.png", \
    (sfVector2f){WIDTH / 2 - 90, 532}, (sfIntRect){0, 0, 180, 50}, VOLUME_BAR);
    game_object[VOLUME_SCROLL] = create_object("assets/scroll.png", \
    (sfVector2f){WIDTH / 2 - 256, 300}, (sfIntRect){0, 0, 512, 512}, \
    VOLUME_SCROLL);
    game_object[TICK] = create_object("assets/tick.png", \
    (sfVector2f){WIDTH / 2 - 50, 800}, (sfIntRect){0, 0, 100, 100}, TICK);
    game_object[PARAMS] = create_object("assets/params.png", \
    (sfVector2f){0, 0}, (sfIntRect){0, 0, 1920, 1080}, PARAMS);
    game_object[RADIUS_SCROLL] = create_object("assets/scroll_down.png", \
    (sfVector2f){1920 - 320, HEIGHT / 2 - 256}, \
    (sfIntRect){0, 0, 512, 512}, RADIUS_SCROLL);
    my_create_game_object_three(game_object);
}

void my_create_game_object(game_object_t *game_object)
{
    game_object[MENU] = create_object("assets/background.png", \
    (sfVector2f){0, 0}, (sfIntRect){0, 0, 1920, 1080}, MENU);
    game_object[PLANET_1] = create_object("assets/planet_1.png", \
    (sfVector2f){0, 0}, (sfIntRect){1920, 0, 1920, 1080}, PLANET_1);
    game_object[PLANET_2] = create_object("assets/planet_2.png", \
    (sfVector2f){0, 0}, (sfIntRect){1920, 0, 1920, 1080}, PLANET_2);
    game_object[PLANET_3] = create_object("assets/planet_3.png", \
    (sfVector2f){0, 0}, (sfIntRect){1920, 0, 1920, 1080}, PLANET_3);
    game_object[STARS] = create_object("assets/stars.png", \
    (sfVector2f){0, 0}, (sfIntRect){1920, 0, 1920, 1080}, STARS);
    game_object[PLAY] = create_object("assets/play.png", \
    (sfVector2f){0, 0}, (sfIntRect){0, 0, 1920, 1080}, PLAY);
    game_object[OPTIONS] = create_object("assets/options.png", \
    (sfVector2f){0, 0}, (sfIntRect){0, 0, 1920, 1080}, OPTIONS);
    game_object[QUIT] = create_object("assets/quit.png", \
    (sfVector2f){0, 0}, (sfIntRect){0, 0, 1920, 1080}, QUIT);
    game_object[BACK] = create_object("assets/undo.png", \
    (sfVector2f){1800, 900}, (sfIntRect){0, 0, 100, 100}, BACK);
    game_object[SAVES] = create_object("assets/saves.png", \
    (sfVector2f){0, 0}, (sfIntRect){0, 0, 1920, 1080}, SAVES);
    my_create_game_object_next(game_object);
}