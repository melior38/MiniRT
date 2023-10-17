/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 08:46:04 by asouchet          #+#    #+#             */
/*   Updated: 2023/10/17 17:09:39 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

int	my_mlx_get_color_value(int red, int green, int blue)
{
	return ((red << 16) | (green << 8) | blue);
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
	int		color;
	double 	t;
	// t_o_type res;

	x = 0;
	y = 0;
	t = HUGE_VAL;
	ray.origin = data->param->camera->coor;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGTH)
		{
			init_ray(data, x, y, &ray);
			color = pixel_color_sphere(ray, loop_sphere(data->param, ray, &t), data->param->alight, data->param->miss);
			// res = intersect_with_all(data->param, ray, &t);
			// if (res == SPHERE)
			// {
			// 	// printf("salut on est dans sphere\n");
			// 	color = pixel_color_sphere(ray, data->param->sp_choosed->rgb, data->param->sp_choosed, data->param->alight);
			// }
			// if (res == CYLINDER)
			// {
			// 	// printf("salut on est dans cylinder\n");
			// 	color = pixel_color_cylinder(ray, data->param->cy_choosed->rgb, data->param->cy_choosed, data->param->alight);
			// }
			// if (res == PLANE)
			// {
			// 	// printf("salut on est dans plane\n");
			// 	color = pixel_color_plane(ray, data->param->pl_choosed->rgb, data->param->pl_choosed, data->param->alight);
			// }
			my_mlx_pixel_put(data, x, y, color);
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

void	show_obj(t_data *data)
{
	printf("Ambient light :\n");
	show_alight(data);
	printf("Camera :\n");
	show_camera(data);
	printf("light :\n");
	show_light(data);
	printf("Plane :\n");
	show_plane(data);
	printf("Sphere :\n");
	show_sphere(data);
	printf("Cylinder :\n");
	show_cylinder(data);
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