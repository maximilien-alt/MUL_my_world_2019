/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** noise.c
*/

#include "../include/my.h"

void get_new_map(all_t *window)
{
    int *perm = get_random_tab();
    float x_off = 0.0;
    float y_off = 0.0;

    for (int y = 0; y < window->map_y; y += 1) {
        x_off = 0;
        for (int x = 0; x < window->map_x; x += 1) {
            window->map[y][x] = bruit_perlin(x_off, y_off, perm) * 350;
            x_off += 0.1;
        }
        y_off += 0.1;
    }
    free (perm);
}

int check_same(int *tab)
{
    int save = 0;
    int temp = 0;
    int index = 0;

    for (index = 0; index < 255 && tab[index + 1] != -1; index += 1);
    save = tab[index];
    for (temp = 0; index < 256 && tab[temp] != save && tab[temp] != -1;\
    temp += 1);
    if (temp == index)
        return (0);
    return (84);
}

int *get_random_tab(void)
{
    int *tab = malloc(sizeof(int) * 256);

    for (int index = 0; index < 256; index += 1)
        tab[index] = -1;
    for (int index = 0; index < 256; index += 1) {
        tab[index] = rand() % 256;
        while (check_same(tab) == 84)
            tab[index] = rand() % 256;
    }
    return (tab);
}

float final_calc(float temp_x, float temp_y, float *tab)
{
    float check[2];
    float liss[2];

    check[0] = 3 * temp_x * temp_x - 2 * temp_x * temp_x * temp_x;
    liss[0] = tab[0] + check[0] * (tab[1] - tab[0]);
    liss[1] = tab[2] + check[0] * (tab[3] - tab[2]);
    check[1] = 3 * temp_y * temp_y - 2 * temp_y * temp_y * temp_y;
    return (liss[0] + check[1] * (liss[1] - liss[0]));
}

float bruit_perlin(float x, float y, int *perm)
{
    float temp[2];
    int gi[6];
    float srt = 1.0/sqrt(2);
    float tab[4];
    float grad[8][2] = {{srt, srt}, {-srt, srt}, {srt, -srt}, \
    {-srt, -srt}, {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    for (int index = 0; index < 4; index += 1) {
        temp[0] = (index % 2 == 0) ? x - (int)x : x - ((int)x + 1);
        temp[1] = (index < 2) ? y - (int)y : y - ((int)y + 1);
        gi[0] = (index % 2 == 0) ? 0 : 1;
        gi[1] = (index < 2) ? 0 : 1;
        gi[index + 2] = perm[(int)x + gi[0] + perm[(int)y + gi[1]]] % 8;
        tab[index] = grad[gi[index + 2]][0]*temp[0] + \
        grad[gi[index + 2]][1]*temp[1];
    }
    return (final_calc(x - (int)x, y - (int)y, tab));
}