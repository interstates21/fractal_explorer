#include "fractol.h"

int				set_defaults(t_collection *c)
{
	if (c->type == 1)
		c->calculate = calculate_mandel;
	else if (c->type == 2)
		c->calculate = calculate_julia;
	else if (c->type == 3)
		c->calculate = calculate_rabbit;
	else if (c->type == 4)
		c->calculate = calculate_sierp;
	else if (c->type == 5)
		c->calculate = calculate_ship;
	else
		c->calculate = calculate_cat;
	c->c = new_complex_number(-0.70176f, -0.3842f);
	c->julia_interact = 0;
	c->scaler.min = new_vec2f(-1.5f, -1.0f);
	c->scaler.max = new_vec2f(1.0f, 1.5f);
	c->zoom = 2.0f;
	c->depth = INITIAL_DEPTH;
	c->shading.color_type = 0;
	start_threads(c);
	mlx_put_image_to_window(c->mlx.init, c->mlx.win, c->mlx.img, 0, 0);
	display_menu(c);
	return (1);
}

void			draw_image(t_collection *c)
{
	start_threads(c);
	mlx_put_image_to_window(c->mlx.init, c->mlx.win, c->mlx.img, 0, 0);
	display_menu(c);
}

int				listen_keys_and_render_frame(int keycode, t_collection *c)
{
	if (keycode == KEY_EXIT)
		listen_exit();
	if (keycode == KEY_SET_DEFAULTS)
		if (!set_defaults(c))
			return (print_error(2));
	key_set_movement(keycode, c);
	key_set_depth(keycode, c);
	key_utils(keycode, c);
	draw_image(c);
	return (1);
}

static void		start_loops(t_collection c)
{
	mlx_hook(c.mlx.win,
	HOOK_PRESS_KEY, HOOK_RESET_KEY, listen_keys_and_render_frame, &c);
	mlx_mouse_hook(c.mlx.win, mouse_zoom_manager, &c);
	mlx_hook(c.mlx.win,
	HOOK_MOUSE_MOTION, HOOK_MOUSE_NMOTION, mouse_change_julia_input, &c);
	mlx_hook(c.mlx.win,
	HOOK_RED_CROSS_IN, HOOK_RED_CROSS_OUT, listen_exit, &c);
	mlx_loop(c.mlx.init);
}

int				main(int argc, char **argv)
{
	t_collection c;

	if (argc != 2)
		return (print_error(0));
	if (!check_name(&(c.type), argv[1]))
		return (print_error(0));
	if (!(c.mlx.init = mlx_init()))
		return (print_error(2));
	if (!(c.mlx.win = mlx_new_window(c.mlx.init, WIDTH, HEIGHT, WIN_NAME)))
		return (print_error(2));
	if (!(c.mlx.img = mlx_new_image(c.mlx.init, WIDTH, HEIGHT)))
		return (print_error(2));
	if (!(c.mlx.img_string = mlx_get_data_addr(c.mlx.img,
	&c.mlx.bpp, &c.mlx.line_size, &c.mlx.endian)))
		return (0);
	if (!set_defaults(&c))
		return (print_error(2));
	print_instruction();
	start_loops(c);
	return (0);
}
