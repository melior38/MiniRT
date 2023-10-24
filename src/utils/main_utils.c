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
	data->tmp = NULL;
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 53)
		free_struct(data);
	return (0);
}
