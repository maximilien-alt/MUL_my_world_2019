/*
** EPITECH PROJECT, 2019
** my
** File description:
** include
*/

#ifndef MY_H_
#define MY_H_

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <errno.h>
#include <string.h>
#include <sys/sysmacros.h>
#include <signal.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Config.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <math.h>
#include <SFML/Graphics/Vertex.h>

#define WIDTH 1920
#define HEIGHT 1080

typedef enum
{
    MENU,
    PLANET_1,
    PLANET_2,
    PLANET_3,
    STARS,
    PLAY,
    OPTIONS,
    QUIT,
    FPS_BAR,
    FPS_SCROLL,
    VOLUME_BAR,
    VOLUME_SCROLL,
    TICK,
    PARAMS,
    RADIUS_SCROLL,
    RADIUS_BAR,
    SAVES,
    BACK,
    CLICK,
    UP,
    DOWN,
    LOAD,
    FILL,
    MOUSE,
    TOTAL
} SPRITES;

typedef struct game_object_s
{
    SPRITES type;
    sfSprite* sprite;
    sfTexture* texture;
    sfVector2f pos;
    sfIntRect rect;
    sfClock *clock;
    float seconds;
    int speed;
    int max;
    sfTime time;
    int cliked;
}game_object_t;

typedef struct framebuffer_s
{
    sfUint8 *pixels;
    int width;
    int height;
    sfTexture *texture;
    sfSprite *sprite;
}framebuffer_t;

typedef struct angle_s
{
    float delta_z;
    float delta_x;
    float delta_y;
    float angle_x;
    float angle_y;
    int zoom;
} angle_t;

typedef struct all_s
{
    int status;
    int fps;
    int volume;
    int map_y;
    int map_x;
    float **map;
    sfVector2f **pos;
    sfVector2i ref;
    sfRenderWindow *window;
    char *filepath;
    sfEvent event;
    sfColor **color;
    sfMusic *music;
    int parallax;
    int radius;
} all_t;

typedef struct format_t
{
    char c;
    void (*ptr)(va_list);
} format_t;

