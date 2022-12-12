/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:51:36 by emajuri           #+#    #+#             */
/*   Updated: 2022/10/31 22:05:30 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*news;
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return (0);
	news = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!news)
		return (0);
	while (*s != 0)
	{
		news[i] = f(i, *s++);
		i++;
	}
	news[i] = 0;
	return (news);
}
