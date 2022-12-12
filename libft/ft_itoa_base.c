/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:34:32 by emajuri           #+#    #+#             */
/*   Updated: 2022/11/21 12:50:35 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_len(int n, int base)
{
	size_t	count;

	count = 1;
	if (n < 0)
		count++;
	while (n > (base - 1) || n < (base * -1 + 1))
	{
		count++;
		n /= base;
	}
	return (count);
}

static void	make_string(int n, int base, char *new, char *chars)
{
	long	nb;
	int		is_negative;
	size_t	i;

	is_negative = 0;
	i = 0;
	nb = n;
	if (nb == 0)
		new[i++] = chars[0];
	else if (nb < 0)
	{
		is_negative = 1;
		nb *= -1;
	}
	while (nb)
	{
		new[i++] = chars[(nb % base)];
		nb /= base;
	}
	if (is_negative)
		new[i++] = '-';
	new[i] = '\0';
}

char	*ft_itoa_base(int n, int base)
{
	static char	*chars = "0123456789abcdef";
	char		*new;

	if (base < 2 || base > 16)
		return (NULL);
	new = malloc((count_len(n, base) + 1) * sizeof(char));
	if (!new)
		return (NULL);
	make_string(n, base, new, chars);
	ft_strrev(new);
	return (new);
}
