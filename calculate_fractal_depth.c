#include "fractol.h"

int		calculate_mandel(t_render_data data, t_vector2 p)
{
	register long double	mx;
	register long double	my;
	register long double	tmp_x;
	register int			i;

	i = 0;
	mx = 0.0;
	my = 0.0;
	data.c.r = MAP((long double)p.x, 0.0f,
	WIDTH, data.scaler.min.x, data.scaler.max.x);
	data.c.i = MAP((long double)p.y, 0.0f,
	HEIGHT, data.scaler.min.y, data.scaler.max.y);
	while (i < data.depth && (mx * mx + my * my) < 4.0f)
	{
		tmp_x = (mx * mx - my * my) + data.c.r;
		my = 2.0f * mx * my + data.c.i;
		mx = tmp_x;
		i++;
	}
	return (i);
}

int		calculate_julia(t_render_data data, t_vector2 p)
{
	register long double	mx;
	register long double	my;
	register long double	tmp_x;
	register int			i;

	i = 0;
	mx = MAP((long double)p.x, 0, WIDTH,
	data.scaler.min.x, data.scaler.max.x);
	my = MAP((long double)p.y, 0, HEIGHT,
	data.scaler.min.y, data.scaler.max.y);
	while (i < data.depth && (mx * mx + my * my) < 4.0f)
	{
		tmp_x = (mx * mx - my * my) + data.c.r;
		my = 2.0f * mx * my + data.c.i;
		mx = tmp_x;
		i++;
	}
	return (i);
}

int		calculate_ship(t_render_data data, t_vector2 p)
{
	register long double	mx;
	register long double	my;
	register long double	tmp_x;
	register int			i;

	i = 0;
	mx = 0.0;
	my = 0.0;
	data.c.r = MAP(p.x, 0, WIDTH,
	data.scaler.min.x, data.scaler.max.x);
	data.c.i = MAP(p.y, 0, HEIGHT,
	data.scaler.min.y, data.scaler.max.y);
	while (i < data.depth && (mx * mx + my * my) < 4.0f)
	{
		tmp_x = (mx * mx - my * my) + data.c.r;
		my = fabsl(2.0 * mx * my + data.c.i);
		mx = fabsl(tmp_x);
		i++;
	}
	return (i);
}

int		calculate_rabbit(t_render_data data, t_vector2 p)
{
	register long double	mx;
	register long double	my;
	register long double	tmp_x;
	register int			i;

	i = 0;
	mx = MAP((long double)p.x, 0, WIDTH,
	data.scaler.min.x, data.scaler.max.x);
	my = MAP((long double)p.y, 0, HEIGHT,
	data.scaler.min.y, data.scaler.max.y);
	while (i < data.depth && (mx * mx + my * my) < 4.0f)
	{
		tmp_x = (mx * mx - my * my) - 0.125;
		my = 2.0f * mx * my + 0.745f;
		mx = tmp_x;
		i++;
	}
	return (i);
}

int		calculate_sierp(t_render_data data, t_vector2 p)
{
	register int			i;

	i = 0;
	p.x *= data.zoom;
	p.y *= data.zoom;
	while (i < data.depth)
	{
		if ((p.x % 3 == 1) && (p.y % 3) == 1)
			return (0);
		p.x /= 3;
		p.y /= 3;
		i++;
	}
	return (data.depth - 1);
}
