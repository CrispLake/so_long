/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:13:18 by emajuri           #+#    #+#             */
/*   Updated: 2023/01/11 17:18:11 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include <unistd.h>

static int	putull_base_count(unsigned long long n, int base, int caps)
{
	const char	*str = "0123456789abcdef0123456789ABCDEF";
	int			count;

	if (caps)
		str += 16;
	count = 0;
	if (base < 2 || base > 16)
		return (0);
	if (n > (unsigned int)(base - 1))
	{
		count += putull_base_count(n / base, base, caps);
		count += putull_base_count(n % base, base, caps);
	}
	if (n <= (unsigned int)(base - 1) && n >= 0)
	{
		ft_putchar_fd(str[n], 1);
		return (++count);
	}
	return (count);
}

static int	putnbr_base_count(int n, int base, char *str)
{
	long	nb;
	int		count;

	count = 1;
	nb = n;
	if (nb < 0)
	{
		count++;
		ft_putchar_fd('-', 1);
		nb = nb * -1;
	}
	if (nb >= base)
	{
		count += putnbr_base_count(nb / base, base, str);
		ft_putchar_fd(str[nb % base], 1);
		return (count);
	}
	if (nb < base)
	{
		ft_putchar_fd(str[nb % base], 1);
		return (count);
	}
	return (0);
}

static int	convert2(const char *str, va_list ap)
{
	int	len;

	len = 1;
	if (*str == 'p')
	{
		write(1, "0x", 2);
		len += 1;
		len += putull_base_count((unsigned long long)va_arg(ap, char *), 16, 0);
	}
	else if (*str == 'd' || *str == 'i')
		len = putnbr_base_count(va_arg(ap, int), 10, "0123456789abcdef");
	else if (*str == 'u')
		len = putull_base_count(va_arg(ap, unsigned int), 10, 0);
	else if (*str == 'x')
		len = putull_base_count(va_arg(ap, unsigned int), 16, 0);
	else if (*str == 'X')
		len = putull_base_count(va_arg(ap, unsigned int), 16, 1);
	else if (*str == '%')
		ft_putchar_fd('%', 1);
	return (len);
}

static int	convert(const char *str, va_list ap)
{
	int		len;
	char	*tmp;

	len = 1;
	if (*str == 'c')
		ft_putchar_fd(va_arg(ap, int), 1);
	else if (*str == 's')
	{
		tmp = va_arg(ap, char *);
		if (!tmp)
		{
			write(1, "(null)", 6);
			len = 6;
		}
		else
		{
			len = ft_strlen(tmp);
			ft_putstr_fd(tmp, 1);
		}
	}
	else
		return (convert2(str, ap));
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		len;

	len = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			len += convert(str, ap);
			if (*str)
				str++;
		}
		else
		{
			ft_putchar_fd(*str, 1);
			str++;
			len++;
		}
	}
	va_end(ap);
	return (len);
}
