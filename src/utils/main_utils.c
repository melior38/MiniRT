/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 08:46:04 by asouchet          #+#    #+#             */
/*   Updated: 2023/11/09 14:08:45 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

// void	init_sp(t_data *data)
// {
// 	t_sphere	*sp;

// 	sp = malloc(sizeof(t_sphere));
// 	if (!sp)
// 		print_error(data ,"something went wrong");
// 	sp->coor.x = 0;
// 	sp->coor.y = 0;
// 	sp->coor.z = 0;
// 	sp->diam = 0;
// 	sp->id = -1;
// 	sp->next = NULL;
// 	sp->rgb.r = 0;
// 	sp->rgb.g = 0;
// 	sp->rgb.b = 0;
// 	data->param->sphere = sp;
// }

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
