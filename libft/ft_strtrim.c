/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 10:45:28 by emajuri           #+#    #+#             */
/*   Updated: 2022/11/04 17:01:32 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		slen;
	char const	*newstr;

	if (!s1 || !set)
		return (0);
	slen = (ft_strlen(s1) + 1);
	newstr = s1 + (slen - 1);
	while (ft_strchr(set, *s1) && (s1 < newstr))
	{
		s1++;
		slen--;
	}
	while (ft_strchr(set, *newstr) && (s1 <= newstr))
	{
		newstr--;
		slen--;
	}
	newstr = malloc((slen + 1) * sizeof(char));
	if (!newstr)
		return (0);
	ft_strlcpy((char *)newstr, s1, (slen + 1));
	return ((char *)newstr);
}
