
#include "ft_ls.h"

void	get_size2(t_size *size, t_elem *cur)
{
	size->linkspace = (int)ft_strlen(ft_itoa(cur->st_nlink)) > \
		size->linkspace ? (int)ft_strlen(ft_itoa(cur->st_nlink)) \
		: size->linkspace;
	size->userspace = (int)ft_strlen(getpwuid(cur->st_uid)->pw_name) \
		> size->userspace ? (int)ft_strlen(getpwuid(cur->st_uid)->pw_name) \
		: size->userspace;
	size->groupspace = (int)ft_strlen(getgrgid(cur->st_gid)->gr_name) \
		> size->groupspace ? (int)ft_strlen(getgrgid(cur->st_gid)->gr_name) \
		: size->groupspace;
	size->maj = (int)ft_strlen(ft_itoa(major(cur->st_rdev))) > size->maj \
		? (int)ft_strlen(ft_itoa(major(cur->st_rdev))) : size->maj;
	size->min = (int)ft_strlen(ft_itoa(minor(cur->st_rdev))) > size->min ? \
		(int)ft_strlen(ft_itoa(minor(cur->st_rdev))) : size->min;
	size->size = (int)ft_strlen(ft_itoa(cur->st_size)) > size->size ? \
		(int)ft_strlen(ft_itoa(cur->st_size)) : size->size;
	size->total += cur->st_blocks;
}

t_size	get_size(t_opt arg, t_elem *files)
{
	t_elem	*cur;
	t_size	size;

	size = (t_size){0, 0, 0, 0, 0, 0, 0};
	cur = files;
	while (cur)
	{
		if (!(arg.a == 0 && cur->name[0] == '.'))
			get_size2(&size, cur);
		cur = cur->next;
	}
	size.size = size.size < size.maj + size.min ? \
		size.maj + size.min : size.size;
	return (size);
}

