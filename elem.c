
#include "ft_ls.h"

t_elem	*elemnew(char *name, char *path, int type, t_opt arg)
{
	t_elem			*elem;
	struct stat		fstat;

	elem = malloc(sizeof(t_elem));
	elem->name = name;
	elem->path = path;
	if (lstat(ft_strjoin(path, name), &fstat) == -1)
	{
		basicerror("ft_ls: ", elem->name, 0);
		return (NULL);
	}
	elem->st_mode = fstat.st_mode;
	elem->st_nlink = fstat.st_nlink;
	elem->st_uid = fstat.st_uid;
	elem->st_gid = fstat.st_gid;
	elem->st_size = fstat.st_size;
	elem->st_blocks = fstat.st_blocks;
	elem->date = (arg.u == 1 ? fstat.st_atime : fstat.st_mtime);
	elem->type = type;
	elem->st_rdev = fstat.st_rdev;
	elem->next = NULL;
	return (elem);
}

int		elemget(t_elem **files, struct dirent *file, char *path, t_opt arg)
{
	t_elem	*list;

	list = *files;
	if (!file)
		return (0);
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = elemnew(file->d_name, path, file->d_type, arg);
	}
	else
		*files = elemnew(file->d_name, path, file->d_type, arg);
	return (1);
}

void	elemgetfiles(t_elem **files, char *name, char *path, t_opt arg)
{
	t_elem *list;

	list = *files;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = elemnew(name, path, 0, arg);
	}
	else
		*files = elemnew(name, path, 0, arg);
}
