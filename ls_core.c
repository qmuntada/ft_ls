/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmuntada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/09 17:36:52 by qmuntada          #+#    #+#             */
/*   Updated: 2015/04/30 15:59:26 by qmuntada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	display_file(t_opt arg, t_elem *files, int fileordir)
{
	t_elem	*cur;

	cur = files;
	cur = sort_elem(cur, arg);
	(arg.l == 1 || arg.g == 1) ? \
			ls_long(arg, cur, fileordir) : ls_simple(arg, cur);
	arg._r == 1 ? recursion(arg, cur) : NULL;
}

void	do_ls_dir(t_opt arg, t_list *path, int multidir)
{
	t_list	*cur;
	t_elem	*files;
	t_elem	*dirlist;
	DIR *dir;
	int		first;

	cur = path;
	files = NULL;
	dirlist = NULL;
	first = 0;
	while (cur)
	{
		elemgetfiles(&dirlist, cur->content, "", arg);
		cur = cur->next;
	}
	dirlist = sort_elem(dirlist, arg);
	while (dirlist)
	{
		dir = opendir(dirlist->name);
		while (elemget(&files, readdir(dir), \
			ft_strjoin(dirlist->path, "/"), arg) != 0)
			;
		closedir(dir);
		if (files)
		{
			first == 1 ? ft_putchar('\n') : NULL;
			if (multidir)
			{
				ft_putstr(dirlist->name);
				ft_putstr(":\n");
			}
			first = 1;
			display_file(arg, files, 1);
		}
		files = NULL;
		dirlist = dirlist->next;
	}
}

void	do_ls_file(t_opt arg, t_list *path)
{
	t_list	*cur;
	t_elem	*files;

	cur = path;
	files = NULL;
	while (cur)
	{
		elemgetfiles(&files, cur->content, "", arg);
		cur = cur->next;
	}
	if (files)
		display_file(arg, files, 0);
}

void	core(t_opt arg, t_list *path, int multidir)
{
	DIR		*dir;
	t_list	*file;
	t_list	*directory;
	t_list	*cur;

	file = NULL;
	directory = NULL;
	cur = path;
	while (cur)
	{
		if ((dir = opendir(cur->content)) == NULL)
		{
			errno != ENOTDIR ? basicerror("ft_ls: ", cur->content, 0) : \
				ft_lstpushback(&file, cur->content, cur->content_size);
		}
		else
		{
			ft_lstpushback(&directory, cur->content, cur->content_size);
			if (closedir(dir) == -1)
				basicerror("ft_ls: ", cur->content, 0);
		}
		cur = cur->next;
	}
	file ? do_ls_file(arg, file) : NULL;
	file && directory ? ft_putchar('\n') : NULL;
	directory ? do_ls_dir(arg, directory, multidir) : NULL;
}
