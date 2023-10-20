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

double	get_digitbeforedot(t_data *data, const char *str, int i)
{
	double	res;

	res = 0.0;
	while (str[i] && str[i] != '.')
	{
		if (str[i] >= '0' && str[i] <= '9')
			res = (res * 10) + (str[i] - 48);
		else
		{
			data->error = 6;
			return (res);
		}
		i++;
	}
	return (res);
}

double	get_digitafterdot(const char *str, int i)
{
	double	res;
	int		count;

	count = 0;
	res = 0.0;
	if (str[i] == '.')
	{
		i++;
		while (str[i])
		{
			res = (res * 10) + (str[i] - 48);
			i++;
			count++;
		}
		res = res / pow(10.0, (double) count);
	}
	return (res);
}

double	ft_atod(char *str, t_data *data)
{
	double	res;
	double	neg;
	int		i;

	neg = 1.0;
	i = 0;
	if (str[i] == '-')
	{
		neg = -1.0;
		i++;
	}
	res = get_digitbeforedot(data, str, i);
	while (str[i] && str[i] != '.')
		i++;
	res += get_digitafterdot(str, i);
	return (res * neg);
}
