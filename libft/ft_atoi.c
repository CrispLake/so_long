/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 20:16:05 by emajuri           #+#    #+#             */
/*   Updated: 2022/10/27 15:24:22 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int		negative;
	long	nb;

	negative = 1;
	nb = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{	
		if (*str == '-')
			negative = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10 + (*str - 48);
		str++;
	}
	nb *= negative;
	if (negative == 1 && nb < 0)
		return (-1);
	else if (negative == -1 && nb > 0)
		return (0);
	return (nb);
}
