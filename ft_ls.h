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

/*# define DT_UNKNOWN	0
# define DT_FIFO	1
# define DT_CHR		2
# define DT_DIR		4
# define DT_BLK		6
# define DT_REG		8
# define DT_LNK		10
# define DT_SOCK	12
# define DT_WHT		14
*/
# define LS_MAJOR(x) ((int32_t)(((u_int32_t)(x) >> 24) & 0xff))
# define LS_MINOR(x) ((int32_t)((x) & 0xffffff))

typedef struct	s_opt
{
	int		l;
	int		_r;
	int		a;
	int		r;
	int		t;
	int		nul;
}				t_opt;

typedef struct	s_elem
{
	char			*name;
	char			*path;
	time_t			date;
	int				sub;
	mode_t			st_mode;
	off_t			st_size;
	nlink_t			st_nlink;
	quad_t			st_blocks;
	dev_t			st_rdev;
	char			*username;
	char			*groupname;
	struct s_elem	*nxt;
}				t_elem;

typedef struct	s_size
{
	quad_t			total;
	int				size;
	int				groupsize;
	int				usersize;
	int				linksize;
	int				min;
	int				maj;
}				t_size;

int		one_of(char c, char *str);

void	error_arg(char arg);
void	basicerror(char *name, char *error, int ex);

void	core(t_opt arg, t_list *path);

#endif
