#include "fractol.h"

void		key_set_depth(int keycode, t_collection *c)
{
	if (keycode == KEY_DEPTH_PLUS)
		c->depth += DEPTH_SPEED;
	if (keycode == KEY_DEPTH_MIN)
		c->depth -= DEPTH_SPEED;
}

void		key_set_movement(int keycode, t_collection *c)
{
	if (keycode == KEY_MOV_LEFT)
	{
		c->scaler.min.x -= MOV_SPEED * c->zoom;
		c->scaler.max.x -= MOV_SPEED * c->zoom;
	}
	if (keycode == KEY_MOV_RIGHT)
	{
		c->scaler.min.x += MOV_SPEED * c->zoom;
		c->scaler.max.x += MOV_SPEED * c->zoom;
	}
	if (keycode == KEY_MOV_UP)
	{
		c->scaler.min.y += MOV_SPEED * c->zoom;
		c->scaler.max.y += MOV_SPEED * c->zoom;
	}
	if (keycode == KEY_MOV_DOWN)
	{
		c->scaler.min.y -= MOV_SPEED * c->zoom;
		c->scaler.max.y -= MOV_SPEED * c->zoom;
	}
}

void		key_utils(int keycode, t_collection *c)
{
	if (keycode == KEY_EXIT)
		listen_exit();
	if (keycode == KEY_NEXT_COLOR)
		c->shading.color_type = (c->shading.color_type + 1) % 4;
	if (keycode == KEY_JULIA_INTERACTIVE)
		c->julia_interact = !c->julia_interact;
	if (keycode == KEY_NEXT_FRACTAL)
	{
		c->type = (c->type + 1) % 6;
		set_defaults(c);
	}
	if (keycode == KEY_SET_DEFAULTS)
	{
		set_defaults(c);
		draw_image(c);
	}
}
