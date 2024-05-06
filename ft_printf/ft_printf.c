/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diolivei <diolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:59:00 by diolivei          #+#    #+#             */
/*   Updated: 2024/05/06 19:52:22 by diolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_putchar(va_arg(ap, int));
	if (specifier == 's')
		count += ft_putstr(va_arg(ap, char *));
	if (specifier == 'x')
		count += ft_puthexa(va_arg(ap, unsigned int), 16);
	if (specifier == 'X')
		count += ft_puthexaupper(va_arg(ap, unsigned int), 16);
	if (specifier == 'd' || specifier == 'i')
		count += ft_putnbr(va_arg(ap, int), 10);
	if (specifier == 'u')
		count += ft_putunsigned(va_arg(ap, unsigned int), 10);
	if (specifier == '%')
		count += write(1, &specifier, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
			count += ft_format(*(++format), ap);
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (count);
}

/* int main()
{
	int count = 0;
	int mycount = 0;
	ft_printf("------------------------\n");
    count = printf("Original: %p\n", (int *)42);
    mycount = ft_printf("myprintf: %X\n", 42);
	printf("count: %d || my count: %d\n", count, mycount);
	ft_printf("------------------------\n");
    return (0);
} */
