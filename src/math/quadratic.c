/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadratic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:00:13 by asouchet          #+#    #+#             */
/*   Updated: 2023/10/09 13:03:09 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

void		swap_doubles(double *a, double *b)
{
	double buffer;

	buffer = *a;
	*a = *b;
	*b = buffer;
}

int			solve_quadratic(t_pos params, double *x0, double *x1)
{
	double discr;
	double q;

	discr = pow(params.y, 2) - 4 * params.x * params.z;
	if (discr < 0)
		return (0);
	else if (discr == 0)
	{
		*x0 = -0.5 * params.y / params.x;
		*x1 = -0.5 * params.y / params.x;
	}
	else
	{
		if (params.y > 0)
			q = -1 * (params.y + sqrt(discr)) / 2;
		else
			q = -1 * (params.y - sqrt(discr)) / 2;
		*x0 = q / params.x;
		*x1 = params.z / q;
	}
	if (*x0 > *x1)
		swap_doubles(x0, x1);
	return (1);
}
