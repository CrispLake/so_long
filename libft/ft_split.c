/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:10:03 by emajuri           #+#    #+#             */
/*   Updated: 2022/11/03 18:51:05 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_word_count(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != 0)
	{
		while (s[i] == c && s[i] != 0)
		{
			i++;
			if (s[i] == 0)
				count--;
		}
		while (s[i] != c && s[i] != 0)
			i++;
		count++;
	}
	return (count);
}

static	void	ft_copystrings(char const *s, char **strings, char c)
{
	size_t	i1;
	size_t	i2;
	size_t	i3;
	size_t	check;

	check = 1;
	i1 = 0;
	i2 = 0;
	while (s[i1] != 0)
	{
		i3 = 0;
		while (s[i1] == c && s[i1] != 0)
		{
			i1++;
			if (s[i1] == 0)
				check = 0;
		}
		while (s[i1] != c && s[i1] != 0)
			strings[i2][i3++] = s[i1++];
		if (check)
			strings[i2][i3] = 0;
		i2++;
	}
}

static	int	ft_malloc_strings(char const *s, char c, char **strs, size_t count)
{
	size_t	i1;
	size_t	i2;
	size_t	count2;

	i1 = 0;
	i2 = 0;
	while (count > 0)
	{
		count2 = 0;
		while (s[i1] == c && s[i1] != 0)
			i1++;
		while (s[i1] != c && s[i1++] != 0)
			count2++;
		strs[i2] = malloc((count2 + 1) * sizeof(char));
		if (!strs[i2])
		{
			while (i2--)
				free(strs[i2]);
			return (1);
		}
		i2++;
		count--;
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**strings;
	size_t	count;
	size_t	check;

	if (!s)
		return (0);
	count = ft_word_count(s, c);
	strings = malloc((count + 1) * sizeof(char *));
	if (!strings)
		return (0);
	strings[count] = 0;
	check = ft_malloc_strings(s, c, strings, count);
	if (check)
	{
		free(strings);
		return (0);
	}
	ft_copystrings(s, strings, c);
	return ((char **)strings);
}
