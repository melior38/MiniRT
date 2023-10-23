/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:21:44 by asouchet          #+#    #+#             */
/*   Updated: 2023/10/20 16:20:57 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"


t_rgb	change_intensity(t_rgb color, double intensity)
{
	t_rgb	new_color;

	if (intensity > 1)
		intensity = 1;
	else if (intensity < 0)
		intensity = 0;
	new_color.r = color.r * intensity;
	new_color.g = color.g * intensity;
	new_color.b = color.b * intensity;
	return (new_color);
}

t_rgb	multiplication_color(t_rgb color1, t_rgb color2)
{
	t_rgb	new_color;

	new_color.r = color1.r * color2.r / 255;
	new_color.g = color1.g * color2.g / 255;
	new_color.b = color1.b * color2.b / 255;
	return (new_color);
}

t_rgb	addition_color(t_rgb color1, t_rgb color2)
{
	t_rgb	new_color;

	new_color.r = color1.r + color2.r;
	if (new_color.r > 255)
		new_color.r = 255;
	new_color.g = color1.g + color2.g;
	if (new_color.g > 255)
		new_color.g = 255;
	new_color.b = color1.b + color2.b;
	if (new_color.b > 255)
		new_color.b = 255;
	return (new_color);
}