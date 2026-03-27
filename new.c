#include "push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	t_list_flag		*flag;
	//t_list_bench	*metric;
	int				i;
	char			*joint;
	char			*hold;

	i = 1;
	//metric = NULL;
	flag = NULL;
	joint = ft_strdup("");
	if (argc < 2)
		return (0);
	define_flag_struct(&flag);
	while (argv[i] && i < argc)
	{
		if (!ft_strcmp(argv[i], "--bench") || !ft_strcmp(argv[i], "\"--bench\""))
			flag->bench = 1;
		else if (!ft_strcmp(argv[i], "--simple") || !ft_strcmp(argv[i], "\"--simple\""))
			flag->mode = 1;
		else if (!ft_strcmp(argv[i], "--medium") || !ft_strcmp(argv[i], "\"--medium\""))
			flag->mode = 2;
		else if (!ft_strcmp(argv[i], "--complex") || !ft_strcmp(argv[i], "\"--complex\""))
			flag->mode = 3;
		else if (!ft_strcmp(argv[i], "--adaptive") || !ft_strcmp(argv[i], "\"--adaptive\""))
			flag->mode = -1;
		else
		{
			hold = joint;
			joint = ft_strjoinspace(joint, argv[i]);
			free(hold);
		}
		i++;
	}
	printf("numbers : %s\n", joint);
	printf("bench : %d, mode : %d\n", flag->bench, flag->mode);
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
