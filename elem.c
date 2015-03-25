
#include "ft_ls.h"

t_elem	*elemnew(struct dirent *file, char *path)
{
	t_elem			*elem;
	struct stat		fstat;

	elem = malloc(sizeof(t_elem));
	elem->name = file->d_name;
	elem->path = path;
	if (stat(ft_strjoin(path, file->d_name), &fstat) == -1)
		basicerror("ft_ls: ", elem->name, 0);
	else
	{
		elem->st_mode = fstat.st_mode;
		elem->st_nlink = fstat.st_nlink;
		elem->st_uid = fstat.st_uid;
		elem->st_gid = fstat.st_gid;
		elem->st_size = fstat.st_size;
		elem->st_blocks = fstat.st_blocks;
		elem->date = fstat.st_mtimespec.tv_sec;
	}
	printf("%s%s\n", elem->path, elem->name);
	elem->next = NULL;
	return (elem);
}

int		ft_elemget(t_elem **files, struct dirent *file, char *path)
{
	t_elem	*list;

	list = *files;
	if (!file)
		return (0);
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = elemnew(file, path);
	}
	else
		*files = elemnew(file, path);
	return (1);
}
