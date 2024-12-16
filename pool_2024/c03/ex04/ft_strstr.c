/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khzouhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 18:56:22 by khzouhai          #+#    #+#             */
/*   Updated: 2024/07/05 10:28:33 by khzouhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	t;

	if (*to_find == '\0')
		return (str);
	while (*str)
	{
		if (*str == *to_find)
		{
			i = 0;
			t = 0;
			while (to_find[i] != '\0')
			{
				if (to_find[i] != str[i])
					t = 1;
				i++;
			}
			if (t == 0)
				return (str);
		}
		str++;
	}
	return (0);
}
