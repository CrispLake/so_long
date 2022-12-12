/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:49:57 by emajuri           #+#    #+#             */
/*   Updated: 2022/11/17 13:37:34 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	if (s)
		return (NULL);
	while (n-- > 0)
		if (*(const unsigned char *)s++ == (unsigned char)c)
			return ((void *)--s);
	return (NULL);
}
