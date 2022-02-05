
#include "push_swap.h"

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
		if (!ft_isnum(argv[i]))
			ft_error_msg("Error: Only numbers are allowed!");
		if (ft_is_repeat(tmp, argv, i))
			ft_error_msg("Error: Numbers should not be repeated!");
		if (tmp < INT32_MIN || tmp > INT32_MAX)
			ft_error_msg("Error: The entered number is too big!");
		i++;
	}
	if (argc == 2)
		ft_free(argv);
}