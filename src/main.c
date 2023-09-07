/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 08:46:04 by asouchet          #+#    #+#             */
/*   Updated: 2023/09/07 18:15:42 by asouchet         ###   ########.fr       */
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

void	ft_minirt(int x, int y, t_data *data)
{

}

int	render_next_frame(void *yourstruct)
{
	t_data	*data;
	int		x;
	int		y;

	data = (t_data *)yourstruct;
	x = 0;
	y = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGTH)
		{
			ft_minirt();
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	return (0);
}

int	main(int ac, char **av)
{
	(void)	ac;
	(void)	**av;
	void	*mlx_win;
	void	*mlx;
	t_data	data;
	
	

	// parsing(av);
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