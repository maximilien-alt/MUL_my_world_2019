/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** main.c
*/

#include "../include/my.h"

int int_to_ascii(int number, char *buffer, int afterpoint)
{
    int index = 0;

    for (; number > 0; number /= 10) {
        buffer[index] = (number % 10) + '0';
        index += 1;
    }
    while (index < afterpoint) {
        buffer[index] = 0;
        index += 1;
    }
    buffer[index] = 0;
    my_revstr(buffer);
    return (index);
}

char *get_neg(char *buffer)
{
    int index = 0;

    my_revstr(buffer);
    for (; buffer[index]; index += 1);
    buffer[index] = '-';
    return (my_revstr(buffer));
}

char *my_ftoa(float number, char *buffer, int afterpoint)
{
    int i_part = 0;
    float f_part = 0.0;
    int index = 0;
    int check = 0;

    (number < 0) ? check = 1 : 0;
    (check == 1) ? number *= -1 : 0;
    i_part = (int)number;
    f_part = number - (float)i_part;
    index = int_to_ascii(i_part, buffer, 0);
    if (afterpoint != 0) {
        buffer[index] = '.';
        f_part = f_part * pow(10, afterpoint);
        int_to_ascii((int)f_part, buffer + index + 1, afterpoint);
    }
    if (check == 1)
        buffer = get_neg(buffer);
    return (buffer);
}

void free_structures(all_t *window, game_object_t *object)
{
    if (window->status == 2) {
        for (int x = 0; x < window->map_y; x += 1)
            free (window->pos[x]);
        free (window->pos);
    }
    for (int index = 0; index < TOTAL; index += 1) {
        sfSprite_destroy(object[index].sprite);
        sfTexture_destroy(object[index].texture);
    }
    sfMusic_destroy(window->music);
}

int main(int ac, char *av[])
{
    all_t window;
    framebuffer_t *fb = create_buffer(WIDTH, HEIGHT);
    angle_t deltas;
    game_object_t object[TOTAL];

    if (ac == 2 && !my_strcmp(av[1], "-h"))
        return (usage_print());
    if (ac != 1)
        return (84);
    srand(time(NULL));
    my_create_game_object(object);
    set_structures(&window, &deltas);
    sfMusic_play(window.music);
    loop_game(&window, fb, &deltas, object);
    free_structures(&window, object);
    return (0);
}