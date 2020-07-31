/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** put_lines.c
*/

#include "../include/my.h"

void put_vertical_line(framebuffer_t *fb, sfVector2f point_1, \
sfVector2f point_2, sfColor color)
{
    if (point_1.y == point_2.y)
        return (put_pixel(fb, point_2.x, point_2.y, color));
    if (point_1.y - point_2.y > 0) {
        for (float index = point_2.y; index < point_1.y; index += 1)
            put_pixel(fb, point_2.x, index, color);
    } else {
        for (float index = point_1.y; index < point_2.y; index += 1)
            put_pixel(fb, point_1.x, index, color);
    }
}

void put_horizontal_line(framebuffer_t *fb, sfVector2f point_1, \
sfVector2f point_2, sfColor color)
{
    if (point_2.x == point_1.x)
        return (put_pixel(fb, point_2.x, point_2.y, color));
    if (point_1.x - point_2.x > 0) {
        for (float index = point_2.x; index < point_1.x; index += 1)
            put_pixel(fb, index, point_2.y, color);
    } else {
        for (float index = point_1.x; index < point_2.x; index += 1)
            put_pixel(fb, index, point_1.y, color);
    }
}

void put_diagonal_line(framebuffer_t *fb, sfVector2f point_1, \
sfVector2f point_2, sfColor color)
{
    float a = (float)(point_1.y - point_2.y) / (point_1.x - point_2.x);
    float b = point_1.y - a * point_1.x;
    float j = 0;

    if (point_1.x > point_2.x) {
        for (float index = point_1.x; index > point_2.x; index -= 1) {
            j = a * index + b;
            put_pixel(fb, index, round(j), color);
        }
    } else {
        for (float index = point_1.x; index < point_2.x; index += 1) {
            j = a * index + b;
            put_pixel(fb, index, round(j), color);
        }
    }
}

void put_line(framebuffer_t *fb, sfVector2f point_1, \
sfVector2f point_2, sfColor color)
{
    if (point_1.y == point_2.y)
        return (put_horizontal_line(fb, point_1, point_2, color));
    if (point_1.x == point_2.x)
        return (put_vertical_line(fb, point_1, point_2, color));
    return (put_diagonal_line(fb, point_1, point_2, color));
}