/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diolivei <diolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:53:32 by diolivei          #+#    #+#             */
/*   Updated: 2024/05/06 19:56:28 by diolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// ********** %c **********
int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

// ********** %s **********
int	ft_putstr(char *s)
{
	int	count;

	count = 0;
	while (*s)
	{
		count += write(1, s, 1);
		s++;
	}
	return (count);
}

// ********** %d or %i **********
int	ft_putnbr(int n, int base)
{
	int	count;

	count = 0;
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

// ********** %u **********
int	ft_putunsigned(unsigned int n, int base)
{
	int	count;

	count = 0;
	if (n <= 9)
		count += ft_putchar(n + '0');
	if (n > 9)
	{
		count += ft_putunsigned(n / base, base);
		count += ft_putunsigned(n % base, base);
	}
	return (count);
}

// ********** %x **********
static int	ft_nbrlen(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		count = 1;
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static char	*ft_strtmp(char *tmp, unsigned int n, int base, int i, char *hexa)
{
	tmp[i] = '\0';
	while (i-- && n != 0)
	{
		tmp[i] = hexa[n % base];
		n = n / base;
	}
	tmp += i + 1;
	return (tmp);
}

int	ft_puthexa(unsigned int n, int base)
{
	int		i;
	int		count;
	char	*tmp;
	char	*tmp_start;
	char	*hexa;

	hexa = "0123456789abcdef";
	count = 0;
	if (n <= 15)
	{
		count += ft_putchar(hexa[n]);
		return (count);
	}
	i = ft_nbrlen(n);
	tmp = (char *)malloc(sizeof(char) * (i + 1));
	if (!tmp)
		return (0);
	tmp_start = tmp;
	tmp = ft_strtmp(tmp, n, base, i, hexa);
	count += ft_putstr(tmp);
	free(tmp_start);
	return (count);
}

// ********** %X **********
static int	ft_toupper(char *tmp)
{
	int	count;

	count = 0;
	while (*tmp)
	{
		if (*tmp >= 'a' && *tmp <= 'z')
		{
			*tmp = *tmp - 32;
			count += write(1, tmp, 1);
		}
		else
			count += write(1, tmp, 1);
		tmp++;
	}
	return (count);
}

int	ft_puthexaupper(unsigned int n, int base)
{
	int		i;
	int		count;
	char	*tmp;
	char	*tmp_start;
	char	*hexa;

	hexa = "0123456789abcdef";
	count = 0;
	if (n <= 15)
	{
		count += ft_putchar(hexa[n]);
		return (count);
	}
	i = ft_nbrlen(n);
	tmp = (char *)malloc(sizeof(char) * (i + 1));
	if (!tmp)
		return (0);
	tmp_start = tmp;
	tmp = ft_strtmp(tmp, n, base, i, hexa);
	count += ft_toupper(tmp);
	free(tmp_start);
	return (count);
}
