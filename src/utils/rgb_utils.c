/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 09:05:31 by asouchet          #+#    #+#             */
/*   Updated: 2023/09/19 17:34:52 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

/// Convertit un string en struct rgb
/// \param str la string a convertir en rgb
/// \return
t_rgb	*rgb_converter(t_data *data, char *str)
{
	char	**split;
	t_rgb	*rgb;

	rgb = malloc(sizeof(t_rgb));
	if (!rgb)
		return (NULL);
	split = ft_split(str, ',');
	if (ft_atoi(split[0]) >= 0 && ft_atoi(split[0]) <= 255
		&& ft_atoi(split[1]) >= 0 && ft_atoi(split[1]) <= 255
		&& ft_atoi(split[2]) >= 0 && ft_atoi(split[2]) <= 255)
	{
		rgb->r = ft_atoi(split[0]);
		rgb->g = ft_atoi(split[1]);
		rgb->b = ft_atoi(split[2]);
	}
	else
		data->error = 2;
	free_tab(split);
	return (rgb);
}

t_axis	*ft_coor(char *str)
{
	t_axis	*new;
	char	**split;

	new = malloc(sizeof(t_axis));
	if (!new)
		return (NULL);
	split = ft_split(str, ',');
	new->x = ft_atod(split[0]);
	new->y = ft_atod(split[1]);
	new->z = ft_atod(split[2]);
	free_tab(split);
	return (new);
}

t_axis	*ft_vector(t_data *data, char *str)
{
	t_axis	*new;
	char	**split;

	new = malloc(sizeof(t_axis));
	if (!new)
		return (NULL);
	split = ft_split(str, ',');
	if (!split[0] || !split[1] || !split[2])
	{
		free_tab(split);
		return (NULL);
	}
	if (ft_atod(split[0]) >= -1.0 && ft_atoi(split[0]) <= 1.0
		&& ft_atod(split[1]) >= -1.0 && ft_atoi(split[1]) <= 1.0
		&& ft_atod(split[2]) >= -1.0 && ft_atoi(split[2]) <= 1.0)
	{
		new->x = ft_atod(split[0]);
		new->y = ft_atod(split[1]);
		new->z = ft_atod(split[2]);
	}
	else
		data->error = 3;
	free_tab(split);
	return (new);
}
