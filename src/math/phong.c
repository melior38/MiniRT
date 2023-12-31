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

t_rgb	i_diffuse_cy(t_inter p, t_cylinder *cylinder)
{
	t_rgb	i_diffuse;
	t_pos	n;
	t_pos	l;
	double	dot_nl;

	n = get_n_cylinder(cylinder, p);
	normed_vec(&n);
	l = subs_vec(p.light_pos, p.inter_point);
	normed_vec(&l);
	dot_nl = dot_product(n, l);
	i_diffuse = change_intensity(change_intensity
			(p.light_color, p.light_bright), fmax(0, dot_nl));
	return (i_diffuse);
}

t_rgb	phong_cy(t_inter p, t_cylinder *cylinder)
{
	t_rgb	final_color;

	final_color = addition_color(change_intensity
			(p.a_mod_color, p.light_bright),
			i_diffuse_cy(p, cylinder));
	final_color = multiplication_color(final_color, cylinder->rgb);
	return (final_color);
}

t_rgb	i_diffuse_pl(t_inter p, t_plane *plane)
{
	t_rgb	i_diffuse;
	t_pos	n;
	t_pos	l;
	double	dot_nl;

	n = plane->vector;
	normed_vec(&n);
	l = subs_vec(p.light_pos, p.inter_point);
	normed_vec(&l);
	dot_nl = dot_product(n, l);
	i_diffuse = change_intensity(change_intensity
			(p.light_color, p.light_bright), fmax(0, dot_nl));
	return (i_diffuse);
}

t_rgb	phong_pl(t_inter p, t_plane *plane)
{
	t_rgb	final_color;

	final_color = addition_color(change_intensity
			(p.a_mod_color, p.light_bright),
			i_diffuse_pl(p, plane));
	final_color = multiplication_color(final_color, plane->rgb);
	return (final_color);
}
