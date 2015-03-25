/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmuntada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 17:46:18 by qmuntada          #+#    #+#             */
/*   Updated: 2014/12/08 14:56:25 by qmuntada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

//La fonction arglen renvoie la longuer des arguements et la postion du premier
//argument non commande afin de facilier l'allocation de memoire.
int		ft_arglen(int ac, char **av, int *ipath)
{
	int		nb;
	int		cpt;

	nb = 0;
	cpt = 0;
	*ipath = 0;
	while (++nb < ac && !*ipath)
	{
		if (av[nb][0] == '-')
		{
			if (!av[nb][1])
			{
				*ipath = nb;
				return (cpt);
			}
			cpt += ft_strlen(av[nb]) - 1;
		}
		else
			*ipath = nb;
	}
	if (!*ipath)
		*ipath = nb;
	return (cpt);
}

//La fonction back_arg renvoie les arguments demandes par l'utilisateur.
char	*back_arg(int ac, char **av, int *ipath)
{
	int		nb;
	int		cpt;
	char	*command;

	nb = 0;
	cpt = -1;
	command = malloc(sizeof(char) * ft_arglen(ac, av, *&ipath));
	ft_strclr(command);
	if (!command)
		return (NULL);
	while (++nb < *ipath)
	{
		++av[nb];
		command = ft_strjoin(command, av[nb]);
	}
	command = sort_arg(command);
	return (command);
}

//La fonction back_path renvoie les chemins demandes par l'utilisateur.
char	**back_path(int ac, char **av, int ipath)
{
	int		i;
	char	**path;

	i = -1;
	path = malloc(sizeof(char) * (ac - ipath));
	if (!path)
		return (NULL);
	while (ipath < ac)
	{
		*(path + (++i)) = malloc(sizeof(char) * ft_strlen(*(av + ipath)));
		if (!*(path + i))
			return (NULL);
		ft_strclr(*(path + i));
		*(path + i) = *(av + ipath);
		ipath++;
	}
	if (!*path)
	{
		*path = malloc(sizeof(char) * 2);
		*path = ".\0";
	}
	return (path);
}

// COMMANDE DE TYPES DE FICHIERS A AFFICHER.
//
//-a AFFICHE LES FICHIERS CACHES (.)
//-R AFFICHE LES SOUS DOSSIERS RECURSIVEMENT
//
// COMMANDE DE TRI DE CES FICHIERS
//
//-r INVERSE L'ORDRE DE TRI
//-t TRI PAR DATE DE DERNIERE MODIFICATION
//
//COMMANDE D'AFFICHAGE
//
//-l AFFICHE LE LONG FORMAT DES FICHIERS (1 PAR LIGNE)
//-1 AFFICHE UN FICHIER PAR LIGNE.



//La fonction coeur.
int		main(int ac, char **av)
{
	char	*command;
	char	**path;
	int		ipath;

	command = NULL;
	path = NULL;
	command = back_arg(ac, av, &ipath);
	path = back_path(ac, av, ipath);
	search(command, path);
	return (0);
}
