/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 08:46:04 by asouchet          #+#    #+#             */
/*   Updated: 2023/10/03 15:50:15 by asouchet         ###   ########.fr       */
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
	t_axis	pixel;
	t_axis	tmp;

	x = 0;
	y = 0;
	tmp = data->param->corner;
	get_win_scale(data->param);
	while (x < WIDTH)
	{
		y = 0;
		pixel = tmp;
		while (y < HEIGTH)
		{
			// my_mlx_pixel_put(data, x, y, my_mlx_get_color_value(23, 45, 200));
			little_main_for_pixel(data, pixel, x, y);
			pixel = add_vec(pixel, data->param->dir.shift_y);
			y++;
		}
		x++;
		tmp = add_vec(tmp, data->param->dir.shift_x);
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
	t_data *tmp;
	tmp = &data;
	// t_referential	ref = set_referential(tmp->param->camera->vector);
	// printf("1 : ref.x = {%f} \nref.y = {%f}\nref.z = {%f}\n", ref.x.x, ref.x.y, ref.x.z);
	// printf("2 : ref.x = {%f} \nref.y = {%f}\nref.z = {%f}\n", ref.y.x, ref.y.y, ref.y.z);
	// printf("3 : ref.x = {%f} \nref.y = {%f}\nref.z = {%f}\n", ref.z.x, ref.z.y, ref.z.z);
	show_obj(&data);
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
	mlx_loop_hook(mlx, render_next_frame, &data);
	mlx_loop(mlx);
}