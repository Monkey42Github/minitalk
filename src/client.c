/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschemit <pschemit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:19:28 by pschemit          #+#    #+#             */
/*   Updated: 2022/05/09 17:58:24 by pschemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	g_pid;

int	ft_atoi(const char *str)
{
	int	nbr;
	int	sign;

	nbr = 0;
	sign = 1;
	while ((*str == ' ') || (*str >= '\t' && *str <= '\r') || (*str == '0'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nbr = 10 * nbr + (*str - '0');
		str++;
	}
	return (nbr * sign);
}

void	ft_texte(char *c, int pid)
{
	int	i;

	i = 0;
	while (c[i] != '\0')
	{
		ft_char(c[i], pid);
		i++;
	}
	i = 0;
	while (i != 8)
	{
		kill(pid, SIGUSR2);
		i++;
		usleep(500);
	}
}

void	ft_char(char c, int pid)
{
	int	i;

	i = 0;
	while (i != 8)
	{
		if (c & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		i++;
	}
}

void	ft_recu(int sig)
{
	if (sig == SIGUSR2)
	{
		write(1, "message-reçu\n", 13);
		exit(0);
	}
}

int	main(int ac, char **av)
{
	struct sigaction	sa;

	sa.sa_handler = ft_recu;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	if (ac == 3)
	{
		g_pid = ft_atoi(av[1]);
		ft_texte(av[2], g_pid);
		exit(0);
	}
	else
		return (write(1, "Erreur\n", 7));
	return (0);
}
