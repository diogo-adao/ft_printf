#include "ft_printf.h"

int ft_putchar(int c)
{
	return write(1, &c, 1);
}

int ft_putstr(char *s)
{
	int count;

	count = 0;
	while (*s)
	{
		write(1, s, 1);
		s++;
	}
	return (count);
}

int	ft_putnbr(int n, int base)
{
	int count;

	if (n == -2147483648)
		count += ft_putstr("-2147483648");
	else if (n < 0)
	{
		count += ft_putchar('-');
		n = n * -1;
	}
	if (n >= 0 && n <= 9)
		count += ft_putchar(n + '0');
	if (n > 9)
	{
		count += ft_putnbr(n / base, base);
		count += ft_putnbr(n % base, base);
	}
	return (count);
}

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;
	char	*string;

	i = 0;
	string = (char *)str;
	while (i < n)
	{
		string[i] = c;
		i++;
	}
	return (str);
}