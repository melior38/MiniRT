/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MiniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 08:52:07 by asouchet          #+#    #+#             */
/*   Updated: 2023/09/19 16:58:03 by asouchet         ###   ########.fr       */
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

typedef struct s_object
{
	int					type; // je dirai plutot un int type avec des define c plus lisible qu'un id en char 
	double				b_ratio;
	int					fov;
	double 				diameter;
	double				height;
	t_axis				*center_coor;
	t_axis 				*vector; //A changer ? ui 8->
	t_rgb				*rgb;
	struct t_object		*next;
}	t_object;

typedef struct s_param {
	t_object			*list;
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

bool		init_file(t_data *data, char *line);
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

////////////////////////////////// FT_PARSING.C/////////////////////////////////
int			open_fd(int ac, char *av);

#endif