void update_tab_color_2(all_t *window, int x, int y);
game_object_t setup_object(char *filepath, sfVector2f pos, \
sfIntRect rect, SPRITES type);
void update_radius(game_object_t *object, sfVector2i mouse, all_t *window);
void manage_click_on_radius(all_t *window, game_object_t \
*object, sfVector2i mouse);
void draw_game(all_t *window, game_object_t *object);
int get_speed(int type);
void update_volume_bar(game_object_t *object, sfVector2i mouse, all_t *window);
void update_fps_bar(game_object_t *object, sfVector2i mouse, all_t *window);
void manage_click_on_options(all_t *window, sfVector2i \
mouse, game_object_t *object);
void update_tab_color(all_t *window);
int usage_print(void);
void    axe_top(all_t *window, int select_col);
void    axe_right(all_t *window, int select_col);
void    axe_bottom(all_t *window, int select_col);
void    axe_left(all_t *window, int select_col);
sfColor **setup_tab_color(all_t *window);
sfVertexArray *shape_top(int i, int j, all_t *window);
sfVertexArray *shape_right(int i, int j, all_t *window);
sfVertexArray *shape_bottom(int i, int j, all_t *window);
sfVertexArray *shape_left(int i, int j, all_t *window);
void terraforming(all_t *window, \
sfVector2i mouse, int offset);
void check_but(game_object_t *object, all_t *window, \
sfVector2i mouse, angle_t *deltas);
void manage_click_on_game(all_t *window, angle_t *deltas, \
sfVector2i mouse, game_object_t *object);
void object_on_game(game_object_t *object, sfVector2i mouse);
void get_new_map(all_t *window);
int *get_random_tab(void);
float get_that_noise(float x, float y);
float bruit_perlin(float x, float y, int *perm);
void manage_click_on_save(all_t *window, sfVector2i mouse, angle_t *deltas);
void object_on_save_screen(game_object_t \
*object, sfVector2i mouse);
void move_rect(game_object_t *game_object, int offset, \
int max_size, SPRITES type);
void object_on_menu(game_object_t *object, sfVector2i mouse);
void manage_mouse_moved(all_t *window, angle_t *deltas, \
game_object_t *object);
void my_create_game_object(game_object_t *game_object);
char *my_ftoa(float number, char *buffer, int afterpoint);
void get_this_save(all_t *window, angle_t *deltas);
sfVector2f **read_save(all_t *window, angle_t *deltas);
void fill_square(framebuffer_t *fb, \
sfVector2f *points, sfColor color);
void put_line(framebuffer_t *fb, sfVector2f point_1, \
sfVector2f point_2, sfColor color);
void update_map(all_t *window, angle_t *deltas);
sfVector2f **create_2d_map(float temp_y, angle_t *deltas, \
float temp_x, all_t *window);
sfVector2f project_iso_point(int x, int y, float z, angle_t *deltas);
void please_rotate_left(all_t *window);
void please_rotate_right(all_t *window);
void manage_key_pressed(all_t *window, sfEvent *event, \
angle_t *deltas, game_object_t *object);
void manage_drag(all_t *window, angle_t *deltas, game_object_t *object);
void manage_mouse_click(all_t *window, angle_t *deltas, game_object_t *object);
void manage_zoom(all_t *window, int delta, angle_t *deltas);
void put_pixel(framebuffer_t *fb, unsigned int x, \
unsigned int y, sfColor col);
framebuffer_t *create_buffer(int width, int height);
void refresh_pixel(framebuffer_t *fb, sfRenderWindow *window);
void clear_fade(framebuffer_t *fb, int alpha);
void draw_2d_map(all_t *window);
void destroy_objects(all_t *window);
void draw_window(all_t *window, angle_t *deltas, \
framebuffer_t *fb, game_object_t *object);
void analyse_events(all_t *window, angle_t *deltas, \
game_object_t *object);
void loop_game(all_t *window, framebuffer_t *fb, \
angle_t *deltas, game_object_t *object);
void set_structures(all_t *window, angle_t *deltas);
double my_getfloat(char *str);
void my_memset(char *buffer, char c, int number);
int    my_putnbr_base(int nbr, char const *base);
int    my_compute_power_rec(int nb, int p);
int    my_compute_square_root(int nb);
int    my_find_prime_sup(int nb);
int    my_getnbr(char const *str);
int    my_isneg(int n);
int    my_is_prime(int nb);
int    my_lengh(char const *str);
char    **my_malloc_words(char const *str, char **tab);
void    my_putchar(char c);
void    my_put_nbr(int nb);
int     my_putstr(char const *str);
char *my_float_to_ascii(double number);
char *int_to_str(int number);
char *float_to_str(double number);
char    *my_revstr(char *str);
int    my_showmem(char const *str, int size);
int    my_showstr(char const *str);
int    my_show_word_array(char * const *tab);
void    my_sort_int_array(int *tab, int size);
char    *my_strcapitalize(char *str);
char    *my_strcat(char *dest, char *src, int check);
char    my_strcmp(char *s1, char *s2);
char    *my_strcpy(char *dest, char const *src);
char    *my_strcpy2(char *dest, char const *src);
char    *my_strdup(char const *src);
int    my_str_isalpha(char const *str);
int    my_str_islower(char const *str);
int    my_str_isnum(char const *str);
int    my_str_isprintable(char const *str);
int    my_str_isupper(char const *str);
int    my_strlen(char const *str);
char    *my_strlowcase(char *str);
char    *my_strncat(char *dest, char const *src, int nb);
int    my_strncmp(char *s1, char *s2, int n);
char    *my_strncpy(char *dest, char const *src, int n);
char    *my_strstr(char *str, char const *to_find);
char    **my_str_to_word_array(char const *str, char *operator);
char    *my_strupcase(char *str);
void    my_swap(int *a, int *b);
int    my_prime(int nb);
int    my_strlen4(char const *str);
void    my_swap3(char const *dest, char const *src);
void    **my_malloc_word(char const *str, char * const *tab);
int    my_word_number(char const *str);
char   **my_word_in_tab(char const *str, char *const *tab);
int    my_str_neg(char *str, char *str2);
char    *my_infin_add_neg(char *str, char *str2);
int    my_str_is_negative(char *str);
char    *my_str_delete_null(char *str);
char    *my_cpy_without_null(char *str, char *cpy, int letter, int zero);
char    *my_supr_null(char *str, char *cpy, int letter);
char    *my_str_is_easy(char *str, char *cpy);
int    my_int_nbr(char const *str, int letter, int size, char **endptr);
int    my_delete_non_null(char const *str);
int    my_str_tol_error(char const *str);
char    *my_infin_add(char *str, char *str2);
char    *my_infin_add_neg(char *str, char *str2);
int    my_infin_cmp(char *str, char *str2);
char *my_supr_same(char *str, char *strtemp);
char *my_delete_neg(char *str);
char *my_strtemp(char *str, char *div);
int my_mult_zero(char *mult);
char *my_add_x_zero(int cursor);
int    my_clean_add_total(char *str, char *mult);
char *my_delete_mult(char *mult);
char *my_zeroo(char *str, char *mult);
char *my_infin_tol(char *str, char **endptr);
int my_bistro_error(int ac, char **av, char *buff);
char *my_infin_sub(char *str, char *str2);
int my_occ(char *str);
void my_putchar(char c);
void my_print_s(va_list ap);
void my_print_c(va_list ap);
void my_print_d(va_list ap);
void my_print_p(va_list ap);
void my_print_x(va_list ap);
void my_print_upcase_x(va_list ap);
void my_print_o(va_list ap);
void my_print_b(va_list ap);
void my_print_u(va_list ap);
void my_print_tab(va_list ap);
void my_print_upcase_s(va_list ap);
void my_printf(char *format, ...);

#endif /* MY_H_ */