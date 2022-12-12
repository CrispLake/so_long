/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:12:45 by emajuri           #+#    #+#             */
/*   Updated: 2022/11/21 12:48:45 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	slen;

	slen = ft_strlen(s1);
	ptr = malloc((slen + 1) * sizeof(char));
	if (ptr)
	{
		ft_strlcpy(ptr, s1, slen + 1);
		return (ptr);
	}
	return (NULL);
}
