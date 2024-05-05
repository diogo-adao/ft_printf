/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diolivei <diolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:49:37 by diolivei          #+#    #+#             */
/*   Updated: 2024/05/03 18:01:31 by diolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "ft_printf_utils.c"

int	    ft_printf(const char *format, ...);
int     ft_putchar(int c);
int     ft_putstr(char *s);
int     ft_putnbr(int n, int base);
void	*ft_memset(void *str, int c, size_t n);

#endif
