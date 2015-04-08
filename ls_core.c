
#include "ft_ls.h"

t_elem	*sort_elem(t_elem *list, t_opt arg)
{
	t_elem	*new;

	if (!list)
		return (NULL);
	new = list;
	if (arg.f == 0)
	{
		sort(&new, cmp_alpha);
		(arg.t == 1 || arg.u == 1) ? sort(&new, cmp_time) : NULL;
		arg.r == 1 ? reversesort(&new) : NULL;
	}
	return (new);
}

void	display_file(t_opt arg, t_elem *files, int multidir)
{
	t_elem	*cur;

	cur = files;
	cur = sort_elem(cur, arg);
	//if (multidir)
//	{
		//ft_putstr(cur->path);
		//ft_putstr(":\n");
//	}
	(arg.l == 1 || arg.g == 1) ? \
			ls_long(arg, cur, multidir) : ls_simple(arg, cur);
	arg._r == 1 ? recursion(arg, cur) : NULL;
}

void	do_ls_dir(t_opt arg, t_list *path, int multidir)
{
	t_list	*cur;
	t_elem	*files;
	t_elem	*dirlist;
	DIR *dir;

	cur = path;
	files = NULL;
	dirlist = NULL;
	while (cur)
	{
		elemgetfiles(&dirlist, cur->content, "", arg);
		cur = cur->next;
	}
	dirlist = sort_elem(dirlist, arg);
	while (dirlist)
	{
		dir = opendir(dirlist->name);
		while (elemget(&files, readdir(dir), \
			ft_strjoin(dirlist->path, "/"), arg) != 0)
			;
		if (files)
		{
			if (multidir || arg._r)
			{
				ft_putstr(dirlist->name);
				ft_putstr(":\n");
			}
			display_file(arg, files, (multidir || arg._r));
			files->next && multidir ? ft_putchar('\n') : NULL;
		}
		files = NULL;
		dirlist = dirlist->next;
	}
}

void	do_ls_file(t_opt arg, t_list *path)
{
	t_list	*cur;
	t_elem	*files;

	cur = path;
	files = NULL;
	while (cur)
	{
		elemgetfiles(&files, cur->content, "", arg);
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
