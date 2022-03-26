/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leldiss <leldiss@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 12:17:23 by leldiss           #+#    #+#             */
/*   Updated: 2022/03/26 19:51:46 by leldiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putnbr(int n)
{
	int	c;

	if (n >= 10)
		ft_putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

static void	get_message(int sig, siginfo_t *info, void *context)
{
	static int	len;
	static int	byte;
	int			bit;

	(void)context;
	bit = (sig == SIGUSR1);
	byte = byte << 1;
	byte = bit + byte;
	if (++len == 7)
	{
		if (!byte)
		{
			write(1, "\n\n", 2);
			kill(info->si_pid, SIGUSR2);
		}
		write(1, &byte, 1);
		len = 0;
		byte = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	act;

	sigemptyset(&act.sa_mask);
	act.sa_sigaction = get_message;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	write(1, "\nPID: ", 6);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
