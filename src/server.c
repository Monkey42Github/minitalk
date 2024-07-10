/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschemit <pschemit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:19:56 by pschemit          #+#    #+#             */
/*   Updated: 2022/05/09 17:58:27 by pschemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include "../minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n >= 10)
		ft_putnbr (n / 10);
	ft_putchar((n % 10) + '0');
}

void	ft_inter(int a, siginfo_t *pid, void *g)
{
	static unsigned char	octet = 0;
	static int				i = 0;

	(void)g;
	if (a == SIGUSR1)
		a = 1;
	else
		a = 0;
	octet |= a << i;
	if (i == 7)
	{
		if (octet == '\0')
		{
			usleep(30);
			kill(pid->si_pid, SIGUSR2);
		}
		else
			ft_putchar(octet);
		i = -1;
		octet = 0;
	}
	i++;
}

int	main(void)
{	
	sigset_t			sig;
	struct sigaction	sa;

	ft_putnbr(getpid());
	ft_putchar('\n');
	sigemptyset(&sig);
	sigaddset(&sig, SIGUSR1);
	sigaddset(&sig, SIGUSR2);
	sa.sa_sigaction = &ft_inter;
	sa.sa_mask = sig;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
