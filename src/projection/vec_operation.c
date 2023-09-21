/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 09:32:28 by asouchet          #+#    #+#             */
/*   Updated: 2023/09/21 11:24:36 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

// we need to norm the camera vec
void	i_don_t_know_how_to_name_it(t_vec cam_vec)
{
	t_vec	tmp;

	if (cam_vec.x || cam_vec.z)
		tmp = add_vec(tmp, (t_vec){0,1,0});
	else
	{
		tmp.x = cam_vec.y / vector_norm(cam_vec);
		tmp.y = 0;
		tmp.z = 0;
	}

	
}