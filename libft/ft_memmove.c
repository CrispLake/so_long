/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 10:34:40 by emajuri           #+#    #+#             */
/*   Updated: 2022/11/09 13:50:21 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dest;
	char	*source;

	if (!dst && !src)
		return (0);
	dest = dst;
	source = (char *)src;
	if (dst < src)
		while (len-- > 0)
			*dest++ = *source++;
	else
		while (len-- > 0)
			dest[len] = source[len];
	return (dst);
}
