/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MiniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 08:52:07 by asouchet          #+#    #+#             */
/*   Updated: 2023/09/21 10:37:59 by asouchet         ###   ########.fr       */
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

// en attendant de la rajouter dans nos structs
typedef struct s_vec {
	double	x;
	double	y;
	double	z;
}				t_vec;

typedef struct s_object
{
	int					type;
	double				b_ratio;
	int					fov;
	double 				bright;
	double 				diameter;
	double				height;
	t_axis				*center_coor;
	t_axis 				*vector;
	t_rgb				*rgb;
	struct t_object		*next;
}	t_object;

typedef struct s_param {
	t_object			*list;

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
	t_object 	*obj;
	t_param		*param;
	
}				t_data;

//////////////////////////////////// MAIN.C ////////////////////////////////////

int			main(int ac, char **av);
void		ft_handle_error(int error);

//////////////////////////////// OBJ_UTILS.C ///////////////////////////////////

t_object	*create_alight(double ratio, t_rgb *rgb);
t_object	*create_camera(t_axis *coor, t_axis *vector, int fov);
t_object	*create_light(t_axis *coor, double bright, t_rgb *rgb);
t_object	*create_plane(t_axis *coor, t_axis *vector, t_rgb *rgb);
t_object	*create_sphere(t_axis *coor, double diam, t_rgb *rgb);
t_object	*create_cylinder(t_axis *coor, t_axis *vector, double diam,
				double height, t_rgb *rgb);
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
t_vec		cross_product(t_vec vec1, t_vec vec2);
t_vec		add_vec(t_vec vec1, t_vec vec2);
t_vec		subs_vec(t_vec vec1, t_vec vec2);
t_vec		scale_vec(t_vec vec, double scaling);

//////////////////////////////// VEC_OPERATION.C ////////////////////////////////



#endif