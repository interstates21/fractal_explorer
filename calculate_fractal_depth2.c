#include "fractol.h"

int		calculate_cat(t_render_data data, t_vector2 p)
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
		tmp_x = (mx * mx - my * my * mx * mx * mx) + data.c.r;
		my = data.c.r * mx * my + data.c.i;
		mx = tmp_x;
		i++;
	}
	return (i);
}
