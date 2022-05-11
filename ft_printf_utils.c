/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catperei <catperei@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:45:34 by catperei          #+#    #+#             */
/*   Updated: 2022/04/17 11:01:18 by catperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	if (s)
	{
		write(1, s, ft_strlen(s));
		return (ft_strlen(s));
	}
	else
	{
		write(1, "(null)", 6);
		return (6);
	}
}

int	ft_puthex(size_t dec, int mode, int count)
{
	if (dec < 16)
	{
		if (mode == 0)
			ft_putchar(HEXLOWER[dec]);
		else
			ft_putchar(HEXUPPER[dec]);
		count++;
	}
	else
	{
		count += ft_puthex(dec / 16, mode, count);
		if (mode == 0)
			ft_putchar(HEXLOWER[dec % 16]);
		else
			ft_putchar(HEXUPPER[dec % 16]);
		count++;
	}
	return (count);
}

int	ft_putptr(void *p)
{
	size_t	i;
	int		ct;

	i = (size_t)p;
	ft_putstr("0x");
	ct = 2;
	ct += ft_puthex(i, 0, 0);
	return (ct);
}

int	ft_putnbr(int i, int ret)
{
	if (i == INT_MIN)
	{
		ft_putstr("-2147483648");
		ret = 11;
	}
	else
	{
		if (i < 0)
		{
			ft_putchar('-');
			i *= -1;
			ret++;
		}
		if (i > 9)
		{
			ret += ft_putnbr(i / 10, 0);
		}
		ft_putchar(i % 10 + '0');
		ret++;
	}
	return (ret);
}

/*
int	main(void)
{
	char *s = "hello";
	
	//ft_putchar('a');
	//ft_putstr("hello!");
	//ft_putnbr(-256345);
	ft_putptr(s);
}
*/
