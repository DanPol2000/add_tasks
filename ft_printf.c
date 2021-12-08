
#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
    va_list args;
    int i;
    int cnt;

    i = 0;
	cnt = 0;
	if (str == NULL)
		return (-1);
    va_start(args, str);
    while (str[i])
    {
		if (str[i] != '%' && str[i])
		{
			ft_putchar_fd()
			cnt++;
		}
		if (!str[i])
			return (count);
        if (str[i] == '%' && ft_strchr("cspdiuxX%", str[i + 1]))
            cnt += ft_flag(args)
        i++;
    }
    va_end(args);
    return (cnt);
}

int	ft_flag(va_list argv)
{
	int		size;
	char	*tmp;

	tmp = ft_itoa(va_arg(argv, int));
	ft_putstr_fd(tmp, 1);
	size = ft_strlen(tmp);
	free(tmp);
	return (size);
}
