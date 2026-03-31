#include "push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	t_list_flag		*flag;
	//t_list_bench	*metric;
	int				i;
	char			*joint;
	char			*hold;
	char			**temp;
	//t_list_stack	*a;

	i = 1;
	//metric = NULL;
	flag = NULL;
	joint = ft_strdup("");
	if (argc < 2)
		return (0);
	define_flag_struct(&flag);
	check_flags(argv, &argc, flag);
	i = 1;
	while (argv[i])
	{
		hold = joint;
		joint = ft_strjoinspace(hold, argv[i++]);
		free(hold);
	}
	printf("numbers : %s\n", joint);
	printf("bench : %d, mode : %d\n", flag->bench, flag->mode);
	printf("final arg number : %d\n", argc);
	temp = ft_split(joint, ' ');
	check_flags(temp, &argc, flag);
	i = 0;
	while (temp[i])
	{
		printf("%s\n", temp[i]);
		i++;
	}
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
	int	i;

	i = 1;
	while (argv[i])
	{
		if ((!ft_strcmp(argv[i], "--bench") || !ft_strcmp(argv[i], "\"--bench\"")) && !(flag->bench))
		{
			remove_flag(argc, argv[i]);
			flag->bench = 1;
		}
		else if ((!ft_strcmp(argv[i], "--simple") || !ft_strcmp(argv[i], "\"--simple\"")) && !(flag->bench))
		{
			remove_flag(argc, argv[i]);
			flag->mode = 1;
		}
		else if ((!ft_strcmp(argv[i], "--medium") || !ft_strcmp(argv[i], "\"--medium\"")) && !(flag->bench))
		{
			remove_flag(argc, argv[i]);
			flag->mode = 2;
		}
		else if ((!ft_strcmp(argv[i], "--complex") || !ft_strcmp(argv[i], "\"--complex\"")) && !(flag->bench))
		{
			remove_flag(argc, argv[i]);
			flag->mode = 3;
		}
		else if ((!ft_strcmp(argv[i], "--adaptive") || !ft_strcmp(argv[i], "\"--adaptive\"")) && !(flag->bench))
		{
			remove_flag(argc, argv[i]);
			flag->mode = -1;
		}
		/*else
		{
			hold = joint;
			joint = ft_strjoinspace(hold, argv[i]);
			free(hold);
		}*/
		i++;
	}
}
