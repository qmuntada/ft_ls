
#include "ft_ls.h"

void	do_ls(t_opt arg, t_list *path)
{
	t_list	*cur;
	struct dirent *dir;

	cur = path;
	while (cur)
	{
		printf("boucle\n");
		while ((dir = readdir(cur->content)) != NULL)
		{
			printf("lol %s\n", dir->d_name);
		}
		cur = cur->next;
	}
}

void	core(t_opt arg, t_list *path)
{
	DIR		*dir;
	t_list	*file;
	t_list	*directory;

	file = NULL;
	directory = NULL;
	while (path)
	{
		if ((dir = opendir(path->content)) == NULL)
		{
			if (errno != ENOTDIR)
				basicerror("ft_ls: ", path->content, 0);
			else
				ft_lstpushback(&file ,path->content, path->content_size);
		}
		else
			ft_lstpushback(&directory, dir, sizeof(dir));
		path = path->next;
	}
	//do_ls_file(file);
	if (directory)
		do_ls(arg, directory);
}
