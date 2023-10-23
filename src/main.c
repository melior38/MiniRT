/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 08:46:04 by asouchet          #+#    #+#             */
/*   Updated: 2023/10/23 12:55:28 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

int	my_mlx_get_color_value(t_rgb rgb)
{
	return ((rgb.r << 16) | (rgb.g << 8) | rgb.b);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}


int	render_next_frame(t_data *data)
{
	int		x;
	int		y;
	t_ray	ray;
	t_rgb	color;
	t_o_type res;

	x = 0;
	ray.origin = data->param->camera->coor;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGTH)
		{
			data->param->p.dist = HUGE_VAL;
			init_ray(data, x, y, &ray);
			res = intersect_with_all(data->param, ray, &data->param->p.dist);
			if (res == SPHERE)
				color = get_pixel_color_sp(update_intersection(data->param, &data->param->p, ray), data->param, data->param->sp_choosed, ray);
			if (res == CYLINDER)
				color = get_pixel_color_cy(update_intersection(data->param, &data->param->p, ray), data->param, data->param->cy_choosed, ray);
			if (res == PLANE)
				color = get_pixel_color_pl(update_intersection(data->param, &data->param->p, ray), data->param, data->param->pl_choosed, ray);
			my_mlx_pixel_put(data, x, y, my_mlx_get_color_value(color));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	return (0);
}

void	ft_handle_error(int error)
{
	if (error == 1)
	{
		perror("Error\nWrong file name, make sure to input an ");
		perror("existing file wich end by a .rt\n");
		exit(1);
	}
	if (error == 2)
	{
		perror("Error\nBad file composition\n");
		exit(1);
	}
}

void	init_data(t_data *data)
{
	data->img = NULL;
	data->addr = NULL;
	data->mlx = NULL;
	data->mlx_win = NULL;
	data->bits_per_pixel = 0;
	data->line_length = 0;
	data->endian = 0;
	data->error = 0;
	data->param = NULL;
}

int	key_hook(int keycode, t_data *data)
{
    if (keycode == 53)
        free_struct(data);
    return (0);
}

int	main(int ac, char **av)
{
	void	*mlx_win;
	void	*mlx;
	t_data	data;

	if (ac != 2)
	{
		perror("wrong amount of argument \n");
		exit(1);
	}
	init_data(&data);
	parsing(&data, ac, av[1]);
	set_obj_id(&data);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGTH, "MiniRT");
	data.img = mlx_new_image(mlx, WIDTH, HEIGTH);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length,
			&data.endian);
	data.mlx = mlx;
	data.mlx_win = mlx_win;
	// mlx_hook(mlx_win, ON_KEYUP, 0, ft_offset_hook, &img);
	// mlx_hook(mlx_win, ON_DESTROY, 0, ft_handle_exit, &img);
	// mlx_hook(mlx_win, ON_MOUSEDOWN, 0, ft_mouse_press, &img);
	// mlx_hook(mlx_win, ON_MOUSEUP, 0, ft_mouse_release, &img);
    mlx_hook(data.mlx_win, 2, 1L << 0, key_hook, &data);
    mlx_hook(data.mlx_win, 17, 0, free_struct, &data);
	mlx_loop_hook(mlx, render_next_frame, &data);
	mlx_loop(mlx);
}