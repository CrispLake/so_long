/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 09:58:30 by emajuri           #+#    #+#             */
/*   Updated: 2022/11/02 12:48:01 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{	
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	if (n < -9)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(n / 10 * -1, fd);
		ft_putnbr_fd(n % 10 * -1, fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	if (n <= 9 && n >= 0)
		ft_putchar_fd(n + '0', fd);
}
