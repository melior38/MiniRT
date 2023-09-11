/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 14:34:22 by asouchet          #+#    #+#             */
/*   Updated: 2023/09/11 10:17:22 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

double	ft_atof(char *str)
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
			return (123.123); // on verra plus tard comment faire pour detecter un soucis
	}
	if(str[i] == '.')
	{
		i++;
		while (str[i])
		{
			if (str[i] <= '0' && str[i] >= '9')
				return (0);
			tmp = (tmp * 10) + (str[i] - 48);
			i++;
			count++;
		}
		tmp = tmp / pow(10.0,(double)count);
	}
	res = res + tmp;
	return (res * neg);
}