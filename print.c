
#include "ft_ls.h"


void	print_access(t_elem *elem)
{
	ft_putchar((S_ISFIFO(elem->st_mode)) ? 'p' : '\0');
	ft_putchar((S_ISCHR(elem->st_mode)) ? 'c' : '\0');
	ft_putchar((S_ISDIR(elem->st_mode)) ? 'd' : '\0');
	ft_putchar((S_ISBLK(elem->st_mode)) ? 'b' : '\0');
	ft_putchar((S_ISREG(elem->st_mode)) ? '-' : '\0');
	ft_putchar((S_ISLNK(elem->st_mode)) ? 'l' : '\0');
	ft_putchar((S_ISSOCK(elem->st_mode)) ? 's' : '\0');
	ft_putchar((elem->st_mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((elem->st_mode & S_IWUSR) ? 'w' : '-');
	ft_putchar((elem->st_mode & S_IXUSR) ? 'x' : '-');
	ft_putchar((elem->st_mode & S_IRGRP) ? 'r' : '-');
	ft_putchar((elem->st_mode & S_IWGRP) ? 'w' : '-');
	ft_putchar((elem->st_mode & S_IXGRP) ? 'x' : '-');
	ft_putchar((elem->st_mode & S_IROTH) ? 'r' : '-');
	ft_putchar((elem->st_mode & S_IWOTH) ? 'w' : '-');
	ft_putchar((elem->st_mode & S_IXOTH) ? 'x' : '-');
	ft_putstr("  ");
}

void	print_int(unsigned int nlink, unsigned int spacemax)
{
	unsigned int		n;

	n = spacemax - (unsigned int)ft_strlen(ft_itoa(nlink));
	while (n-- > 0)
		ft_putchar(' ');
	ft_putnbr(nlink);
	ft_putstr(" ");
}

void	print_str(char *str, unsigned int spacemax)
{
	unsigned int		n;

	n = spacemax - (unsigned int)ft_strlen(str);
	ft_putstr(str);
	while (n-- > 0)
		ft_putchar(' ');
	ft_putstr("  ");
}

void	print_majmin(t_elem *file, t_size size)
{
	unsigned int		min;
	unsigned int		maj;

	min = (unsigned int)ft_strlen(ft_itoa(MINOR(file->st_rdev)));
	maj = (unsigned int)ft_strlen(ft_itoa(MAJOR(file->st_rdev)));
	ft_putnbr(maj);
	while (maj < size.maj--)
		ft_putchar(' ');
	ft_putstr(", ");
	ft_putnbr(min);
	while (min < size.min--)
		ft_putchar(' ');
	ft_putchar(' ');
}
