/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmuntada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/09 17:37:11 by qmuntada          #+#    #+#             */
/*   Updated: 2015/04/30 15:59:11 by qmuntada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_size2(t_size *size, t_elem *cur)
{
	size->linkspace = (int)ft_strlen(ft_itoa(cur->st_nlink)) > \
		size->linkspace ? (int)ft_strlen(ft_itoa(cur->st_nlink)) \
		: size->linkspace;
	if (getpwuid(cur->st_uid))
		size->userspace = (int)ft_strlen(getpwuid(cur->st_uid)->pw_name) \
			> size->userspace ? (int)ft_strlen(getpwuid(cur->st_uid)->pw_name) \
			: size->userspace;
	else
		size->userspace = (int)ft_strlen(ft_itoa(cur->st_uid)) \
			> size->userspace ? (int)ft_strlen(ft_itoa(cur->st_uid)) \
			: size->userspace;
	if (getgrgid(cur->st_gid))
		size->groupspace = (int)ft_strlen(getgrgid(cur->st_gid)->gr_name) \
			> size->groupspace ? \
			(int)ft_strlen(getgrgid(cur->st_gid)->gr_name) : size->groupspace;
	else
		size->groupspace = (int)ft_strlen(ft_itoa(cur->st_gid)) \
			> size->groupspace ? (int)ft_strlen(ft_itoa(cur->st_gid)) \
			: size->groupspace;
	size->maj = (int)ft_strlen(ft_itoa(major(cur->st_rdev))) > size->maj \
		? (int)ft_strlen(ft_itoa(major(cur->st_rdev))) : size->maj;
	size->min = (int)ft_strlen(ft_itoa(minor(cur->st_rdev))) > size->min ? \
		(int)ft_strlen(ft_itoa(minor(cur->st_rdev))) : size->min;
	size->size = (int)ft_strlen(ft_itoa(cur->st_size)) > size->size ? \
		(int)ft_strlen(ft_itoa(cur->st_size)) : size->size;
	size->total += cur->st_blocks;
}

t_size	get_size(t_opt arg, t_elem *files)
{
	t_elem	*cur;
	t_size	size;

	size = (t_size){0, 0, 0, 0, 0, 0, 0};
	cur = files;
	while (cur)
	{
		if (!(arg.a == 0 && cur->name[0] == '.'))
			get_size2(&size, cur);
		cur = cur->next;
	}
	return (size);
}
