/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khzouhai <khzouhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 08:46:59 by khzouhai          #+#    #+#             */
/*   Updated: 2025/03/14 08:27:47 by khzouhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	receive_message(int signal, siginfo_t *info, void *context)
{
	static unsigned char	current_char;
	static int				i;
	static int				pid;

	(void)context;
	if (!pid || pid != info->si_pid)
	{
		pid = info->si_pid;
		current_char = 0;
		i = 0;
	}
	if (signal == SIGUSR1)
		current_char |= (1 << (7 - i));
	i++;
	if (i == 8)
	{
		write(1, &current_char, 1);
		i = 0;
		current_char = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = receive_message;
	sigemptyset(&sa.sa_mask);
	pid = getpid();
	ft_putnbr(pid);
	write(1, "\n", 1);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
