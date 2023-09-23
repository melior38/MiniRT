/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MiniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 08:52:07 by asouchet          #+#    #+#             */
/*   Updated: 2023/09/23 15:11:33 by asouchet         ###   ########.fr       */
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
# define HEIGTH	768.0
# define WIDTH 1366.0
# define AMBIENT_LIGHT 1
# define CAMERA 2
# define LIGHT 3
# define PLAN 4
# define SPHERE 5
# define CYLINDER 6

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

typedef struct s_alight
{
	double				ratio;
	t_rgb				*rgb;
}	t_alight;

typedef struct s_camera
{
	int					fov;
	t_axis				*coor;
	t_axis				*vector;
}	t_camera;

typedef struct s_light
{
	double				bright;
	t_rgb				*rgb;
	t_axis				*coor;
}	t_light;

typedef struct s_plane
{
	t_axis				*coor;
	t_axis				*vector;
	t_rgb				*rgb;
	struct t_plane		*next;
}	t_plane;

typedef struct s_sphere
{
	t_axis				*coor;
	double				diam;
	t_rgb				*rgb;
	struct t_sphere		*next;
}	t_sphere;

typedef struct s_cylinder
{
	t_axis				*coor;
	t_axis				*vector;
	double				diam;
	double				height;
	t_rgb				*rgb;
	struct t_cylinder	*next;
}	t_cylinder;

typedef struct s_param
{
	t_alight			*alight;
	t_camera			*camera;
	t_light				*light;
	t_plane				*plane;
	t_sphere			*sphere;
	t_cylinder			*cylinder;
}						t_param;

typedef struct s_data {
	void		*img;
	char		*addr;
	void		*mlx;
	void		*mlx_win;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			error;
	t_param		*param;
}				t_data;

//////////////////////////////////// MAIN.C ////////////////////////////////////

int			main(int ac, char **av);
void		ft_handle_error(int error);

//////////////////////////////// OBJ_UTILS.C ///////////////////////////////////
t_alight	*create_alight(t_data *data, char **args);

////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////// parsing ///////////////////////////////////
//////////////////////////////////// folder ////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

/////////////////////////////// PARSING_UTILS.C ////////////////////////////////

void		init_file(t_data *data, char *line);
int			parsing(t_data *data, int ac, char *av);
int			tab_check(int *tab);
void		init_tab(int *tab);
int			check_rt_file(char *av);

///////////////////////////////// PARSE_INIT.C /////////////////////////////////

bool		Ambient_light_set(t_param *param, char **arg_tab);
int			rgb_convertor(char *str, char rgb);
void		free_tab(char **tab);
float		coor_convertor(char *str, char coor);
bool		check_str_int(char *str);
bool		check_str_float(char *str);
bool		Camera_set(t_object *list, char **arg_tab);
bool		Light_set(t_object *list, char **arg_tab);
bool		plane_set(t_object *list, char **arg_tab);
bool		sphere_set(t_object *list, char **arg_tab);
bool		cylinder_set(t_object *list, char **arg_tab);

////////////////////////////////// FT_ATOD.C ///////////////////////////////////

double		ft_atod(char *str);

/////////////////////////////// GET_FUNCTION.C /////////////////////////////////

bool		get_vector(t_axis *axis, char *str);
bool		get_rgb(t_rgb *rgb, char *str);
bool		get_dimension(double *value, char *str);
bool		get_coor(t_axis *axis, char *str);
bool		get_ratio(double *ratio, char *str);

///////////////////////////////// PARSING.C ////////////////////////////////////
int			open_fd(int ac, char *av);
int			print_error(char *msg, int code);


////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////// projection /////////////////////////////////
//////////////////////////////////// folder ////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////// VEC_UTILS.C /////////////////////////////////

double		vec_norm(t_vec vec);
void		normed_vec(t_vec *vec);
t_axis		cross_product(t_axis vec1, t_axis vec2);
t_axis		add_vec(t_axis vec1, t_axis vec2);
t_axis		subs_vec(t_axis vec1, t_axis vec2);
t_axis		scale_vec(t_axis vec, double scaling);

//////////////////////////////// VEC_OPERATION.C ////////////////////////////////



////////////////////////////////// RGB_UTILS.C//////////////////////////////////
t_rgb		*rgb_converter(t_data *data, char *str);

#endif