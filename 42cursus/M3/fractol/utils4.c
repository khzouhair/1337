/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khzouhai <khzouhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:04:32 by khzouhai          #+#    #+#             */
/*   Updated: 2025/03/24 13:26:07 by khzouhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	generate_random_c(void)
{
	return (((double)rand() / RAND_MAX) * 3.0 - 1.5);
}

void	set_julia(double *creal, double *cimaginary)
{
	*creal = generate_random_c();
	*cimaginary = generate_random_c();
}

void	change_iterations(t_fractal *fractal, int key_code)
{
	if (key_code == M)
	{
		if (fractal->max_iterations > 42)
			fractal->max_iterations -= 42;
	}
	else if (key_code == P)
	{
		if (fractal->max_iterations < 4200)
			fractal->max_iterations += 42;
	}
}

int	key_hook(int key_code, t_fractal_graphics *fg)
{
	if (key_code == ESC)
		exit(0);
	else if (key_code == LEFT)
		fg->fractal->offset.x += 42 / fg->fractal->zoom;
	else if (key_code == RIGHT)
		fg->fractal->offset.x -= 42 / fg->fractal->zoom;
	else if (key_code == UP)
		fg->fractal->offset.y += 42 / fg->fractal->zoom;
	else if (key_code == DOWN)
		fg->fractal->offset.y -= 42 / fg->fractal->zoom;
	else if (key_code == R)
		init_fractal(fg->fractal, fg->fractal->name);
	else if (key_code == C)
		fg->fractal->color += (255 * 255 * 255) / 100;
	else if (key_code == J)
		set_julia(&fg->fractal->c.x, &fg->fractal->c.y);
	else if (key_code == M || key_code == P)
		change_iterations(fg->fractal, key_code);
	select_fractal(fg->graphics_data, fg->fractal, fg->fractal->name);
	return (0);
}
