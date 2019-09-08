#ifndef FRACTOL_H
#define FRACTOL_H

#include <unistd.h>
#include <math.h>
#include <fcntl.h>
#include "libft/libft.h"
#include <stdlib.h>
#include "MinilibX/sierra/mlx.h"
#include <pthread.h>
#include <stdio.h>

#define WIDTH 900
#define HEIGHT 600
#define WIN_NAME "Fractal Explorer"
#define MOV_SPEED 0.1
#define DEPTH_SPEED 10
#define ZOOM_SPEED 0.1f

#define CLAMP(x, x1, x2) (((x) > (x2)) ? (x2) : (((x) < (x1)) ? (x1) : (x)))
#define MAP(x, x1, x2, y1, y2) ((y1) + ((x) - (x1)) * ((y2) - (y1)) / ((x2) - (x1)))
#define HOOK_PRESS_KEY 2
#define HOOK_RESET_KEY 5
#define HOOK_RED_CROSS_IN 17
#define HOOK_RED_CROSS_OUT 0

#define KEY_EXIT 53
#define KEY_MOV_LEFT 123
#define KEY_MOV_RIGHT 124
#define KEY_MOV_UP 125
#define KEY_MOV_DOWN 126
#define KEY_DEPTH_MIN 78
#define KEY_DEPTH_PLUS 69
#define KEY_ZOOM_MIN 78
#define KEY_ZOOM_PLUS 69
#define KEY_NEXT_COLOR 18
#define KEY_COLOR_FADE 19
#define KEY_NEXT_FRACTAL 19
#define KEY_JULIA_INTERACTIVE 48
#define KEY_SET_DEFAULTS 15
#define LIMIT_PIXEL_WIN_EDGE 50

#define MOUSE_L_CL 1
#define MOUSE_R_CL 2
#define MOUSE_WHEEL_IN 5
#define MOUSE_WHEEL_OUT 4
#define MIN_ZOOM 0.00000000001f
#define MAX_ZOOM 3
#define MIN_DEPTH -10
#define MAX_DEPTH 10

#define HOOK_MOUSE_MOTION 6
#define HOOK_MOUSE_NMOTION (1L << 6)
#define COL_D 0x999999
#define N_THREADS 8
#define INITIAL_DEPTH 100

typedef struct s_rgb
{
	int red;
	int green;
	int blue;
} t_rgb;

typedef struct s_complex_num
{
	long double r;
	long double i;
} t_complex_num;

typedef struct s_vector2f
{
	long double x;
	long double y;
} t_vector2f;

typedef struct s_vector4f
{
	t_vector2f min;
	t_vector2f max;
} t_vector4f;

typedef struct s_vector2
{
	int x;
	int y;
} t_vector2;

typedef struct s_mlx
{
	void *init;
	void *win;
	void *img;
	char *img_string;
	int endian;
	int line_size;
	int bpp;
} t_mlx;

typedef struct s_shading
{
	t_rgb col;
	int color_type;
} t_shading;

typedef struct s_range
{
	long double min_x;
	long double mix_y;
	long double max_x;
	long double max_y;
} t_range;

typedef struct s_render_data
{
	t_vector4f scaler;
	t_shading shading;
	long double depth;
	t_range range;
	char *img;
	long double zoom;
	t_complex_num c;
	int (*calculate)(struct s_render_data data, t_vector2 p);
} t_render_data;

typedef struct s_collection
{
	int color;
	int color_fade;
	int color_id;
	int type;
	t_mlx mlx;
	t_complex_num c;
	t_vector4f scaler;
	t_shading shading;
	int depth;
	long double zoom;
	int julia_interact;
	int (*calculate)(t_render_data data, t_vector2 p);
} t_collection;

int mouse_zoom_manager(int keycode, int x, int y, t_collection *c);
void key_set_movement(int keycode, t_collection *c);
void key_set_zoom_and_depth(int keycode, t_collection *c);
void key_utils(int keycode, t_collection *c);

void print_instructions(int type);
int print_error(int error_code);
int listen_exit(void);
void start_threads(t_collection *c);
int calculate_rabbit(t_render_data data, t_vector2 p);
int calculate_sierp(t_render_data data, t_vector2 p);
int calculate_ship(t_render_data data, t_vector2 p);
int calculate_julia(t_render_data data, t_vector2 p);
int calculate_mandel(t_render_data data, t_vector2 p);
int calculate_cat(t_render_data data, t_vector2 p);
t_rgb new_rgb(int red, int green, int blue);
t_complex_num new_complex_number(long double r, long double i);
t_vector2f new_vec2f(long double x, long double y);
t_vector2 new_vec2(int x, int y);
int mouse_change_julia_input(int x, int y, t_collection *c);

void put_pixel_to_img(char **img, t_vector2 p, t_rgb rgb);
void draw_image(t_collection *c);
t_rgb set_color(t_shading shading, int depth, int max_depth);
int set_defaults(t_collection *c);
void display_menu(t_collection *c);
void key_set_depth(int keycode, t_collection *c);
void print_instruction();
int check_name(int *type, char *arg);
#endif
