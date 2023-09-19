/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MiniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 08:52:07 by asouchet          #+#    #+#             */
/*   Updated: 2023/09/11 13:52:39 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "libft.h"
# include <math.h>
# include <mlx.h>
# include <stdbool.h>

# define HEIGTH		768.0
# define WIDTH		1366.0
# define ERROR		0
# define SUCCESS	1
typedef struct s_axis {
	float	x;
	float	y;
	float	z;

}				t_axis;

typedef struct s_rgb {
	int	r;
	int	g;
	int	b;

}				t_rgb;

typedef struct s_object
{
	char				*id;
	double				ratio;
	int					fov;
	double				brightness;
	double 				diameter;
	double				height;
	t_axis				axis;
	t_axis 				axisnorm; //A changer ?
	t_rgb				rgb;
	struct t_object		*next;
}	t_object;

typedef struct s_sphere {
	t_axis	*sp_center;
	float	radius;
	t_rgb	*colour;

}				t_sphere;

typedef struct s_plane {
	t_axis	*pl_coor;
	t_axis	*vector;
	t_rgb	*rgb;

}				t_plane;

typedef struct s_cylinder {
	t_axis	*cy_center;
	t_axis	*vector;
	float	diameter;
	float	height;
	t_rgb	*rgb;

}				t_cylinder;

typedef struct s_light {
	t_axis	*view_point;
	float	brightness;
	t_rgb	*rgb;

}				t_light;

typedef struct s_ambient_light {
	t_rgb	*rgb;
	float	light_ratio;

}				t_ambient_light;

typedef struct s_camera {
	t_axis	*view_coor;
	t_axis	*vector;
	int		FOV;

}				t_camera;

typedef struct s_param {
	t_axis				*axe;
	t_ambient_light		*A_light;
	t_sphere			*spheres;
	t_plane				*plane;
	t_cylinder			*cylinders;
	t_light				*light;
	t_camera			*camera;
	int					error;

}						t_param;

typedef struct s_data {
	void		*img;
	char		*addr;
	void		*mlx;
	void		*mlx_win;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_param		*param;
	
}				t_data;

//////////////////////////////////// MAIN.C ////////////////////////////////////

int			main(int ac, char **av);
void		ft_handle_error(int error);


////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////// parsing ///////////////////////////////////
//////////////////////////////////// folder ////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

/////////////////////////////// PARSING_UTILS.C ////////////////////////////////

int			init_file(t_data *data, char *line);
int			parsing(t_data *data, char *av);
int			tab_check(int *tab);
void		init_tab(int *tab);
int			check_rt_file(char *av);

///////////////////////////////// PARSE_INIT.C /////////////////////////////////

int			Ambient_light_set(t_param *param, char **arg_tab);
int			rgb_convertor(char *str, char rgb);
void		free_tab(char **tab);
float		coor_convertor(char *str, char coor);
bool		check_str_int(char *str);
int			check_str_float(char *str);
bool		Camera_set(t_param *param, char **arg_tab);


// int			Light_set(t_light *light, char **arg_tab);
// int			plane_set(t_plane *plane, char **arg_tab);
// int			sphere_set(t_sphere *sphere, char **arg_tab);
// int			cylinder_set(t_cylinder *cylinder, char **arg_tab);

////////////////////////////////// FT_ATOD.C ///////////////////////////////////

double		ft_atod(char *str);

/////////////////////////////// GET_FUNCTION.C /////////////////////////////////

bool		get_vector(t_axis *axis, char *str);
bool		get_rgb(t_rgb *rgb);
bool		get_dimension(double *value, char *str);
bool		get_coor(t_axis *axis, char *str);


int	open_fd(int ac, char **av);
#endif