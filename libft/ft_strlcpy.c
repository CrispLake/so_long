/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:41:04 by emajuri           #+#    #+#             */
/*   Updated: 2022/10/31 19:16:58 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	slen;

	slen = ft_strlen(src);
	if (dstsize == 0)
		return (slen);
	while (dstsize-- > 1 && *src != 0)
		*dst++ = *src++;
	*dst = 0;
	return (slen);
}
