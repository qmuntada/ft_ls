/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_date.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmuntada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 17:23:02 by qmuntada          #+#    #+#             */
/*   Updated: 2014/12/08 18:02:49 by qmuntada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
struct stat
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
};
struct timespec
{
	time_t  tv_sec    seconds
	long    tv_nsec   nanoseconds
};
*/

t_info	*fnum(t_list *list, int n)
{
	t_info		*info;
	int		i;

	info = malloc(sizeof(t_info));
	i = -1;
	while (++i < n && list)
		list = list->next;
	info = list->content;
	return (info);
}

void	quick_lstsortdate(t_list **list, int left, int right, char *path)
{
	int		i;
	int		j;
	t_info	*k;
	t_info	*buf1;

	k = fnum(*list, ((i = left) + (j = right) / 2));
	while (i <= j)
	{
		buf1 = fnum(*list, i);
		while (buf1->st_mtimespec.tv_sec > k->st_mtimespec.tv_sec && i < right)
			buf1 = fnum(*list, ++i);
		buf1 = fnum(*list, j);
		while (buf1->st_mtimespec.tv_sec < k->st_mtimespec.tv_sec && j > left)
			buf1 = fnum(*list, --j);
		if (i <= j)
			ft_lstswap(*&list, i++, j--);
	}
	if (left < j)
		quick_lstsortdate(*&list, left, j, path);
	if (i < right)
		quick_lstsortdate(*&list, i, right, path);
}

t_list	*sort_date(t_list *lst, int left, int right, char *path)
{
	t_list	*list;

	list = lst;
	if (!list)
		return (NULL);
	quick_lstsortdate(&list, left, right, ft_strjoin(path, "/"));
	return (list);
}
