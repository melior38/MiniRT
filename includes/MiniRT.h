/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MiniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 08:52:07 by asouchet          #+#    #+#             */
/*   Updated: 2023/10/18 12:22:59 by asouchet         ###   ########.fr       */
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
# define RESET_COLOR			"\033[0m"
# define BLACK					"\033[0m\033[30m"
# define RED					"\033[0m\033[31m"
# define GREEN					"\033[0m\033[32m"
# define YELLOW					"\033[0m\033[33m"
# define BLUE					"\033[0m\033[34m"
# define MAGENTA				"\033[0m\033[35m"
# define CYAN					"\033[0m\033[36m"
# define WHITE					"\033[0m\033[37m"

typedef enum	e_obj_type
{
	SPHERE,
	CYLINDER,
	PLANE,
}				t_o_type;

typedef struct s_pos {
	double	x;
	double	y;
	double	z;
}				t_pos;

typedef struct s_rgb {
	int	r;
	int	g;
	int	b;
}				t_rgb;

typedef struct	s_ray
{
	t_pos	origin;
	t_pos	dir;
}				t_ray;

typedef struct s_matrix
{
	t_pos	a;
	t_pos	b;
	t_pos	c;
}				t_matrix;

typedef struct s_ref {
	t_pos	right;
	t_pos	up;
	t_pos	dir;
}				t_ref;

typedef struct s_alight
{
	double				ratio;
	t_rgb				rgb;
}				t_alight;

typedef struct s_camera
{
	double				fov;
	t_pos				coor;
	t_pos				vector;
	t_ref				ref;
	t_pos				up_left;
	t_pos				center;
	double				width;
	double				heigth;
}				t_camera;

typedef struct s_light
{
	double				bright;
	t_rgb				rgb;
	t_pos				coor;
}	t_light;

typedef struct s_plane
{
	t_pos				coor;
	t_pos				vector;
	t_rgb				rgb;
	struct s_plane		*next;
}	t_plane;

typedef struct s_sphere
{
	t_pos				coor;
	double				diam;
	t_rgb				rgb;
	struct s_sphere		*next;
}	t_sphere;

typedef struct s_cylinder
{
	t_pos				coor;
	t_pos				vector;
	double				diam;
	double				height;
	t_rgb				rgb;
	struct s_cylinder	*next;
}	t_cylinder;

typedef struct s_param
{
	t_alight		*alight;
	t_camera		*camera;
	t_light			*light;
	t_plane			*plane;
	t_plane			*pl_choosed;
	t_sphere		*sphere;
	t_sphere		*sp_choosed;
	t_cylinder		*cylinder;
	t_cylinder		*cy_choosed;
	t_pos			corner;
	double			hx;
	double			hy;
	int				miss;
	t_ref	ref;
	t_matrix		dir;
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
void		cyl_addb(t_cylinder **lst, t_cylinder *new, t_cylinder *cy_choosed);
void		sp_addb(t_sphere **lst, t_sphere *new, t_sphere *sp_choosed);
void		pl_addb(t_plane **lst, t_plane*new, t_plane *pl_choosed);

/////////////////////////////////// FREE.C /////////////////////////////////////
int free_struct(t_data *data);

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
t_rgb		rgb_converter(t_data *data, char *str);
t_pos		ft_coor(char *str, t_data *data);
t_pos		ft_vector(t_data *data, char *str);

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

///////////////////////////////// PARSING.C ////////////////////////////////////

int			open_fd(t_data *data, int ac, char *av);
void		print_error(t_data	*data, char *msg);


////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////// projection /////////////////////////////////
//////////////////////////////////// folder ////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////// VEC_UTILS.C /////////////////////////////////

double		vec_norm(t_pos vec);
void		normed_vec(t_pos *vec);
t_pos		cross_product(t_pos vec1, t_pos vec2);
t_pos		add_vec(t_pos vec1, t_pos vec2);
t_pos		subs_vec(t_pos vec1, t_pos vec2);
t_pos		scale_vec(t_pos vec, double scaling);
t_pos		create_vec(double x, double y, double z);
double	    dot_product(t_pos vec1, t_pos vec2);

//////////////////////////////// VEC_OPERATION.C ///////////////////////////////

int			pixel_color_sphere(t_ray ray, t_sphere *sphere, t_alight *A);
int			pixel_color_cylinder(t_ray ray, t_cylinder *cylinder, t_alight *A);
int			pixel_color_plane(t_ray ray, t_plane *plane, t_alight *A);
void		init_ray(t_data *data, int x, int y, t_ray *res);
// t_pos		get_matrix(t_param *param, int x, int y);
t_ref		set_ref(t_pos cam_ve);
// void		init_matrix(t_ref *ref, t_matrix *m);
// t_pos		matrix_vector_multi(t_pos dir, t_matrix m);

///////////////////////////////// INTERSECTION.C ////////////////////////////////

void		swap_doubles(double *a, double *b);
int			intersect_sphere(t_ray ray, t_sphere *sphere, double *t);
t_pos		get_sphere_normal(t_pos point, t_sphere *sphere);
int			get_roots(double *t0, double *t1, t_ray ray, t_sphere *sphere);
int			intersect_plane(t_ray ray, t_plane *plane, double *t);
// int			intersect_sphere(t_ray ray, t_sphere *sphere);

///////////////////////////////// QUADRATIC.C ///////////////////////////////////

int			solve_quadratic(t_pos params, double *x0, double *x1);

//////////////////////////////// INIT_CAMERA.C //////////////////////////////////

void		init_camera(t_camera *camera);

///////////////////////////////// CYLINDER.C ////////////////////////////////////

t_pos		get_cylinder_normal(t_pos point, t_cylinder *cylinder);
void		check_t(double *t, t_cylinder *cylinder, t_ray ray);
int			cyl_get_roots(double *t0, double *t1, t_cylinder *cylinder, t_ray ray);
int			intersect_cylinder(t_ray ray, t_cylinder *cylinder, double *t);

///////////////////////////////// INTERSECT_ALL.C ///////////////////////////////
t_cylinder	*loop_cylinder(t_param *param, t_ray ray, double *t);
t_sphere	*loop_sphere(t_param *param, t_ray ray, double *t);
t_plane		*loop_plane(t_param *param, t_ray ray, double *t);
t_o_type	intersect_with_all(t_param *param, t_ray ray, double *t);


#endif