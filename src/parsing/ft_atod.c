/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 14:34:22 by asouchet          #+#    #+#             */
/*   Updated: 2023/09/28 15:25:43 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

double	ft_atod(char *str, t_data *data)
{
	double	res;
	double	neg;
	double	tmp;
	int		count;
	int		i;

	i = 0;
	count = 0;
	neg = 1.0;
	res = 0.0;
	tmp = 0.0;
	if (str[i] == '-')
	{
		neg = -1.0;
		i++;
	}
	while (str[i] && str[i] != '.')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			res = (res * 10) + (str[i] - 48);
			i++;
		}
		else
		{
			data->error = 6;
			return (res);
		}
	}
	if (str[i] == '.')
	{
		i++;
		while (str[i])
		{
			if (str[i] <= '0' && str[i] >= '9')
				data->error = 6;
			tmp = (tmp * 10) + (str[i] - 48);
			i++;
			count++;
		}
		tmp = tmp / pow(10.0, (double)count);
	}
	res += tmp;
	return (res * neg);
}
