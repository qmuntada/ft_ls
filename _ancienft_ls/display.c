/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmuntada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 15:24:04 by qmuntada          #+#    #+#             */
/*   Updated: 2014/12/08 17:58:52 by qmuntada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*struct stat
{
	dev_t    st_dev;    device inode resides on
	ino_t    st_ino;    inode's number
	mode_t   st_mode;   inode protection mode
	nlink_t  st_nlink;  number of hard links to the file
	uid_t    st_uid;    user-id of owner
	gid_t    st_gid;    group-id of owner
	dev_t    st_rdev;   device type, for special file inode
	struct timespec st_atimespec;  time of last access
	struct timespec st_mtimespec;  time of last data modification
	struct timespec st_ctimespec;  time of last file status change
	off_t    st_size;   file size, in bytes
	quad_t   st_blocks; blocks allocated for file
	u_long   st_blksize; optimal file sys I/O ops blocksize
	u_long   st_flags;  user defined flags for file
	u_long   st_gen;    file generation number
};*/

void	display_path(char *path)
{
	ft_putchar_fd('\n', 2);
	ft_putstr_fd(path, 2);
	ft_putstr_fd(":\n", 2);
}

int		*get_lendisplay(t_list *list, char *path)
{
	int		*len;

	len = malloc(sizeof(int) * 5);
	len[0] = get_lenlink(list);
	len[1] = get_lenusrid(list);
	len[2] = get_lenusrgrp(list);
	len[3] = get_lensize(list);
	len[4] = 0;
	return (len);
}

void	display_tnfsb(t_list *list, char *path)
{
	t_info			*info;
	t_list			*lst;
	int				n;

	lst = list;
	info = malloc(sizeof(t_info));
	n = 0;
	while (lst)
	{
		info = lst->content;
		n += info->st_blocks;
		lst = lst->next;
	}
	ft_putstr("total ");
	ft_putnbr(n);
	ft_putchar('\n');
}

void	ls_long(t_list *list, char *path, int boolean)
{
	t_list		*lst;
	t_info		*info;
	int			*len;

	lst = list;
	len = get_lendisplay(lst, path);
	if (boolean)
		display_tnfsb(lst, path);
	info = malloc(sizeof(t_info));
	while (lst)
	{
		info = NULL;
		info = lst->content;
		display_permi(info);
		display_nlink(info, len[0]);
		display_usrid(info, len[1]);
		display_usrgrp(info, len[2]);
		display_size(info, len[3]);
		display_date(info);
		ft_putstr(info->name);
		ft_putchar('\n');
		lst = lst->next;
	}
}

void	display(char *command, t_list *list, char *path)
{
	t_info	*info;

	if (!list)
		return ;
	if (one_of('l', command))
		ls_long(list, ft_strjoin("/", path), 1);
	else
		while (list)
		{
			info = list->content;
			ft_putstr(info->name);
			ft_putchar('\n');
			list = list->next;
		}
}
