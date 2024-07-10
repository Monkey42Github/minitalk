/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschemit <pschemit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:19:12 by pschemit          #+#    #+#             */
/*   Updated: 2022/04/16 14:16:02 by pschemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <signal.h>

void	ft_putnbr(int n);
void	ft_putchar(char c);
void	ft_inter(int a, siginfo_t *pid, void *g);
void	ft_char(char c, int pid);
void	ft_texte(char *c, int pid);
int		ft_atoi(const char *str);

#endif