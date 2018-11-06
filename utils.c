#include "fractol.h"

int				check_name(int *type, char *arg)
{
	*type = ft_atoi(arg);
	if (*type < 1 || *type > 6)
		return (0);
	return (1);
}

t_complex_num	new_complex_number(long double r, long double i)
{
	t_complex_num c;

	c.r = r;
	c.i = i;
	return (c);
}

t_rgb			new_rgb(int red, int green, int blue)
{
	t_rgb col;

	red = CLAMP(red, 2, 254);
	blue = CLAMP(blue, 2, 254);
	green = CLAMP(green, 2, 254);
	col.red = red;
	col.blue = blue;
	col.green = green;
	return (col);
}

void			put_pixel_to_img(char **img, t_vector2 p, t_rgb rgb)
{
	if (p.x < LIMIT_PIXEL_WIN_EDGE || p.x > WIDTH - LIMIT_PIXEL_WIN_EDGE - 1
	|| p.y < LIMIT_PIXEL_WIN_EDGE || p.y > HEIGHT - LIMIT_PIXEL_WIN_EDGE - 1)
		return ;
	(*img)[(p.x * 4) + (p.y * 4 * WIDTH)] = rgb.blue;
	(*img)[(p.x * 4) + (p.y * 4 * WIDTH) + 1] = rgb.green;
	(*img)[(p.x * 4) + (p.y * 4 * WIDTH) + 2] = rgb.red;
}
