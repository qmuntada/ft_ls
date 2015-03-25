/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmuntada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 14:32:33 by qmuntada          #+#    #+#             */
/*   Updated: 2014/12/08 16:21:28 by qmuntada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_lstswap(t_list **list, int right, int left)
{
	t_list	*tmp1;
	t_list	*tmp2;
	t_list	*tmp3;
	int		i;

	i = -1;
	tmp1 = *list;
	tmp2 = *list;
	tmp3 = ft_lstnew(NULL, sizeof(struct dirent));
	if (!*list || right == left)
		return ;
	while (++i < right)
		tmp1 = tmp1->next;
	i = -1;
	while (++i < left)
		tmp2 = tmp2->next;
	tmp3->content = tmp1->content;
	tmp1->content = tmp2->content;
	tmp2->content = tmp3->content;
	free(tmp3);
}

char	*fname(t_list *lst, int n)
{
	int				i;
	t_list			*list;
	t_info			*ninfo;

	i = -1;
	list = lst;
	while (++i < n)
	{
		list = list->next;
	}
	ninfo = list->content;
	return (ninfo->name);
}

t_list	*rev_list(t_list *list, int left, int right)
{
	t_list	*lst;
	t_list	*tmp;


	if (list)
	{
		lst = list;
		while (left < right / 2)
		{
			ft_lstswap(&lst, left, (right - left - 1));
			left++;
		}
	}
	return (lst);
}

void	*quick_lstsort(t_list **list, int left, int right)
{
	int		i;
	int		j;
	char	*key;

	key = fname(*list, (((i = left) + (j = right)) / 2));
	while (i <= j)
	{
		while (ft_strcmp(fname(*list, i), key) < 0 && i < right)
			i++;
		while (ft_strcmp(fname(*list, j), key) > 0 && j > left)
			j--;
		if (i <= j)
			ft_lstswap(*&list, i++, j--);
	}
	if (left < j)
		quick_lstsort(*&list, left, j);
	if (i < right)
		quick_lstsort(*&list, i, right);
}

t_list	*lstqs(t_list *lst, int left, int right)
{
	t_list	*list;

	list = lst;
	if (!list)
		return (NULL);
	quick_lstsort(&list, left, right);
	return (list);
}
