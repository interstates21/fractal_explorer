#include "fractol.h"

static void			*render_this_frame(void *data_ptr)
{
	int				i;
	int				j;
	int				fractal_depth;
	t_render_data	*data;

	data = (t_render_data*)data_ptr;
	j = 0;
	while (j < HEIGHT)
	{
		i = data->range.min_x;
		while (i < data->range.max_x)
		{
			fractal_depth = data->calculate(*data, new_vec2(i, j));
			put_pixel_to_img(&(data->img), new_vec2(i, j),
			set_color(data->shading, fractal_depth, data->depth));
			i++;
		}
		j++;
	}
	pthread_exit(0);
}

void				start_threads(t_collection *c)
{
	pthread_t		threads[N_THREADS];
	t_render_data	data[N_THREADS];
	int				i;

	i = 0;
	while (i < N_THREADS)
	{
		data[i].range.min_x = i * (WIDTH / N_THREADS);
		data[i].range.max_x = (i + 1) * (WIDTH / N_THREADS);
		data[i].scaler = c->scaler;
		data[i].depth = c->depth;
		data[i].shading = c->shading;
		data[i].calculate = c->calculate;
		data[i].img = c->mlx.img_string;
		data[i].zoom = c->zoom;
		data[i].c = c->c;
		pthread_create(&threads[i], NULL, render_this_frame, &data[i]);
		i++;
	}
	i = 0;
	while (i < N_THREADS)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
}
