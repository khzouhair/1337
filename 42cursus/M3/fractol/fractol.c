/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khzouhai <khzouhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:17:01 by khzouhai          #+#    #+#             */
/*   Updated: 2025/03/24 13:28:39 by khzouhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	validate_fractal_param(char *str)
{
	int	i;
	int	temp;

	if (str == NULL)
		return (0);
	(1) && (i = 0, temp = 0);
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (0);
	while (str[i])
	{
		if (str[i] == '.')
			temp++;
		if (!(str[i] >= '0' && str[i] <= '9') && str[i] != '.' && !(str[i] == 32
				|| (str[i] >= 9 && str[i] <= 13)))
			return (0);
		i++;
	}
	if (temp > 1)
		return (0);
	return (1);
}

void	free_all(t_fractal *fractal, t_graphics *graphics_data)
{
	if (fractal->name != NULL)
		free(fractal->name);
	if (fractal != NULL)
		free(fractal);
	if (graphics_data != NULL)
		free(graphics_data);
	exit(1);
}

void	run_fractal(t_fractal *fractal, t_graphics *graphics_data,
		t_fractal_graphics *fg)
{
	init_mlx(fractal, graphics_data, fractal->name);
	init_fractal(fractal, fractal->name);
	select_fractal(graphics_data, fractal, fractal->name);
	mlx_mouse_hook(graphics_data->win, handle_mouse_zoom, fg);
	mlx_hook(graphics_data->win, 17, 0L, close_window, fg);
	mlx_key_hook(graphics_data->win, key_hook, fg);
	mlx_loop(graphics_data->mlx);
}

void	check_param(int c, char *v[], t_fractal *fractal,
		t_graphics *graphics_data)
{
	if (c == 3 || c > 4 || c < 2 || c == 1)
		clean_exit(fractal, graphics_data, 1);
	if (ft_strcmp(v[1], "mandelbrot") != 0 && ft_strcmp(v[1], "julia") != 0)
		clean_exit(fractal, graphics_data, 1);
	if ((c != 4 && ft_strcmp(v[1], "julia") == 0) || (ft_strcmp(v[1],
				"mandelbrot") == 0 && c != 2))
		clean_exit(fractal, graphics_data, 1);
}

int	main(int c, char *v[])
{
	t_graphics			*graphics_data;
	t_fractal			*fractal;
	t_fractal_graphics	fg;

	if (c >= 2)
	{
		(1) && (graphics_data = malloc(sizeof(t_graphics)),
			fractal = malloc(sizeof(t_fractal)),
			fractal->name = malloc(ft_strlen(v[1]) + 1));
		if (!graphics_data || !fractal || !fractal->name)
		{
			write(2, "Error: Memory allocation failed.\n", 33);
			free_all(fractal, graphics_data);
		}
		ft_strcpy(fractal->name, v[1]);
		fg.fractal = fractal;
		fg.graphics_data = graphics_data;
		check_param(c, v, fractal, graphics_data);
		if (c == 4)
			init_julia_param(fractal, graphics_data, v);
		run_fractal(fractal, graphics_data, &fg);
		free_all(fractal, graphics_data);
	}
	print_error_message();
	return (0);
}
