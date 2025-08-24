#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	arg;

	i = 0;
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'd' || format[i] == 'i')
				ft_putnbr_fd(va_arg(arg, int), 1);
			else if (format[i] == 's')
				ft_putstr_fd(va_arg(arg, char *), 1);
			else if (format[i] == 'x')
				ft_puthex_fd(va_arg(arg, unsigned int), 1);
			else if (format[i] == 'c')
				ft_putchar_fd(va_arg(arg, int), 1);
		}
		else
			ft_putchar_fd(format[i], 1);
		i++;
	}
	va_end(arg);
	return (i);
}
