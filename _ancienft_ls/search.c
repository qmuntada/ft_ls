/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmuntada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 16:46:28 by qmuntada          #+#    #+#             */
/*   Updated: 2014/12/09 14:25:54 by qmuntada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*struct dirent {  when _DARWIN_FEATURE_64_BIT_INODE is NOT defined
	ino_t      d_ino;                file number of entry
	__uint16_t d_reclen;             length of this record
	__uint8_t  d_type;               file type, see below
	__uint8_t  d_namlen;             length of string in d_name
	char    d_name[255 + 1];   name must be no longer than this
};
#define DT_UNKNOWN       0
#define DT_FIFO          1
#define DT_CHR           2
#define DT_DIR           4
#define DT_BLK           6
#define DT_REG           8
#define DT_LNK          10
#define DT_SOCK         12
#define DT_WHT          14
*/

void	sortfiles(char *command, t_list **lst, char *path)
{
	t_list	*list;

	list = *lst;
	if (!lst)
		return ;
	list = detailinfo(list, path);
	printf("ayyyy\n");
	list = lstqs(list, 0, ft_lstlen(list) - 1);
	if (one_of('t', command))
		list = sort_date(list, 0 ,ft_lstlen(list) - 1, path);
	if (one_of('r', command))
		list = rev_list(list, 0 , ft_lstlen(list));
	*lst = list;
}

void	filestype(char *command, DIR *rep, char *path)
{
	t_list			*list;
	struct dirent	*ent;
	t_list			*replist;
	t_info			*info;

	ft_lstclear(&list);
	ft_lstclear(&replist);
	if (!rep)
		return ;
	info = malloc(sizeof(t_info));
	while ((ent = readdir(rep)) != NULL)
	{
		info->name = ft_strdup(ent->d_name);
		if (ent->d_type == DT_DIR && one_of('R', command)
				&& !(info->name == "." || info->name == ".."))
			ft_lstpushback(&replist, info, sizeof(t_info));
		if (info->name[0] == '.' && one_of('a', command))
			ft_lstpushback(&list, info, sizeof(t_info));
		else if (info->name[0] != '.')
			ft_lstpushback(&list, info, sizeof(t_info));
	}
	sortfiles(command, &list, path);
	display(command, list, path);
	while (replist)
	{
		sortfiles(command, &replist, path);
		searchdir(command, replist->content, path);
		replist = replist->next;
	}
}

void	searchdir(char *command, struct dirent *ent, char *path)
{
	DIR		*rep;
	char	*concpath;

	if (!ent)
		return ;
	ft_strclr(concpath);
	concpath = ft_strjoin(path, "/");
	concpath = ft_strjoin(concpath, ent->d_name);
	if (ent->d_name != "." || ent->d_name != "..")
	{
		printf("|%s|\n", ent->d_name);
		if (ent->d_name[0] == '.' && one_of('a', command))
		{
			display_path(concpath);
			rep = opendir(concpath);
			if (!rep)
				error_readdir(concpath);
			else
			{
				filestype(command, rep, concpath);
				closedir(rep);
			}
		}
		else if (ent->d_name[0] != '.' && !one_of('a', command))
		{
			display_path(concpath);
			rep = opendir(concpath);
			if (!rep)
				error_readdir(concpath);
			else
			{
				filestype(command, rep, concpath);
				closedir(rep);
			}
		}
	}
}

void	search(char *command, char **path)
{
	int		i;
	char	**tpath;
	t_list	*dirlst;
	DIR		*rep;

	i = -1;
	nfpath(path, command);
	tpath = truepath(path);
	if (!tpath)
		return ;
	while (*(tpath + (++i)))
	{
		rep = opendir(*(tpath + i));
		filestype(command, rep, *(tpath + i));
		closedir(rep);
	}
}
