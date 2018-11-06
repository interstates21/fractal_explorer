#include "fractol.h"

void	display_name(t_collection *c)
{
	if (c->type == 1)
		mlx_string_put(c->mlx.init,
		c->mlx.win, 80, HEIGHT - 80, COL_D, "MANDELBROT");
	else if (c->type == 2)
		mlx_string_put(c->mlx.init, c->mlx.win,
		80, HEIGHT - 80, COL_D, "JULIA");
	else if (c->type == 3)
		mlx_string_put(c->mlx.init, c->mlx.win,
		80, HEIGHT - 80, COL_D, "RABBIT");
	else if (c->type == 4)
		mlx_string_put(c->mlx.init, c->mlx.win,
		80, HEIGHT - 80, COL_D, "SIERPINSKY TRIANGLE");
	else if (c->type == 5)
		mlx_string_put(c->mlx.init, c->mlx.win,
		80, HEIGHT - 80, COL_D, "BURNING SHIP");
	else
		mlx_string_put(c->mlx.init, c->mlx.win,
		80, HEIGHT - 80, COL_D, "BIG CAT");
}

int		listen_exit(void)
{
	exit(0);
	return (0);
}

void	print_instruction(void)
{
	ft_putendl("CONTROLS:");
	ft_putendl(" [ARROWS] - move");
	ft_putendl(" [MOUSE WHEEL | MOUSE BUTTONS] - zoom");
	ft_putendl(" [+ | -] - max depth");
	ft_putendl(" [R] - reset");
	ft_putendl(" [1] - change color mode");
	ft_putendl(" [2] - change fractal");
	ft_putendl(" [TAB] - julia interactive ON/OFF");
	ft_putendl(" [ESK] - exit");
}

void	display_menu(t_collection *c)
{
	display_name(c);
}

int		print_error(int error_code)
{
	if (error_code == 0)
	{
		ft_putendl("USAGE: ./fractol [1 | 2 | 3 | 4 | 5]");
		ft_putendl("1 - MANDELBROT");
		ft_putendl("2 - JULIA");
		ft_putendl("3 - RABBIT");
		ft_putendl("4 - SIERPINSKY TRIANGLE");
		ft_putendl("5 - BURNING SHIP");
		ft_putendl("6 - BIG CAT");
	}
	if (error_code == 1)
		ft_putendl("FILE IS NOT VALID");
	if (error_code == 2)
		ft_putendl("MLX ERROR");
	if (error_code == 3)
		ft_putendl("VALID MAP SYMBOLS: [(0 - 9), (,), ( ), (-), (0x...)]");
	if (error_code == 4)
		ft_putendl("ALL MAPLINES MUST CONTAIN THE SAME AMOUNT OF ELEMENTS");
	if (error_code == 5)
		ft_putendl("THE MAP IS TOO SMALL");
	if (error_code == 10)
		ft_putendl("SYSTEM ERROR");
	return (0);
}
