/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khzouhai <khzouhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:11:28 by khzouhai          #+#    #+#             */
/*   Updated: 2024/11/30 11:42:28 by khzouhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_putchar(int c);
int		ft_putnbr(int n);
int		ft_putstr(char *str);
int		ft_putunsigned(unsigned int n);
int		ft_printf(const char *format, ...);
#endif
