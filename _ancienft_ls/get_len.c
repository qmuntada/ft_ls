/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmuntada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 15:52:33 by qmuntada          #+#    #+#             */
/*   Updated: 2014/12/08 17:42:19 by qmuntada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		get_lenlink(t_list *list)
{
	int				n;
	t_info			*info;
	t_list			*lst;

	n = 0;
	lst = list;
	info = malloc(sizeof(t_info));
	while (lst)
	{
		info = lst->content;
		if (ft_strlen(ft_itoa(info->st_nlink)) > n)
			n = ft_strlen(ft_itoa(info->st_nlink));
		lst = lst->next;
	}
	return (n);
}

int		get_lenusrid(t_list *list)
{
	int				n;
	t_info			*info;
	struct passwd	*usr;
	t_list			*lst;

	n = 0;
	lst = list;
	info = malloc(sizeof(t_info));
	while (lst)
	{
		info = lst->content;
		usr = getpwuid(info->st_uid);
		if (ft_strlen((usr->pw_name)) > n)
			n = ft_strlen(usr->pw_name);
		lst = lst->next;
	}
	return (n);
}

int		get_lenusrgrp(t_list *list)
{
	t_info			*info;
	int				n;
	struct group	*grp;
	t_list			*lst;

	n = 0;
	lst = list;
	info = malloc(sizeof(t_info));
	while (lst)
	{
		info = lst->content;
		grp = getgrgid(info->st_gid);
		if (ft_strlen((grp->gr_name)) > n)
			n = ft_strlen(grp->gr_name);
		lst = lst->next;
	}
	return (n);
}

int		get_lensize(t_list *list)
{
	int				n;
	t_info			*info;
	t_list			*lst;

	n = 0;
	lst = list;
	info = malloc(sizeof(t_info));
	while (lst)
	{
		info = lst->content;
		if (ft_strlen(ft_itoa(info->st_size)) > n)
			n = ft_strlen(ft_itoa(info->st_size));
		lst = lst->next;
	}
	return (n);
}
