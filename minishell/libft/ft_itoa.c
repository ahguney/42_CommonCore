/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahguney <ahguney@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:50:02 by ahguney           #+#    #+#             */
/*   Updated: 2023/01/12 12:50:02 by ahguney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	ft_intlen(int nbr)
{
	int	i;

	if (nbr == 0)
		return (1);
	i = 0;
	if (nbr < 0)
		i++;
	while (nbr)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nbr)
{
	char	*temp;
	int		i;
	int		sign;

	i = ft_intlen(nbr);
	temp = ft_calloc(ft_intlen(nbr) + 1, sizeof(char));
	if (!temp)
		return (NULL);
	if (nbr == -2147483648)
		return (ft_memcpy(temp, "-2147483648", 11));
	sign = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		sign = 1;
	}
	while (--i >= 0)
	{
		temp[i] = nbr % 10 + '0';
		nbr /= 10;
		if (i == 0 && sign == 1)
			temp[i] = '-';
	}
	return (temp);
}
