
#include "ft_ls.h"


void	display_file(t_opt arg, t_elem *files)
{
	// FIRST : TRI FICHIER CACHE -a (supression)
	// THEN : TRI TEMPS / ALPHA / REVERSE -tr
	// THEN : AFFICHAGE SIMPLE OU LONG -l
	// THEN : RECURSION : ON REDEMARRE LA FONCTION
}

void	do_ls_dir(t_opt arg, t_list *path)
{
	t_list	*cur;
	t_elem	*files;
	DIR *dir;

	cur = path;
	files = NULL;
	while (cur)
	{
		if ((dir = opendir(cur->content)) == NULL)
			basicerror("ft_ls: ", cur->content, 0);
		else
		{
			while (ft_elemget(&files, readdir(dir), ft_strjoin(cur->content, "/")) != 0)
				;
		}
		cur = cur->next;
	}
	display_file(arg, files);
}

void	do_ls_file(t_opt arg, t_list *path)
{
	t_list	*cur;
	t_elem	*files;

	cur = path;
	files = NULL;
	while (cur)
	{
		// version de ft_elemget sans la struct dirent
		cur = cur->next;
	}
	display_file(arg, files);
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
		{
			ft_lstpushback(&directory, path->content, path->content_size);
			if (closedir(dir) == -1)
				basicerror("ft_ls: ", path->content, 0);
		}
		path = path->next;
	}
	if (file)
		do_ls_file(arg, file);
	if (directory)
		do_ls_dir(arg, directory);
	//free(path);
}
