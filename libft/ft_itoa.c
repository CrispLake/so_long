/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 10:12:38 by emajuri           #+#    #+#             */
/*   Updated: 2022/11/21 12:24:55 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_calc_digits(int n)
{
	int	count;

	count = 2;
	if (n < 0)
		count++;
	while (n > 9 || n < -9)
	{
		count++;
		n /= 10;
	}
	return (count);
}

static	void	ft_terminator(char *s, int check)
{
	if (check)
		*s++ = '-';
	*s = 0;
}

char	*ft_itoa(int n)
{
	char	*s;
	char	*save;
	int		check;

	check = 0;
	s = malloc(ft_calc_digits(n) * sizeof(char));
	if (!s)
		return (0);
	save = s;
	if (n == 0)
		*s++ = '0';
	if (n < 0)
	{
		check = 1;
		*s++ = ((n % 10) * -1) + '0';
		n /= -10;
	}
	while (n > 0)
	{
		*s++ = (n % 10) + '0';
		n /= 10;
	}
	ft_terminator(s, check);
	return (ft_strrev(save));
}
