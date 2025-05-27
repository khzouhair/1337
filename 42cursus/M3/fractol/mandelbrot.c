/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khzouhai <khzouhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:16:21 by khzouhai          #+#    #+#             */
/*   Updated: 2025/03/23 16:43:44 by khzouhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color_pixel1(t_fractal *fractal, int color)
{
	int	pixel_index;

	pixel_index = (fractal->y_pixel) * fractal->size_line + (fractal->x_pixel)
		* (fractal->bpp / 8);
	*(unsigned int *)(fractal->pointer_to_image + pixel_index) = color;
}

void	calculate_mandelbrot(t_fractal *fractal)
{
	double	i;
	double	temp;

	i = 0;
	fractal->z.x = 0;
	fractal->z.y = 0;
	fractal->c.x = fractal->x_pixel / fractal->zoom + fractal->offset.x;
	fractal->c.y = fractal->y_pixel / fractal->zoom + fractal->offset.y;
	while (++i < fractal->max_iterations)
	{
		temp = (fractal->z.x) * (fractal->z.x) - (fractal->z.y) * (fractal->z.y)
			+ fractal->c.x;
		fractal->z.y = 2 * (fractal->z.x) * (fractal->z.y) + fractal->c.y;
		fractal->z.x = temp;
		if (((fractal->z.x) * (fractal->z.x) + (fractal->z.y)
				* (fractal->z.y)) > 4.0)
			break ;
	}
	if (i == fractal->max_iterations)
		color_pixel1(fractal, 0x000000);
	else
		color_pixel1(fractal, fractal->color * i * 10);
}

void	mandelbrot(t_graphics *graphics_data, t_fractal *fractal)
{
	fractal->x_pixel = 0;
	fractal->y_pixel = 0;
	while (fractal->x_pixel < SIZE)
	{
		fractal->y_pixel = 0;
		while (fractal->y_pixel < SIZE)
		{
			calculate_mandelbrot(fractal);
			fractal->y_pixel++;
		}
		fractal->x_pixel++;
	}
	mlx_put_image_to_window(graphics_data->mlx, graphics_data->win,
		graphics_data->img, 0, 0);
}
