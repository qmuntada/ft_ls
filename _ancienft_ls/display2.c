/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display2.c                                         :+:      :+:    :+:   */

/*                                                    +:+ +:+         +:+     */
/*   By: qmuntada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 15:15:53 by qmuntada          #+#    #+#             */
/*   Updated: 2014/12/01 15:30:22 by qmuntada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

//b
//c
//d
//l
//s
//p
//-

void	display_usrgrp(t_info *info, int i)
{
	struct group	*grp;
	int				n;

	grp = getgrgid(info->st_gid);
	n = ft_strlen(grp->gr_name) - 1;
	while (++n < i)
		ft_putchar(' ');
	ft_putstr(grp->gr_name);
	ft_putstr("  ");
}

void	display_usrid(t_info *info, int i)
{
	struct passwd	*usr;
	int				n;

	usr = getpwuid(info->st_uid);
	n = ft_strlen(usr->pw_name) - 1;
	while (++n < i)
		ft_putchar(' ');
	ft_putstr(usr->pw_name);
	ft_putstr("  ");
}

void	display_nlink(t_info *info, int i)
{
	int				n;

	n = ft_strlen(ft_itoa(info->st_nlink)) - 1;
	while (++n < i)
		ft_putchar(' ');
	ft_putnbr(info->st_nlink);
	ft_putchar(' ');
}

void	display_permi(t_info *info)
{
	ft_putchar((S_ISFIFO(info->st_mode)) ? 'p' : '\0');
	ft_putchar((S_ISCHR(info->st_mode)) ? 'c' : '\0');
	ft_putchar((S_ISDIR(info->st_mode)) ? 'd' : '\0');
	ft_putchar((S_ISBLK(info->st_mode)) ? 'b' : '\0');
	ft_putchar((S_ISREG(info->st_mode)) ? '-' : '\0');
	ft_putchar((S_ISLNK(info->st_mode)) ? 'l' : '\0');
	ft_putchar((S_ISSOCK(info->st_mode)) ? 's' : '\0');
	ft_putchar((info->st_mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((info->st_mode & S_IWUSR) ? 'w' : '-');
	ft_putchar((info->st_mode & S_IXUSR) ? 'x' : '-');
	ft_putchar((info->st_mode & S_IRGRP) ? 'r' : '-');
	ft_putchar((info->st_mode & S_IWGRP) ? 'w' : '-');
	ft_putchar((info->st_mode & S_IXGRP) ? 'x' : '-');
	ft_putchar((info->st_mode & S_IROTH) ? 'r' : '-');
	ft_putchar((info->st_mode & S_IWOTH) ? 'w' : '-');
	ft_putchar((info->st_mode & S_IXOTH) ? 'x' : '-');
	ft_putstr("  ");
}
