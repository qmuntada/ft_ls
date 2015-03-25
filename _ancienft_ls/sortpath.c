/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortpath.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmuntada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 17:21:23 by qmuntada          #+#    #+#             */
/*   Updated: 2014/12/08 17:14:45 by qmuntada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	**sort_lst(t_list *lst)
{
	int		len;
	int		i;
	char	**no_file;

	i = -1;
	len = ft_lstlen(lst);
	if (!len)
		return (NULL);
	no_file = malloc(sizeof(char) * len + 1);
	while (++i < len)
	{
		*(no_file + i) = malloc(sizeof(char) * lst->content_size);
		*(no_file + i) = lst->content;
		lst = lst->next;
	}
	no_file = qs(no_file, 0, len - 1);
	*(no_file + len) = NULL;
	return (no_file);
}

void	sort_nfpath(t_list *lst)
{
	DIR				*rep;
	char			**path;
	t_list			*tlst;
	struct stat		info;

	tlst = NULL;
	while (lst)
	{
		rep = opendir(lst->content);
		if (!rep)
			ft_lstpushback(&tlst, lst->content, lst->content_size);
		else
			closedir(rep);
		lst = lst->next;
	}
	if (!tlst)
		return ;
	path = sort_lst(tlst);
	error_incpath(path);
}

void	nfpath(char **path, char *command)
{
	int		i;
	t_list	*list;

	i = -1;
	list = NULL;
	while (*(path + (++i)))
		ft_lstpushback(&list, *(path + i), ft_strlen(*(path + i)));
	if (list)
	{
		sort_nfpath(list);
		truefile(list, command);
	}
}

char	**sort_path(t_list *lst)
{
	DIR		*rep;
	char	**path;
	t_list	*tlst;

	tlst = NULL;
	while (lst)
	{
		rep = opendir(lst->content);
		if (rep)
		{
			ft_lstpushback(&tlst, lst->content, lst->content_size);
			closedir(rep);
		}
		lst = lst->next;
	}
	if (!tlst)
		return (NULL);
	path = sort_lst(tlst);
	return (path);
}

char	**truepath(char **path)
{
	int		i;
	int		j;
	int		doublon;
	t_list	*list;

	i = -1;
	list = NULL;
	while (*(path + (++i)))
	{
		j = i;
		doublon = 0;
		while (*(path + (++j)))
			if (ft_strcmp(*(path + i), *(path + j)) == 0)
				doublon = 1;
		if (!doublon)
			ft_lstpushback(&list, *(path + i), ft_strlen(*(path + i)));
	}
	return (sort_path(list));
}
