#include "fractol.h"

static	t_rgb	color_mode_one(int depth, int max_depth)
{
	t_rgb	c;

	if (depth == max_depth)
		return (new_rgb(0, 0, 0));
	c.red = (depth * 5) % 110;
	c.blue = (depth * 5) % 255;
	c.green = (depth * 9) % 30;
	return (c);
}

static	t_rgb	color_mode_two(int depth, int max_depth)
{
	t_rgb	c;

	if (depth == max_depth)
		return (new_rgb(0, 0, 0));
	c.red = (depth * 6) % 255;
	c.blue = (depth * 8) % 255;
	c.green = (depth * 7) % 255;
	return (c);
}

static	t_rgb	color_mode_three(int depth, int max_depth)
{
	t_rgb	c;

	if (depth == max_depth)
		return (new_rgb(0, 0, 0));
	c.blue = (random() % 250);
	c.red = (depth * 8) % 255;
	c.green = (random() % 150);
	return (c);
}

static	t_rgb	color_mode_four(int depth, int max_depth)
{
	if (depth == max_depth)
		return (new_rgb(230, 230, 10));
	return (new_rgb(depth * 0.5, depth * 0.5, depth * 0.5));
}

t_rgb			set_color(t_shading shading, int depth, int max_depth)
{
	if (shading.color_type == 0)
		return (color_mode_one(depth, max_depth));
	else if (shading.color_type == 1)
		return (color_mode_two(depth, max_depth));
	else if (shading.color_type == 2)
		return (color_mode_three(depth, max_depth));
	return (color_mode_four(depth, max_depth));
}
