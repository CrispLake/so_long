/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:18:54 by emajuri           #+#    #+#             */
/*   Updated: 2022/10/31 20:29:24 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	sumlen;
	size_t	s1len;
	size_t	s2len;
	char	*s;

	if (!s1 || !s2)
		return (0);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	sumlen = s1len + s2len;
	s = malloc(sumlen * sizeof(char) + 1);
	if (s)
	{
		ft_strlcpy(s, s1, (s1len + 1));
		ft_strlcpy((s + s1len), s2, (s2len + 1));
		return (s);
	}
	return (0);
}
