#include "fractol.h"

static	void	mouse_set_zoom(t_collection *c, int x, int y, int is_zoom_in)
{
	long double	delta_zoom;
	t_vector2f	delta_offset;

	delta_offset.x = x * ((c->scaler.max.x - c->scaler.min.x)
		/ WIDTH) + c->scaler.min.x;
	delta_offset.y = y * ((c->scaler.max.y - c->scaler.min.y)
		/ HEIGHT) + c->scaler.min.y;
	delta_zoom = is_zoom_in ? (1.0f - ZOOM_SPEED) : (1.0f + ZOOM_SPEED);
	if (c->zoom * delta_zoom > MIN_ZOOM && c->zoom * delta_zoom < MAX_ZOOM)
	{
		c->zoom *= delta_zoom;
		c->scaler.max.x = c->scaler.max.x * delta_zoom
		+ delta_offset.x * (1.0f - delta_zoom);
		c->scaler.min.x = c->scaler.min.x * delta_zoom
		+ delta_offset.x * (1.0f - delta_zoom);
		c->scaler.max.y = c->scaler.max.y * delta_zoom
		+ delta_offset.y * (1.0f - delta_zoom);
		c->scaler.min.y = c->scaler.min.y * delta_zoom
		+ delta_offset.y * (1.0f - delta_zoom);
	}
}

int				mouse_zoom_manager(int keycode, int x, int y, t_collection *c)
{
	if (keycode == MOUSE_L_CL || keycode == MOUSE_WHEEL_IN)
		mouse_set_zoom(c, x, y, 1);
	if (keycode == MOUSE_R_CL || keycode == MOUSE_WHEEL_OUT)
		mouse_set_zoom(c, x, y, 0);
	draw_image(c);
	return (1);
}

int				mouse_change_julia_input(int x, int y, t_collection *c)
{
	if (c->julia_interact)
	{
		c->c = new_complex_number((MAP(x, 0.0f, WIDTH, -1.0f, 1.0f)),
		(MAP(y, 0.0f, WIDTH, -1.0f, 1.0f)));
		draw_image(c);
	}
	return (1);
}
