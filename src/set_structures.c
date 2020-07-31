/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** set_structures.c
*/

#include "../include/my.h"

float **get_random_map(all_t *window)
{
    float **mapp = malloc(sizeof(int *) * window->map_y);
    float x_off = 0;
    float y_off = 0;
    int *perm = get_random_tab();

    for (int index = 0; index < window->map_y; index += 1)
        mapp[index] = malloc(sizeof(int) * window->map_x);
    for (int y = 0; y < window->map_x; y += 1) {
        x_off = 0;
        for (int x = 0; x < window->map_x; x += 1) {
            mapp[y][x] = bruit_perlin(x_off, y_off, perm) * 350;
            x_off += 0.1;
        }
        y_off += 0.1;
    }
    free (perm);
    return (mapp);
}

sfRenderWindow *create_window(int nb)
{
    sfRenderWindow* window;
    sfVideoMode mode = {WIDTH, HEIGHT, 32};

    window = sfRenderWindow_create(mode, "My_world", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, nb);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    return (window);
}

sfVector2f project_iso_point(int x, int y, float z, angle_t *deltas)
{
    float new_pos_x = 0;
    float new_pos_y = 0;

    new_pos_x = cosf(deltas->angle_x) * x - cosf(deltas->angle_x) * y;
    new_pos_y = sinf(deltas->angle_y) * y + sinf(deltas->angle_y) * x - z;
    new_pos_x += (WIDTH / 2) + deltas->delta_x;
    new_pos_y += 150 + deltas->delta_y;
    return ((sfVector2f){new_pos_x, new_pos_y});
}

sfVector2f **create_2d_map(float temp_y, angle_t *deltas, \
float temp_x, all_t *window)
{
    sfVector2f **new_map;
    float save_x = 0;

    new_map = malloc(sizeof(sfVector2f *) * window->map_y);
    for (int temp = 0; temp < window->map_y; temp += 1) {
        new_map[temp] = malloc(sizeof(sfVector2f) * window->map_x);
        for (int y = 0; y < window->map_x; y += 1) {
            temp_x = temp * deltas->zoom;
            save_x = temp_x;
            temp_y = y * deltas->zoom;
            temp_x = (save_x - ((window->map_x / 2) * deltas->zoom)) * \
            cosf(deltas->delta_z) + (temp_y - ((window->map_y / 2) * \
            deltas->zoom)) * sinf(deltas->delta_z);
            temp_y = (temp_y - ((window->map_y / 2) * deltas->zoom)) * \
            cosf(deltas->delta_z) - (save_x - ((window->map_x / 2) * \
            deltas->zoom)) * sinf(deltas->delta_z);
            new_map[temp][y] = project_iso_point(temp_x, temp_y, \
            window->map[temp][y] * deltas->zoom * 0.02, deltas);
        }
    }
    return (new_map);
}

void set_structures(all_t *window, angle_t *deltas)
{
    deltas->angle_x = 45 * M_PI / 180.0;
    deltas->angle_y = 45 * M_PI / 180.0;
    deltas->delta_x = 0;
    deltas->delta_z = 0;
    deltas->delta_y = 0;
    deltas->zoom = 5;
    window->status = 0;
    window->window = create_window(60);
    window->map_y = 100;
    window->map_x = 100;
    window->map = get_random_map(window);
    window->color = setup_tab_color(window);
    window->music = sfMusic_createFromFile("assets/music.ogg");
    sfMusic_setLoop(window->music, sfTrue);
    sfMusic_setVolume(window->music, 50);
    window->parallax = 1;
    window->volume = 50;
    window->fps = 60;
    window->radius = 50;
}