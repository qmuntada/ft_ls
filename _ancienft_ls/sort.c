/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmuntada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/23 18:34:33 by qmuntada          #+#    #+#             */
/*   Updated: 2014/12/08 15:51:48 by qmuntada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

//La fonction one_of verifie si le char c est compris dams le string etalon
int		one_of(char c, char *etalon)
{
	*etalon--;
	while (*++etalon)
		if (c == *etalon)
			return (1);
	return (0);
}

// La fonction sort_arg classe les arguments en fonction de leur priorite
// d'execution, supprime les doublons et les arguments non supportes.
char	*sort_arg(char *command)
{
//	-a -r -l
//	-R -t -1
//
	char	*arg;
	int		i;

	i = -1;
	// JE NE GERE PAS L'AFFICHAGE EN COLLONE DONC :
	if (!*command)
		return ("1");
	arg = malloc(sizeof(char) * ft_strlen("aRrtl1"));
	*command--;
	while (*++command)
	{
		if (!one_of(*command, "aRrtl1"))
			error_arg(*command);
		if (one_of(*command, "arlRt1") && !one_of(*command, arg))
			arg[++i] = *command;
	}
	arg[++i] = '\0';
	return (arg);
}
