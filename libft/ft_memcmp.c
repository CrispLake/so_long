/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:29:21 by emajuri           #+#    #+#             */
/*   Updated: 2022/11/01 14:05:48 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*str1;
	char	*str2;

	if (n == 0)
		return (0);
	str1 = (char *)s1;
	str2 = (char *)s2;
	while ((unsigned char)*str1 == (unsigned char)*str2 && n > 1)
	{
		str1++;
		str2++;
		n--;
	}
	return ((unsigned char)*str1 - (unsigned char)*str2);
}
