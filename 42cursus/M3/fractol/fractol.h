/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khzouhai <khzouhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:15:44 by khzouhai          #+#    #+#             */
/*   Updated: 2025/03/24 12:47:15 by khzouhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./include/minilibx/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

# define SIZE 1000
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define R 15
# define C 8
# define H 4
# define J 38
# define P 35
# define M 46

typedef struct s_nbrcomplex
{
	double			x;
	double			y;
}					t_nbrcomplex;

typedef struct s_graphics
{
	void			*mlx;
	void			*win;
	void			*img;
}					t_graphics;

typedef struct s_fractal
{
	char			*pointer_to_image;
	char			*name;
	int				bpp;
	int				size_line;
	int				endian;
	int				x_pixel;
	int				y_pixel;
	int				color;
	int				max_iterations;
	t_nbrcomplex	z;
	t_nbrcomplex	c;
	t_nbrcomplex	offset;
	double			zoom;
}					t_fractal;

typedef struct s_fractal_graphics
{
	t_fractal		*fractal;
	t_graphics		*graphics_data;
}					t_fractal_graphics;

void				mandelbrot(t_graphics *graphics_data, t_fractal *fractal);
void				julia(t_graphics *graphics_data, t_fractal *fractal);
void				init_julia_param(t_fractal *fractal,
						t_graphics *graphics_data, char *v[]);
void				init_fractal(t_fractal *fractal, char *name);
void				init_mlx(t_fractal *fractal, t_graphics *graphics_data,
						char *name);
void				select_fractal(t_graphics *graphics_data,
						t_fractal *fractal, char *set);
void				clean_exit(t_fractal *fractal, t_graphics *graphics_data,
						int n);
double				ft_atof(const char *str);
int					validate_fractal_param(char *str);
void				zoom(t_fractal *fractal, int x, int y, int zoom);
int					handle_mouse_zoom(int mouse_code, int x, int y,
						t_fractal_graphics *fg);
int					close_window(t_fractal_graphics *fg);
int					ft_strcmp(char *s1, char *s2);
char				*ft_strcpy(char *dest, char *src);
int					ft_strlen(char *str);
int					key_hook(int key_code, t_fractal_graphics *fg);
void				free_all(t_fractal *fractal, t_graphics *graphics_data);
void				print_error_message(void);

#endif