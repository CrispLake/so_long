/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:20:21 by emajuri           #+#    #+#             */
/*   Updated: 2022/11/21 12:00:26 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *src)
{
	char	tmp;
	size_t	i;
	size_t	i2;

	i = 0;
	i2 = ft_strlen(src) - 1;
	while (i < i2)
	{
		tmp = src[i];
		src[i++] = src[i2];
		src[i2--] = tmp;
	}
	return (src);
}
