
#include "ft_ls.h"

int		one_of(char c, char *str)
{
	int		i;

	if (str == NULL || c == '\0')
		return (0);
	i = -1;
	while (str[++i])
		if (c == str[i])
			return (1);
	return (0);
}
