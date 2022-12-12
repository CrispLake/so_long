/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:56:23 by emajuri           #+#    #+#             */
/*   Updated: 2022/12/05 13:31:04 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_len(unsigned long long n, int base)
{
	size_t	count;

	count = 1;
	while (n > (unsigned long long)(base - 1))
	{
		count++;
		n /= base;
	}
	return (count);
}

char	*ft_ulltoa_base(unsigned long long n, int base)
{
	const char	*chars = "0123456789abcdef";
	char		*new;
	size_t		i;

	i = 0;
	if (base < 2 || base > 16)
		return (NULL);
	new = malloc((count_len(n, base) + 1) * sizeof(char));
	if (!new)
		return (NULL);
	if (n == 0)
		new[i++] = chars[0];
	while (n)
	{
		new[i++] = chars[(n % base)];
		n /= base;
	}
	new[i] = '\0';
	ft_strrev(new);
	return (new);
}
