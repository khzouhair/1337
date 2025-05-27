/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khzouhai <khzouhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:16:42 by khzouhai          #+#    #+#             */
/*   Updated: 2025/03/24 11:59:35 by khzouhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color_pixel(t_fractal *fractal, int color)
{
	int	pixel_index;

	pixel_index = (fractal->y_pixel) * fractal->size_line + (fractal->x_pixel)
		* (fractal->bpp / 8);
	*(unsigned int *)(fractal->pointer_to_image + pixel_index) = color;
}

void	calculate_julia(t_fractal *fractal)
{
	double	i;
	double	temp;

	i = 0;
	fractal->z.x = fractal->x_pixel / fractal->zoom + fractal->offset.x;
	fractal->z.y = fractal->y_pixel / fractal->zoom + fractal->offset.y;
	while (++i < fractal->max_iterations)
	{
		temp = (fractal->z.x) * (fractal->z.x) - (fractal->z.y) * (fractal->z.y)
			+ fractal->c.x;
		fractal->z.y = 2 * (fractal->z.x) * (fractal->z.y) + fractal->c.y;
		fractal->z.x = temp;
		if (((fractal->z.x) * (fractal->z.x) + (fractal->z.y)
				* (fractal->z.y)) >= 4.0)
			break ;
	}
	if (i == fractal->max_iterations)
		color_pixel(fractal, 0x000000);
	else
		color_pixel(fractal, fractal->color * i * 10);
}

void	julia(t_graphics *graphics_data, t_fractal *fractal)
{
	fractal->x_pixel = 0;
	fractal->y_pixel = 0;
	while (fractal->x_pixel < SIZE)
	{
		while (fractal->y_pixel < SIZE)
		{
			calculate_julia(fractal);
			fractal->y_pixel++;
		}
		fractal->y_pixel = 0;
		fractal->x_pixel++;
	}
	mlx_put_image_to_window(graphics_data->mlx, graphics_data->win,
		graphics_data->img, 0, 0);
}

void	init_julia_param(t_fractal *fractal, t_graphics *graphics_data,
		char *v[])
{
	if (ft_strcmp(v[1], "julia") == 0)
	{
		if (!validate_fractal_param(v[2]) || !validate_fractal_param(v[3]))
			clean_exit(fractal, graphics_data, 1);
		fractal->c.x = ft_atof(v[2]);
		fractal->c.y = ft_atof(v[3]);
		if (fractal->c.x == INFINITY || fractal->c.x == -INFINITY
			|| fractal->c.y == INFINITY || fractal->c.y == -INFINITY)
		{
			write(2, "Error: Overflow.\n\n", 59);
			clean_exit(fractal, graphics_data, 1);
		}
		if ((fractal->c.x < -2.0 || fractal->c.x > 2.0) || (fractal->c.y < -2.0
				|| fractal->c.y > 2.0))
		{
			write(2,
				"Error: Julia set parameters must be in the range [-2,2].\n\n",
				59);
			clean_exit(fractal, graphics_data, 1);
		}
	}
}
