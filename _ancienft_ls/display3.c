/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmuntada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 16:41:23 by qmuntada          #+#    #+#             */
/*   Updated: 2014/12/08 17:02:53 by qmuntada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	display_size(t_info *info, int i)
{
	int		n;

	n = ft_strlen(ft_itoa(info->st_size)) - 1;
	while (++n < i)
		ft_putchar(' ');
	ft_putnbr(info->st_size);
	ft_putchar(' ');
}

void	display_date(t_info *info)
{
	time_t				actualtime;
	char				*str;
	char				*str2;
	struct timespec		t;

	t = info->st_mtimespec;
	actualtime = time(0);
	str = ctime(&t.tv_sec);
	if ((actualtime - 15778463) > t.tv_sec || actualtime < t.tv_sec)
	{
		str2 = malloc(sizeof(char) * 6);
		str2 = ft_strsub(str, 20, 4);
		str = ft_strsub(str, 4, 6);
		str = ft_strjoin(str, "  ");
		str = ft_strjoin(str, str2);
		free(str2);
	}
	else
		str = ft_strsub(str, 4, 12);
	ft_putstr(str);
	ft_putchar(' ');
}
