/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmuntada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 14:37:33 by qmuntada          #+#    #+#             */
/*   Updated: 2014/12/08 17:56:00 by qmuntada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list	*detailinfo(t_list *lst, char *path)
{
	struct stat		fstat;
	t_info			*info;
	t_list			*list;

	list = lst;
	info = malloc(sizeof(t_info));
	while (lst)
	{
		info = NULL;
		info = lst->content;
		stat(ft_strjoin(path, info->name), &fstat);
		info->st_mode = fstat.st_mode;
		info->st_nlink = fstat.st_nlink;
		info->st_uid = fstat.st_uid;
		info->st_gid = fstat.st_gid;
		info->st_mtimespec = fstat.st_mtimespec;
		info->st_size = fstat.st_size;
		info->st_blocks = fstat.st_blocks;
		lst->content = info;
		lst = lst->next;
	}
	return (list);
}

void	display_file(char *command, t_list *list)
{
	t_info	*info;
	if (!list)
		return ;
	if (one_of('l', command))
		ls_long(list, "\0", 0);
	else
		while (list)
		{
			info = list->content;
			ft_putstr(info->name);
			ft_putchar('\n');
			list = list->next;
		}
}

void	*truefile(t_list *list, char *command)
{
	DIR				*rep;
	struct stat		fstat;
	t_info			*info;
	t_list			*newlist;

	info = malloc(sizeof(t_info));
	while (list)
	{
		rep = opendir(list->content);
		if (!rep && errno == ENOTDIR)
		{
			stat(list->content, &fstat);
			info->name = ft_strdup(list->content);
			ft_lstpushback(&newlist, info, sizeof(info));
		}
		list = list->next;
	}
	sortfiles(command, &newlist, "\0");
	display_file(command, newlist);
}
