
#include "ft_ls.h"

// -l -R -a -r -t -1


int		analize_str(char *str)
{
	if (str && str[0] == '-')
		return (1);
	return (0);
}

void	get_arg(t_opt *arg, char *str)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (one_of(str[i], "-1lRart"))
		{
			if (str[i] == 'l')
				arg->l = 1;
			else if (str[i] == 'R')
				arg->_r = 1;
			else if (str[i] == 'a')
				arg->a = 1;
			else if (str[i] == 'r')
				arg->r = 1;
			else if (str[i] == 't')
				arg->t = 1;
		}
		else
			error_arg(str[i]);
	}
}

void	get_param(int nb, char **param, t_opt *arg, t_list **path)
{
	int		i;
	int		type;

	i = -1;
	type = 1;
	// first let's differentiate arg from path
	while (++i < nb)
	{
		if (analize_str(param[i + 1]) == 0)
			type = 0;
		if (type == 1)
			get_arg(arg, param[i + 1]);
		else if (type == 0)
			ft_lstpushback(path, param[i + 1], ft_strlen(param[i + 1]));
	}
}

int		main(int ac, char **av)
{
	t_opt	arg;
	t_list	*path;

	arg = (t_opt){0, 0, 0, 0, 0};
	path = NULL;
	if (ac > 1)
		get_param(ac - 1, av, &arg, &path);
	if (path == NULL)
		path = ft_lstnew(".", ft_strlen("."));
	core(arg, path);
	return (0);
}
