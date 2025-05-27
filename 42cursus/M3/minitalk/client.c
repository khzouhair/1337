/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khzouhai <khzouhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 08:46:48 by khzouhai          #+#    #+#             */
/*   Updated: 2025/03/14 21:02:27 by khzouhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int			g_flag = 0;

static void	send_signal(int pid, char caractere)
{
	int	i;
	int	result;

	i = 7;
	while (i >= 0)
	{
		if (1 & (caractere >> i))
			result = kill(pid, SIGUSR1);
		else
			result = kill(pid, SIGUSR2);
		if (result == -1)
		{
			write(2, "Kill failed", 11);
			exit(1);
		}
		while (g_flag == 0)
			usleep(800);
		g_flag = 0;
		i--;
	}
}

static void	confirm_signal(int sig)
{
	if (sig == SIGUSR1)
		g_flag = 1;
}

static int	is_nbr(char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (0);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9') && !(str[i] == 32 || (str[i] >= 9
					&& str[i] <= 13)))
			return (0);
		i++;
	}
	return (1);
}

static void	validate_pid_message(int pid, char *message, char *v1)
{
	if (is_nbr(v1) == 0)
	{
		write(2, "PID must be a positive integer.\n", 33);
		exit(1);
	}
	if (pid <= 0)
	{
		write(2, "PID must be a positive integer.\n", 33);
		exit(1);
	}
	if (message[0] == '\0')
	{
		write(2, "Message cannot be empty.\n", 25);
		exit(1);
	}
	if (kill(pid, 0) == -1)
	{
		write(2, "No process found with this PID.\n", 33);
		exit(1);
	}
}

int	main(int c, char *v[])
{
	int	i;
	int	pid;

	if (c != 3)
	{
		write(2, "Usage: ./client <pid> <message>\n", 33);
		return (1);
	}
	else
	{
		pid = ft_atoi(v[1]);
		validate_pid_message(pid, v[2], v[1]);
		signal(SIGUSR1, confirm_signal);
		i = 0;
		while (v[2][i] != '\0')
		{
			send_signal(pid, v[2][i]);
			i++;
		}
		send_signal(pid, '\0');
		send_signal(pid, '\n');
	}
	return (0);
}
