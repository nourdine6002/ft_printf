#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_puthex_fd(unsigned int n, int fd)
{
	char	*base;

	base = "0123456789abcdef";
	if (n >= 16)
	{
		ft_puthex_fd(n / 16, fd);
	}
	ft_putchar_fd(base[n % 16], fd);
}
