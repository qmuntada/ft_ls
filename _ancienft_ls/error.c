/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmuntada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 17:12:33 by qmuntada          #+#    #+#             */
/*   Updated: 2014/12/08 15:38:49 by qmuntada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//SORTIE D'ERREUR == 2 !!!
//PENSEZ A UTILISER LES PUT_FD !

#include "ft_ls.h"

void	error_readdir(char *path)
{
	ft_putstr_fd("ls: ", 2);
	perror(path);
}

void	error_arg(char c)
{
	ft_putstr_fd("ls: illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("usage: ls [-Ralrt1] ", 2);
	ft_putstr_fd("[file ...]\n", 2);
	exit(1);
}

void	error_incpath(char **no_file)
{
	DIR		*rep;
	int		i;

	i = -1;
	while (*(no_file + (++i)))
	{
		rep = opendir(*(no_file + i));
		if (errno != ENOTDIR)
		{
			ft_putstr_fd("ls: ", 2);
			perror(*(no_file + i));
		}
	}
}
