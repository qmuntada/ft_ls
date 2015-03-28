
#include "ft_ls.h"

void	size_init(t_size *size)
{
	size->size = 0;
	size->groupspace = 0;
	size->userspace = 0;
	size->linkspace = 0;
	size->min = 0;
	size->maj = 0;
	size->total = 0;
}

void	get_size2(t_size *size, t_elem *cur)
{
			size->linkspace = (unsigned int)ft_strlen(ft_itoa( \
				cur->st_nlink)) > size->linkspace ? \
				(unsigned int)ft_strlen(ft_itoa(cur->st_nlink)) \
				: size->linkspace;
			size->userspace = (unsigned int)ft_strlen(getpwuid( \
				cur->st_uid)->pw_name) > size->userspace ? \
				(unsigned int)ft_strlen(getpwuid(cur->st_uid)->pw_name) \
				: size->userspace;
			size->groupspace = (unsigned int)ft_strlen(getgrgid( \
				cur->st_gid)->gr_name) > size->groupspace ? \
				(unsigned int)ft_strlen(getgrgid(cur->st_gid)->gr_name) \
				: size->groupspace;
			size->maj = (unsigned int)ft_strlen(ft_itoa(MAJOR( \
				cur->st_rdev))) > size->maj ? \
				(unsigned int)ft_strlen(ft_itoa(MAJOR(cur->st_rdev))) \
				: size->maj;
			size->min = (unsigned int)ft_strlen(ft_itoa(MINOR( \
				cur->st_rdev))) > size->min ? \
				(unsigned int)ft_strlen(ft_itoa(MINOR(cur->st_rdev))) \
				: size->min;
			size->size = (unsigned int)ft_strlen(ft_itoa(cur->st_size)) \
				> size->size ? (unsigned int)ft_strlen(ft_itoa( \
				cur->st_size)) : size->size;
			size->total += cur->st_blocks;
}

t_size	get_size(t_opt arg, t_elem *files)
{
	t_elem	*cur;
	t_size	size;
	
	size_init(&size);
	cur = files;
	while (cur)
	{
		if (!(arg.a == 0 && cur->name[0] == '.'))
			get_size2(&size, cur);
		cur = cur->next;
	}
	return (size);
}

