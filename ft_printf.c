/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ward <mel-ward@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:34:32 by mel-ward          #+#    #+#             */
/*   Updated: 2023/11/23 18:36:06 by mel-ward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

static int	ft_putstr(char *str)
{
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

static int	putnbr_base(long nb, int base, int alpha)
{
	int				count;
	unsigned long	n;
	char			*str;

	str = "0123456789abcdef";
	count = 0;
	n = nb;
	if (nb < 0 && base <= 10)
	{
		count += ft_putchar('-');
		n = -nb;
	}
	if (n >= (unsigned long)base)
	{
		count += putnbr_base(n / base, base, alpha);
		count += putnbr_base(n % base, base, alpha);
	}
	else
	{
		if (!alpha)
			count += ft_putchar(str[n]);
		else
			count += ft_putchar(ft_toupper(str[n]));
	}
	return (count);
}

static int	ft_flag(va_list ap, char c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (c == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (c == 'p')
	{
		count += ft_putstr("0x");
		count += putnbr_base((unsigned long)va_arg(ap, void *), 16, 0);
	}
	else if (c == 'i' || c == 'd')
		count += putnbr_base(va_arg(ap, int), 10, 0);
	else if (c == 'u')
		count += putnbr_base((unsigned int)va_arg(ap, int), 10, 0);
	else if (c == 'x')
		count += putnbr_base((unsigned int)va_arg(ap, int), 16, 0);
	else if (c == 'X')
		count += putnbr_base((unsigned int)va_arg(ap, int), 16, 1);
	else if (c == '%')
		count += ft_putchar(c);
	else if (c)
		count += ft_putchar(c);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	int		i;
	va_list	ap;

	if (write(1, "", 0) == -1)
		return (-1);
	i = 0;
	count = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%' && str[1 + i])
			count += ft_flag(ap, str[++i]);
		else if (str[i] && str[i] != '%')
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(ap);
	return (count);
}
