
#include "ft_ls.h"

void	ls_simple(t_opt arg, t_elem *files)
{
	t_elem	*cur;

	cur = files;
	while (cur)
	{
		if (!(arg.a == 0 && cur->name[0] == '.'))
			ft_putendl(cur->name);
		cur = cur->next;
	}
}

void	ls_long(t_opt arg, t_elem *files, int dir)
{
	t_elem	*cur;
	t_size	size;

	cur = files;
	size = get_size(arg, files);
	if (dir)
	{
		ft_putstr("total ");
		ft_putnbr(size.total / 2);
		ft_putchar('\n');
	}
	while (cur)
	{
		if (!(arg.a == 0 && cur->name[0] == '.'))
		{
			print_access(cur);
			print_int(cur->st_nlink, size.linkspace);
			if (arg.g == 0)
				print_str(getpwuid(cur->st_uid)->pw_name, size.userspace);
			print_str(getgrgid(cur->st_gid)->gr_name, size.groupspace);
			if (S_ISCHR(cur->st_mode) || S_ISBLK(cur->st_mode))
				print_majmin(cur, size);
			else
				print_int(cur->st_size, size.size);
			display_date(cur->date);
			ft_putendl(cur->name);
		}
		cur = cur->next;
	}
}
