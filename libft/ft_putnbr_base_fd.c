/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 09:58:30 by emajuri           #+#    #+#             */
/*   Updated: 2022/11/24 14:27:43 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base_fd(int n, int base, int fd)
{
	const char	*str = "0123456789abcdefg";

	if (base < 2 || base > 16)
		return ;
	if (n > (base - 1))
	{
		ft_putnbr_base_fd(n / base, base, fd);
		ft_putnbr_base_fd(n % base, base, fd);
	}
	if (n < (base * -1 + 1))
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_base_fd(n / base * -1, base, fd);
		ft_putnbr_base_fd(n % base * -1, base, fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	if (n <= (base - 1) && n >= 0)
		ft_putchar_fd(str[n], fd);
}
