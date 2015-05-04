/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmuntada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/09 17:36:59 by qmuntada          #+#    #+#             */
/*   Updated: 2015/05/04 17:20:40 by qmuntada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		analize_str(char *str)
{
	if (str && str[0] == '-' && str[1])
		return (1);
	return (0);
}

void	get_arg(t_opt *arg, char *str)
{
	int		i;

	i = 0;
	while (str[++i])
	{
		if (one_of(str[i], "1lRafgrtu") || (str[1] == '-' && !str[2]))
		{
			arg->l = (str[i] == 'l' ? 1 : arg->l);
			arg->upper_r = (str[i] == 'R' ? 1 : arg->upper_r);
			arg->a = (str[i] == 'a' ? 1 : arg->a);
			arg->r = (str[i] == 'r' ? 1 : arg->r);
			arg->t = (str[i] == 't' ? 1 : arg->t);
			arg->u = (str[i] == 'u' ? 1 : arg->u);
			arg->f = (str[i] == 'f' ? 1 : arg->f);
			arg->l = (str[i] == 'f' ? 0 : arg->l);
			arg->a = (str[i] == 'f' ? 1 : arg->a);
			arg->g = (str[i] == 'g' ? 1 : arg->g);
			arg->l = (str[i] == '1' ? 0 : arg->l);
		}
		else
			error_arg(str[i]);
	}
}

void	get_param(int nb, char **param, t_opt *arg, t_list **path)
{
	int		i;
	int		type;

	i = -1;
	type = 1;
	while (++i < nb)
	{
		if (analize_str(param[i + 1]) == 0)
			type = 0;
		if (type == 1)
			get_arg(arg, param[i + 1]);
		else if (type == 0)
			ft_lstpushback(path, param[i + 1], ft_strlen(param[i + 1]));
	}
}

int		main(int ac, char **av)
{
	t_opt	arg;
	t_list	*path;

	arg = (t_opt){0, 0, 0, 0, 0, 0, 0, 0};
	path = NULL;
	if (ac > 1)
		get_param(ac - 1, av, &arg, &path);
	if (path == NULL)
		path = ft_lstnew(".", ft_strlen("."));
	core(arg, path, path->next != NULL ? 1 : 0);
	return (0);
}
