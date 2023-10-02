/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MiniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 08:52:07 by asouchet          #+#    #+#             */
/*   Updated: 2023/10/02 08:39:27 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "libft.h"
# include <math.h>
# include <mlx.h>
# include <stdbool.h>

# define HEIGTH		720.0
# define WIDTH		1280.0
# define ERROR		0
# define SUCCESS	1
# define AMBIENT_LIGHT 1
# define CAMERA 2
# define LIGHT 3
# define PLAN 4
# define SPHERE 5
# define CYLINDER 6
# define RESET_COLOR			"\033[0m"
# define BLACK					"\033[0m\033[30m"
# define RED					"\033[0m\033[31m"
# define GREEN					"\033[0m\033[32m"
# define YELLOW					"\033[0m\033[33m"
# define BLUE					"\033[0m\033[34m"
# define MAGENTA				"\033[0m\033[35m"
# define CYAN					"\033[0m\033[36m"
# define WHITE					"\033[0m\033[37m"

typedef struct s_axis {
	double	x;
	double	y;
	double	z;
}				t_axis;

typedef struct s_rgb {
	int	r;
	int	g;
	int	b;

}				t_rgb;


typedef struct s_vec_dir
{
	t_axis	qx;
	t_axis	qy;
}				t_vec_dir;

typedef struct s_referential {
	t_axis	x;
	t_axis	y;
	t_axis	z;
}				t_referential;

typedef struct s_alight
{
	double				ratio;
	t_rgb				*rgb;
}				t_alight;

typedef struct s_camera
{
	double				fov;
	t_axis				*coor;
	t_axis				*vector;
}				t_camera;

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
	struct s_plane		*next;
}	t_plane;

typedef struct s_sphere
{
	t_axis				*coor;
	double				diam;
	t_rgb				*rgb;
	struct s_sphere		*next;
}	t_sphere;

typedef struct s_cylinder
{
	t_axis				*coor;
	t_axis				*vector;
	double				diam;
	double				height;
	t_rgb				*rgb;
	struct s_cylinder	*next;
}	t_cylinder;

typedef struct s_param
{
	t_alight		*alight;
	t_camera		*camera;
	t_light			*light;
	t_plane			*plane;
	t_sphere		*sphere;
	t_cylinder		*cylinder;
	double			hx;
	double			hy;
	t_referential	ref;
	t_vec_dir		vec;
}				t_param;

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
int			my_mlx_get_color_value(int red, int green, int blue);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);

////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////// utils /////////////////////////////////////
//////////////////////////////////// folder ////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

///////////////////////////////// ADD_BACK.C ///////////////////////////////////
void		cyl_addb(t_cylinder **lst, t_cylinder *new);
void		sp_addb(t_sphere **lst, t_sphere *new);
void		pl_addb(t_plane **lst, t_plane*new);

/////////////////////////////////// FREE.C /////////////////////////////////////
void		free_struct(t_data *data);

///////////////////////////////// FREE_OBJ.C ///////////////////////////////////
void		free_cylinder(t_param *param);
void		free_plane(t_param *param);
void		free_sphere(t_param *param);

///////////////////////////////// FREE_UOBJ.C //////////////////////////////////
void		free_camera(t_camera *camera);
void		free_light(t_light *light);


/////////////////////////////////// SHOW.C /////////////////////////////////////
void		show_alight(t_data *data);
void		show_camera(t_data *data);
void		show_light(t_data *data);
void		show_plane(t_data *data);
void		show_sphere(t_data *data);
void		show_cylinder(t_data *data);



/////////////////////////////////// SHOW.C /////////////////////////////////////
//////////////////////////////// OBJ_UTILS.C ///////////////////////////////////
t_plane		*create_plane(t_data *data, char **args);
t_sphere	*create_sphere(t_data *data, char **args);
t_cylinder	*create_cylinder(t_data *data, char **args);

/////////////////////////////// UOBJ_UTILS.C ///////////////////////////////////
t_alight	*create_alight(t_data *data, char **args);
t_camera	*create_camera(t_data *data, char **args);
t_light		*create_light(t_data *data, char **args);

////////////////////////////////// RGB_UTILS.C//////////////////////////////////
t_rgb		*rgb_converter(t_data *data, char *str);
t_axis		*ft_coor(char *str, t_data *data);
t_axis		*ft_vector(t_data *data, char *str);

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

void		free_tab(char **tab);

////////////////////////////////// FT_ATOD.C ///////////////////////////////////
double		ft_atod(char *str, t_data *data);

/////////////////////////////// GET_FUNCTION.C /////////////////////////////////

// bool		get_vector(t_axis *axis, char *str);
// bool		get_rgb(t_rgb *rgb, char *str);
// bool		get_dimension(double *value, char *str);
// bool		get_coor(t_axis *axis, char *str);
// bool		get_ratio(double *ratio, char *str);

///////////////////////////////// PARSING.C ////////////////////////////////////
int			open_fd(int ac, char *av);
void		print_error(t_data	*data, char *msg, int code);

////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////// projection /////////////////////////////////
//////////////////////////////////// folder ////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////// VEC_UTILS.C /////////////////////////////////

double		vec_norm(t_axis vec);
void		normed_vec(t_axis *vec);
t_axis		cross_product(t_axis vec1, t_axis vec2);
t_axis		add_vec(t_axis vec1, t_axis vec2);
t_axis		subs_vec(t_axis vec1, t_axis vec2);
t_axis		scale_vec(t_axis vec, double scaling);

//////////////////////////////// VEC_OPERATION.C ///////////////////////////////
void		little_main_for_pixel(t_data *data, int x, int y);
int			shifting_pixel(t_param *param, int x, int y,
				t_referential ref);
void		get_win_scale(t_param *param, double fov);
t_referential	set_referential(t_axis *cam_ve);

#endif