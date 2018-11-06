#include "fractol.h"

t_vector2	new_vec2(int x, int y)
{
	t_vector2 v;

	v.x = x;
	v.y = y;
	return (v);
}

t_vector2f	new_vec2f(long double x, long double y)
{
	t_vector2f v;

	v.x = x;
	v.y = y;
	return (v);
}
