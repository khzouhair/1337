/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khzouhai <khzouhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:37:45 by khzouhai          #+#    #+#             */
/*   Updated: 2024/11/30 11:41:49 by khzouhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	ft_putnbr_base(unsigned long nbr, char *base)
{
	size_t	base_len;
	int		i;

	i = 0;
	base_len = ft_strlen(base);
	if (nbr >= 0)
	{
		if (nbr / base_len != 0)
			i += ft_putnbr_base(nbr / base_len, base);
		write(1, &base[nbr % base_len], 1);
		i++;
	}
	return (i);
}

static int	ft_putadress(unsigned long n)
{
	int	i;

	i = 0;
	i = ft_putstr("0x");
	i += ft_putnbr_base(n, "0123456789abcdef");
	return (i);
}

static void	ft_format(const char *format, va_list args, int *size)
{
	if (*format == 'd' || *format == 'i')
		*size += ft_putnbr(va_arg(args, int));
	else if (*format == 'c')
		*size += ft_putchar(va_arg(args, int));
	else if (*format == 's')
		*size += ft_putstr(va_arg(args, char *));
	else if (*format == 'x' || *format == 'X')
	{
		if (*format == 'x')
			*size += ft_putnbr_base(va_arg(args, unsigned int),
					"0123456789abcdef");
		else
			*size += ft_putnbr_base(va_arg(args, unsigned int),
					"0123456789ABCDEF");
	}
	else if (*format == 'u')
		*size += ft_putunsigned(va_arg(args, unsigned int));
	else if (*format == 'p')
		*size += ft_putadress((unsigned long)va_arg(args, void *));
	else if (*format == '%')
		*size += ft_putchar('%');
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		size;

	if (write(1, 0, 0) == -1)
		return (-1);
	va_start(args, format);
	size = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ft_format(format, args, &size);
		}
		else
			size += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (size);
}
