/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khzouhai <khzouhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:15:28 by khzouhai          #+#    #+#             */
/*   Updated: 2025/03/23 13:12:16 by khzouhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(t_fractal *fractal, int x, int y, int zoom)
{
	double	zoom_level;

	zoom_level = 1.42;
	if (zoom == 1)
	{
		fractal->offset.x = (x / fractal->zoom + fractal->offset.x) - (x
				/ (fractal->zoom * zoom_level));
		fractal->offset.y = (y / fractal->zoom + fractal->offset.y) - (y
				/ (fractal->zoom * zoom_level));
		fractal->zoom *= zoom_level;
	}
	else if (zoom == -1)
	{
		fractal->offset.x = (x / fractal->zoom + fractal->offset.x) - (x
				/ (fractal->zoom / zoom_level));
		fractal->offset.y = (y / fractal->zoom + fractal->offset.y) - (y
				/ (fractal->zoom / zoom_level));
		fractal->zoom /= zoom_level;
	}
	else
		return ;
}

int	handle_mouse_zoom(int mouse_code, int x, int y, t_fractal_graphics *fg)
{
	if (mouse_code == SCROLL_UP)
		zoom(fg->fractal, x, y, 1);
	else if (mouse_code == SCROLL_DOWN)
		zoom(fg->fractal, x, y, -1);
	select_fractal(fg->graphics_data, fg->fractal, fg->fractal->name);
	return (0);
}

int	close_window(t_fractal_graphics *fg)
{
	mlx_destroy_image(fg->graphics_data->mlx, fg->graphics_data->img);
	mlx_destroy_window(fg->graphics_data->mlx, fg->graphics_data->win);
	free(fg->graphics_data);
	free(fg->fractal->name);
	free(fg->fractal);
	exit(0);
}
