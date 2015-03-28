
#include "ft_ls.h"

void	display_file(t_opt arg, t_elem *files, int multidir)
{
	t_elem	*cur;

	if (!files)
		return ;
	cur = files;
	if (arg.f == 0)
	{
		sort(&cur, cmp_alpha);
		(arg.t == 1 || arg.u == 1) ? sort(&cur, cmp_time) : NULL;
		arg.r == 1 ? reversesort(&cur) : NULL;
	}
	if (multidir || arg._r)
	{
		ft_putstr(cur->path);
		ft_putstr(":\n");
	}
	if (arg.l == 1 || arg.g == 1)
		ls_long(arg, cur);
	else
		ls_simple(arg, cur);
	arg._r == 1 ? recursion(arg, cur) : NULL;
}

void	do_ls_dir(t_opt arg, t_list *path, int multidir)
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
			while (elemget(&files, readdir(dir), \
				ft_strjoin(cur->content, "/"), arg) != 0)
				;
		cur = cur->next;
	}
	if (files)
		display_file(arg, files, multidir);
}

void	do_ls_file(t_opt arg, t_list *path)
{
	t_list	*cur;
	t_elem	*files;

	cur = path;
	files = NULL;
	while (cur)
	{
		elemgetfiles(&files, cur->content, "./", arg);
		cur = cur->next;
	}
	if (files)
		display_file(arg, files, 0);
}

void	core(t_opt arg, t_list *path)
{
	DIR		*dir;
	t_list	*file;
	t_list	*directory;
	t_list	*cur;

	file = NULL;
	directory = NULL;
	cur = path;
	while (cur)
	{
		if ((dir = opendir(cur->content)) == NULL)
			errno != ENOTDIR ? basicerror("ft_ls: ", cur->content, 0) : \
				ft_lstpushback(&file ,cur->content, cur->content_size);
		else
		{
			ft_lstpushback(&directory, cur->content, cur->content_size);
			if (closedir(dir) == -1)
				basicerror("ft_ls: ", cur->content, 0);
		}
		cur = cur->next;
	}
	file ? do_ls_file(arg, file) : NULL;
	directory ? do_ls_dir(arg, directory, (directory->next != NULL)) : NULL;
	//free(path); Need a real function that does free the list
}
