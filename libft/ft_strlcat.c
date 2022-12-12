/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:08:00 by emajuri           #+#    #+#             */
/*   Updated: 2022/11/02 13:21:56 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	rval;
	size_t	dlen;
	size_t	slen;

	if (!dst && dstsize == 0)
		return (0);
	slen = ft_strlen(src);
	dlen = ft_strlen(dst);
	rval = dlen + slen;
	if (dstsize > dlen)
	{
		dst += dlen;
		dstsize = dstsize - dlen - 1;
		while (dstsize > 0 && slen > 0)
		{
			*dst++ = *src++;
			dstsize--;
			slen--;
		}
		*dst = 0;
		return (rval);
	}
	else
		return (dstsize + slen);
}
