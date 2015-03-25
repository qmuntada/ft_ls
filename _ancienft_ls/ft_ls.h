/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmuntada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 14:48:06 by qmuntada          #+#    #+#             */
/*   Updated: 2015/02/16 18:17:14 by qmuntada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define  FT_LS_H

# include "libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <sys/xattr.h>
# include <time.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>

# define MINORBITS 20
# define MINORMASK ((1U << MINORBITS) - 1)
# define MAJOR(dev) ((unsigned int) ((dev) >> MINORBITS))
# define MINOR(dev) ((unsigned int) ((dev) & MINORMASK))
# define MKDEV(ma,mi) (((ma) << MINORBITS) | (mi))

typedef struct		s_info
{
	char			*name;
	mode_t			st_mode;
	nlink_t			st_nlink;
	uid_t			st_uid;
	gid_t			st_gid;
	struct timespec	st_mtimespec;
	off_t			st_size;
	quad_t			st_blocks;
}					t_info;

void	error_readdir(char *path);
void	error_arg(char c);
void	error_incpath(char **no_file);
char	*sort_arg(char *command);
void	search(char *command, char **path);
int		one_of(char c, char *etalon);
void	searchdir(char *comman, struct dirent *ent, char *path);
char	**qs(char **array, int beg, int end);
void	display(char *command, t_list *list, char *path);
void	nfpath(char **path, char *command);
void	display_path(char *path);
void	*truefile(t_list *list, char *command);
char	**truepath(char **path);
t_list	*lstqs(t_list *lst, int left, int right);
char	*fname(t_list *lst, int n);
void	ft_lstswap(t_list **list, int right, int left);
t_list	*sort_date(t_list *lst, int left, int right, char *path);
t_list	*rev_list(t_list *list, int left, int right);
t_list	*detailinfo(t_list *lst, char *path);
int		get_lensize(t_list *list);
int		get_lenusrgrp(t_list *list);
int		get_lenusrid(t_list *list);
int		get_lenlink(t_list *list);
void	display_permi(t_info *info);
void	display_nlink(t_info *info, int i);
void	display_usrid(t_info *info ,int i);
void	display_usrgrp(t_info *info, int i);
void	display_size(t_info *info, int i);
void	display_date(t_info *info);
void	sortfiles(char *command, t_list **lst, char *path);
void	ls_long(t_list *list, char *path, int boolean);

#endif
