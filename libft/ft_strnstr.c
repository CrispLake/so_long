/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 19:48:45 by emajuri           #+#    #+#             */
/*   Updated: 2022/11/01 13:30:41 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	nlen;

	nlen = ft_strlen(needle);
	if (*needle && len == 0)
		return (0);
	if (*needle && len != 0)
	{
		while (*haystack != 0 && len > 0)
		{
			if (ft_strncmp(haystack, needle, nlen) == 0 && (nlen <= len))
				return ((char *)haystack);
			haystack++;
			len--;
		}
		return (0);
	}
	return ((char *)haystack);
}
