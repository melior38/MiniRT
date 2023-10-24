/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:48:08 by asouchet          #+#    #+#             */
/*   Updated: 2023/10/20 16:27:56 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

t_rgb	i_diffuse_sp(t_inter p, t_sphere *sphere)
{
	t_rgb	i_diffuse;
	t_pos	n;
	t_pos	l;
	double	dot_nl;

	n = subs_vec(p.inter_point, sphere->coor);
	normed_vec(&n);
	l = subs_vec(p.light_pos, p.inter_point);
	normed_vec(&l);
	dot_nl = dot_product(n, l);
	i_diffuse = change_intensity(change_intensity
			(p.light_color, p.light_bright),
			fmax(0, dot_nl));
	return (i_diffuse);
}

t_rgb	phong_sp(t_inter p, t_sphere *sphere)
{
	t_rgb	final_color;

	final_color = addition_color(p.a_mod_color, i_diffuse_sp(p, sphere));
	final_color = multiplication_color(final_color, sphere->rgb);
	return (final_color);
}
