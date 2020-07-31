/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** read_and_write.c
*/

#include "../include/my.h"

void get_angles(angle_t *deltas, int index, char **array)
{
    deltas->angle_x = my_getfloat(array[index]);
    deltas->angle_y = my_getfloat(array[index + 1]);
    deltas->delta_x = my_getfloat(array[index + 2]);
    deltas->delta_y = my_getfloat(array[index + 3]);
    deltas->delta_z = my_getfloat(array[index + 4]);
    deltas->zoom = my_getfloat(array[index + 5]);
}

sfVector2f **modif_with_array(sfVector2f **tab, char **array, \
angle_t *deltas, all_t *window)
{
    int index = 0;

    for (int x = 0; x < window->map_y; x += 1) {
        for (int y = 0; y < window->map_x; y += 1) {
            tab[x][y].x = my_getfloat(array[index]);
            tab[x][y].y = my_getfloat(array[index + 1]);
            index += 2;
        }
    }
    get_angles(deltas, index, array);
    return (tab);
}

void save_angles(angle_t *deltas, int fd, char *buffer)
{
    buffer = my_ftoa(deltas->angle_x, buffer, 6);
    write(fd, buffer, my_strlen(buffer));
    write(fd, "\n", 1);
    buffer = my_ftoa(deltas->angle_y, buffer, 6);
    write(fd, buffer, my_strlen(buffer));
    write(fd, "\n", 1);
    buffer = my_ftoa(deltas->delta_x, buffer, 6);
    write(fd, buffer, my_strlen(buffer));
    write(fd, "\n", 1);
    buffer = my_ftoa(deltas->delta_y, buffer, 6);
    write(fd, buffer, my_strlen(buffer));
    write(fd, "\n", 1);
    buffer = my_ftoa(deltas->delta_z, buffer, 6);
    write(fd, buffer, my_strlen(buffer));
    write(fd, "\n", 1);
    buffer = my_ftoa(deltas->zoom, buffer, 6);
    write(fd, buffer, my_strlen(buffer));
    write(fd, "\n", 1);
}

void get_this_save(all_t *window, angle_t *deltas)
{
    int fd = open(window->filepath, O_WRONLY);
    char *buffer = malloc(sizeof(char) * 60);

    my_memset(buffer, 0, 60);
    if (!fd)
        return;
    for (int x = 0; x < window->map_y; x += 1) {
        for (int y = 0; y < window->map_y; y += 1) {
            buffer = my_ftoa(window->pos[x][y].x, buffer, 6);
            write(fd, buffer, my_strlen(buffer));
            write(fd, " ", 1);
            buffer = my_ftoa(window->pos[x][y].y, buffer, 6);
            write(fd, buffer, my_strlen(buffer));
            write(fd, "\n", 1);
        }
    }
    save_angles(deltas, fd, buffer);
    free (buffer);
    close (fd);
}

sfVector2f **read_save(all_t *window, angle_t *deltas)
{
    sfVector2f **tab = create_2d_map(0.0, deltas, 0.0, window);
    int fd = open(window->filepath, O_RDONLY);
    char *temp = NULL;
    char **array = NULL;

    if (!fd)
        return (tab);
    temp = malloc(sizeof(char) * 2216160);
    my_memset(temp, 0, 2216160);
    if (read(fd, temp, 2216160) <= 0) {
        free (temp);
        return (tab);
    }
    array = my_str_to_word_array(temp, " \n");
    tab = modif_with_array(tab, array, deltas, window);
    for (int index = 0; array[index]; index += 1)
        free (array[index]);
    free (array);
    close (fd);
    free (temp);
    return (tab);
}