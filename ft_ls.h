#ifndef FT_LS_H
# define FT_LS_H

# include "libft/libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <time.h>
# include <stdio.h>
# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <errno.h>

# define MINORBITS 20
# define MINORMASK ((1U << MINORBITS) - 1)
# define MAJOR(x) ((unsigned int) ((x) >> MINORBITS))
# define MINOR(x) ((unsigned int) ((x) & MINORMASK))
# define MKDEV(ma, mi) (((ma) << MINORBITS) | (mi))

typedef struct	s_opt
{
	int		l;
	int		_r;
	int		a;
	int		r;
	int		t;
	int		u;
	int		f;
	int		g;
}				t_opt;

typedef struct	s_elem
{
	char			*name;
	char			*path;
	time_t			date;
	mode_t			st_mode;
	nlink_t			st_nlink;
	uid_t			st_uid;
	gid_t			st_gid;
	off_t			st_size;
	quad_t			st_blocks;
	int				type;
	dev_t			st_rdev;
	struct s_elem	*next;
}				t_elem;

typedef struct	s_size
{
	unsigned int	total;
	unsigned int	size;
	unsigned int	groupspace;
	unsigned int	userspace;
	unsigned int	linkspace;
	unsigned int	min;
	unsigned int	maj;
}				t_size;

int		one_of(char c, char *str);

void	error_arg(char arg);
void	basicerror(char *name, char *error, int ex);

void	core(t_opt arg, t_list *path);
void	display_file(t_opt arg, t_elem *files, int multidir);

int		elemget(t_elem **files, struct dirent *file, char *path, t_opt arg);
void	elemgetfiles(t_elem **files, char *name, char *path, t_opt arg);

void	display_date(time_t date);

void	sort(t_elem **list, int (*cmp)());
void	reversesort(t_elem **list);

int		cmp_alpha(t_elem *elem1, t_elem *elem2);
int		cmp_time(t_elem *elem1, t_elem *elem2);

void	recursion(t_opt arg, t_elem *files);

void	ls_simple(t_opt arg, t_elem *files);
void	ls_long(t_opt arg, t_elem *files);

t_size	get_size(t_opt arg, t_elem *files);

void	print_access(t_elem *elem);
void	print_int(unsigned int nlink, unsigned int spacemax);
void	print_str(char *str, unsigned int spacemax);
void	print_majmin(t_elem *file, t_size size);

#endif
