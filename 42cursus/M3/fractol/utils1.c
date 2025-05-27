/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khzouhai <khzouhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:15:16 by khzouhai          #+#    #+#             */
/*   Updated: 2025/03/24 12:01:07 by khzouhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractal(t_fractal *fractal, char *name)
{
	fractal->x_pixel = 0;
	fractal->y_pixel = 0;
	fractal->zoom = 300;
	fractal->color = 1;
	if (ft_strcmp(name, "mandelbrot") == 0)
	{
		fractal->offset.x = -2.10;
		fractal->offset.y = -1.50;
	}
	else if (ft_strcmp(name, "julia") == 0)
	{
		fractal->offset.x = -1.60;
		fractal->offset.y = -1.50;
	}
	fractal->max_iterations = 42;
}

void	init_mlx(t_fractal *fractal, t_graphics *graphics_data, char *name)
{
	graphics_data->mlx = mlx_init();
	if (!graphics_data->mlx)
		clean_exit(fractal, graphics_data, 0);
	graphics_data->win = mlx_new_window(graphics_data->mlx, SIZE, SIZE, name);
	if (!graphics_data->win)
		clean_exit(fractal, graphics_data, 0);
	graphics_data->img = mlx_new_image(graphics_data->mlx, SIZE, SIZE);
	if (!graphics_data->img)
		clean_exit(fractal, graphics_data, 0);
	fractal->pointer_to_image = mlx_get_data_addr(graphics_data->img,
			&fractal->bpp, &fractal->size_line, &fractal->endian);
	if (!fractal->pointer_to_image)
		clean_exit(fractal, graphics_data, 0);
}

void	select_fractal(t_graphics *graphics_data, t_fractal *fractal, char *set)
{
	if (ft_strcmp(set, "mandelbrot") == 0)
		mandelbrot(graphics_data, fractal);
	else if (ft_strcmp(set, "julia") == 0)
		julia(graphics_data, fractal);
}

void	print_error_message(void)
{
	write(2, "Please choose a fractal: mandelbrot or julia.\n", 46);
	write(2, "You can specify an additional parameter  for the Julia set.\n",
		60);
	write(2, "----------------------------Example------------------------\n",
		60);
	write(2, "./fractol juilia <real part> <imaginary part>\n", 46);
	write(2, "./fractol mandelbrot\n", 21);
}

void	clean_exit(t_fractal *fractal, t_graphics *graphics_data, int n)
{
	if (n == 0)
		write(2, "MLX Initialization Error: Failed to initialize graphics.\n",
			56);
	else if (n == 1)
	{
		write(2, "Please choose a fractal: mandelbrot or julia.\n", 46);
		write(2,
			"You can specify an additional parameter  for the Julia set.\n",
			60);
		write(2,
			"----------------------------Example------------------------\n",
			60);
		write(2, "./fractol juilia <real part> <imaginary part>\n", 46);
		write(2, "./fractol mandelbrot\n", 21);
	}
	free_all(fractal, graphics_data);
}
