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
	return (rgb);
}
