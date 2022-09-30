/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils_I.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahguney <ahguney@student.42kocaeli.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 13:46:20 by ahguney           #+#    #+#             */
/*   Updated: 2022/06/04 13:46:33 by ahguney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char	*set_str(int n, int *bas)
{
	char	*str;

	*bas = 1;
	if (n < 0)
	{
		n *= -1;
		(*bas)++;
	}
	while (n >= 10)
	{
		n /= 10;
		(*bas)++;
	}
	str = malloc(sizeof(char) * (*bas + 1));
	if (!str)
		return (NULL);
	str[0] = '-';
	str[(*bas)] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		bas;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = set_str(n, &bas);
	if (n < 0)
		n *= -1;
	if (!str)
		return (NULL);
	while (n >= 10)
	{
		str[--bas] = n % 10 + '0';
		n = n / 10;
	}
	str[--bas] = n % 10 + '0';
	return (str);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

char	*ft_strjoin(char *s1, char const s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	j = 0;
	i = 0;
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(*s1) + (ft_strlen(s1) + 1));
	if (!str)
		return (NULL);
	while (s1[i] != 0)
	{
		str[j++] = s1[i];
		i++;
	}
	str[j++] = s2;
	str[j] = 0;
	return (str);
}
