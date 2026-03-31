#include "push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	t_list_flag		*flag;
	int				i;
	char			*joint;
	char			*hold;
	char			**temp;
	t_list_stack	*a;

	if (argc < 2)
		return (0);
	i = 1;
	flag = NULL;
	a = NULL;
	joint = ft_strdup("");

	define_flag_struct(&flag);
	check_flags(argv, &argc, flag);
	i = 1;
	while (argv[i])
	{
		hold = joint;
		joint = ft_strjoinspace(hold, argv[i++]);
		free(hold);
	}
	temp = ft_split(joint, ' ');
	manage_input(temp, &a, flag, joint);
	if (a)
	{
		define_indexes(a);
		actual_sort(&a, flag);
		free_everything(&a, joint, temp, &flag);
	}
	return (0);
}

void	define_flag_struct(t_list_flag **flag)
{
	t_list_flag	*newnode;

	newnode = malloc(sizeof(t_list_flag));
	if (!newnode)
		return;
	ft_bzero(newnode, sizeof(t_list_flag));
	*flag = newnode;
}

void	remove_flag(int *argc, char *argv)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(argv))
	{
		ft_memset(argv, ' ', ft_strlen(argv));
		i++;
	}
	(*argc)--;
}

void	check_flags(char **argv, int *argc, t_list_flag *flag)
{
	int				i;

	i = 1;
	while (argv[i])
	{
		if ((!ft_strcmp(argv[i], "--bench") || !ft_strcmp(argv[i], "\"--bench\"")) && !(flag->bench))
		{
			remove_flag(argc, argv[i]);
			flag->bench = 1;
		}
		else if ((!ft_strcmp(argv[i], "--simple") || !ft_strcmp(argv[i], "\"--simple\"")) && !(flag->mode))
		{
			remove_flag(argc, argv[i]);
			flag->mode = 1;
		}
		else if ((!ft_strcmp(argv[i], "--medium") || !ft_strcmp(argv[i], "\"--medium\"")) && !(flag->mode))
		{
			remove_flag(argc, argv[i]);
			flag->mode = 2;
		}
		else if ((!ft_strcmp(argv[i], "--complex") || !ft_strcmp(argv[i], "\"--complex\"")) && !(flag->mode))
		{
			remove_flag(argc, argv[i]);
			flag->mode = 3;
		}
		else if ((!ft_strcmp(argv[i], "--adaptive") || !ft_strcmp(argv[i], "\"--adaptive\"")) && !(flag->mode))
		{
			remove_flag(argc, argv[i]);
			flag->mode = -1;
		}
		i++;
	}
}
