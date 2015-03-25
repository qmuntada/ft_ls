/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmuntada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 18:34:52 by qmuntada          #+#    #+#             */
/*   Updated: 2014/12/17 16:24:34 by qmuntada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	**swap(char **array, int a, int b)
{
	char	*tmp;
	tmp = strdup(*(array + a));
	*(array + a) = *(array + b);
	*(array + b) = tmp;
	return (array);
}

char	**quick_sort(char **array, int left, int right)
{
	int		i;
	int		j;
	char	*key;

	key = array[((i = left) + (j = right)) / 2];
	while (i <= j)
	{
		while (ft_strcmp(*(array + i), key) < 0 && i < right)
			i++;
		while (ft_strcmp(*(array + j), key) > 0 && j > left)
			j--;
		if (i <= j)
			swap(array, i++, j--);
	}
	if (left < j)
		quick_sort(array, left, j);
	if (i < right)
		quick_sort(array, i, right);
	return (array);
}

char	**qs(char **array, int beg, int end)
{
	if (end != 0)
		array = quick_sort(array, beg, end);
	return (array);
}
