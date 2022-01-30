
#include "push_swap.h"

static int	ft_is_repeat(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_check_args(int argc, char **argv)
{
	int		i;
	long	tmp;	

	i = 0;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (!*argv)
			exit(0);
	}
	else
		i = 1;
	while (argv[i])
	{
		tmp = ft_atoi(argv[i]);
		// if (!ft_isnum(argv[i]))
			// ft_error_msg("Error: Only numbers are allowed!");
		// if (ft_is_repeat(tmp, argv, i))
			// ft_error_msg("Error: Numbers should not be repeated!");
		// if (tmp < INT32_MIN || tmp > INT32_MAX)
			// ft_error_msg("Error: The entered number is too big!");
		i++;
	}
}


int	check_sorted(t_list *stack_a)
{
	int	flag;
	int	length;

	flag = 0;
	length = ft_lstsize(stack_a);
	while (length > 1)
	{
		if (stack_a->num > stack_a->next->next)
			return (1);
		stack_a = stack_a->next;
		length--;
	}
	return (0);
}