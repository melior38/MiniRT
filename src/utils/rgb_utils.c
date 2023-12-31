/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 09:05:31 by asouchet          #+#    #+#             */
/*   Updated: 2023/10/11 10:43:28 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

/// Convertit un string en struct rgb
/// \param str la string a convertir en rgb
/// \return
t_rgb	rgb_converter(t_data *data, char *str)
{
	char	**split;
	t_rgb	rgb;

	rgb.r = 0;
	rgb.g = 0;
	rgb.b = 0;
	split = ft_split(str, ',');
	if (ft_atoi(split[0]) >= 0 && ft_atoi(split[0]) <= 255
		&& ft_atoi(split[1]) >= 0 && ft_atoi(split[1]) <= 255
		&& ft_atoi(split[2]) >= 0 && ft_atoi(split[2]) <= 255)
	{
		rgb.r = ft_atoi(split[0]);
		rgb.g = ft_atoi(split[1]);
		rgb.b = ft_atoi(split[2]);
	}
	else
		print_error(data, "Rgb not in range\n");
	free_tab(split);
	return (rgb);
}

t_pos	ft_coor(char *str, t_data *data)
{
	t_pos	new;
	char	**split;

	split = ft_split(str, ',');
	new.x = ft_atod(split[0], data);
	new.y = ft_atod(split[1], data);
	new.z = ft_atod(split[2], data);
	free_tab(split);
	return (new);
}

t_pos	ft_vector(t_data *data, char *str)
{
	t_pos	new;
	char	**split;

	new.x = 0;
	new.y = 0;
	new.z = 0;
	split = ft_split(str, ',');
	if (ft_atod(split[0], data) >= -1.0 && ft_atod(split[0], data) <= 1.0
		&& ft_atod(split[1], data) >= -1.0 && ft_atod(split[1], data) <= 1.0
		&& ft_atod(split[2], data) >= -1.0 && ft_atod(split[2], data) <= 1.0)
	{
		new.x = ft_atod(split[0], data);
		new.y = ft_atod(split[1], data);
		new.z = ft_atod(split[2], data);
	}
	else
		print_error(data, "Vector not in range\n");
	free_tab(split);
	return (new);
}
