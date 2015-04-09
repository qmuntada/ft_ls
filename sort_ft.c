/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmuntada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/09 17:37:18 by qmuntada          #+#    #+#             */
/*   Updated: 2015/04/09 17:37:19 by qmuntada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		cmp_alpha(t_elem *elem1, t_elem *elem2)
{
	return (ft_strcmp(elem1->name, elem2->name));
}

int		cmp_time(t_elem *elem1, t_elem *elem2)
{
	return ((int)elem1->date < (int)elem2->date);
}
