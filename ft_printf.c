/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catperei <catperei@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 23:16:15 by catperei          #+#    #+#             */
/*   Updated: 2022/05/11 18:57:08 by catperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	convertcharacter(char c, va_list args)
{
	int	result;

	result = 0;
	if (c == 'c')
		result = ft_putchar(va_arg(args, int));
	else if (c == 's')
		result = ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		result = ft_putptr(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		result = ft_putnbr(va_arg(args, int), result);
	else if (c == 'u')
		result = ft_putunbr(va_arg(args, unsigned int), result);
	else if (c == 'x')
		result = ft_puthex(va_arg(args, unsigned int), 0, result);
	else if (c == 'X')
		result = ft_puthex(va_arg(args, unsigned int), 1, result);
	else if (c == '%')
		result = ft_putchar('%');
	else
		result = 0;
	return (result);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		len;

	if (s == NULL)
		return (0);
	va_start(args, s);
	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] != '%')
		{
			len += ft_putchar(s[i++]);
		}
		else
		{
			len += convertcharacter(s[++i], args);
			i++;
		}
	}
	va_end(args);
	return (len);
}

/*int	main(void)
{
	char a = 'a';
	char b = 'b';
	int i = 1234;
	int j = 9876;
	int k = 255;
	char str1[] = "hello";
	char str2[] = "there";

	// OUR TESTS
	ft_printf("Print a char: %c\n", a);
	ft_printf("Print many chars: %c, %c\n", a, b);
	ft_printf("Print a str: %s\n", str1);
	ft_printf("Print many str: %s, %s\n", str1, str2);
	ft_printf("Print a number (d): %d\n", i);
	ft_printf("Print a number (i) : %i\n", i);
	ft_printf("Print many numbers: %d, %i\n", i, j);
	ft_printf("Print a pointer: %p\n", str1);
	ft_printf("Print many pointers: %p, %p\n", str1, str2);
	ft_printf("Print a hex lower: %x\n", k);
	ft_printf("Print a hex upper: %X\n", k);
	ft_printf("Print an unsigned number: %u\n", i);
	ft_printf("Print many unsigned numbers: %u, %u\n\n", i, j);
	
	// OFFICIAL TESTS
	printf("Print a char: %c\n", a);
	printf("Print many chars: %c, %c\n", a, b);
	printf("Print a str: %s\n", str1);
	printf("Print many str: %s, %s\n", str1, str2);
	printf("Print a number (d): %d\n", i);
	printf("Print a number (i) : %i\n", i);
	printf("Print many numbers: %d, %i\n", i, j);
	printf("Print a pointer: %p\n", str1);
	printf("Print many pointers: %p, %p\n", str1, str2);
	printf("Print a hex lower: %x\n", k);
	printf("Print a hex upper: %X\n", k);
	printf("Print an unsigned number: %u\n", i);
	printf("Print many unsigned numbers: %u, %u\n", i, j);
}
*/

