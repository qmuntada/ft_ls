
#include "ft_ls.h"

void	do_recursion(t_opt arg, char *path)
{
	t_elem	*files;
	DIR *dir;

	files = NULL;
	if ((dir = opendir(path)) != NULL)
	{
		while (elemget(&files, readdir(dir), \
					ft_strjoin(path, "/"), arg) != 0)
			;
		if (files)
		{
			ft_putchar('\n');
			display_file(arg, files, 1);
			files = NULL;
		}
	}
	else if (errno != ENOTDIR)
			basicerror("ft_ls: ", path, 0);
}

void	recursion(t_opt arg, t_elem *files)
{
	t_elem	*cur;
	char	*cpath;

	cur = files;
	while (cur)
	{
		cpath = ft_strjoin(cur->path, cur->name);
		printf("|%s| |%s|\n", cur->path, cur->name);
		if (S_ISDIR(cur->st_mode) && ft_strcmp(".", cur->name) && \
			ft_strcmp("..", cur->name) && \
			!(arg.a == 0 && cur->name[0] == '.'))
			do_recursion(arg, cpath);
		cur = cur->next;
	}
}
