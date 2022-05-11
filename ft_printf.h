/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catperei <catperei@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 22:45:48 by catperei          #+#    #+#             */
/*   Updated: 2022/04/18 23:13:20 by catperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define HEXUPPER "0123456789ABCDEF"
# define HEXLOWER "0123456789abcdef"
# define INT_MIN -2147483648
# define INT_MAX 2147483647
# define LONG_MIN -9223372036854775808
# define LONG_MAX +9223372036854775807
# define UINT_MAX 424967295
# define ULONG_MAX 18446744073709551615

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

/*
** PRINTF
*/

int		ft_print_f(const char *, ...);

/*
** PRINTF UTILS
*/

int		ft_putchar(char c);
int		ft_putstr(char*);
int		ft_puthex(size_t dec, int mode, int count);
int		ft_putptr(void *p);
int		ft_putnbr(int i, int ret);
int 	ft_putunbr(size_t i, int ret);
size_t	ft_strlen(const char *str);

#endif
