/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:45:32 by emajuri           #+#    #+#             */
/*   Updated: 2022/11/04 17:14:06 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	slen;

	if (!s)
		return (0);
	slen = ft_strlen(s);
	if (start >= slen)
		len = 0;
	if (len > slen - start)
	{
		str = malloc((slen - start + 1) * sizeof(char));
		len = slen - start;
	}
	else
		str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	ft_strlcpy(str, (s + start), (len + 1));
	return (str);
}
