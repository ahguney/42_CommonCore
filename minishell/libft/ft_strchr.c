/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahguney <ahguney@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:50:04 by ahguney           #+#    #+#             */
/*   Updated: 2023/01/12 12:50:04 by ahguney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_strchr(const char *str, int nbr)
{
	int	i;
	int	len;

	if (!str)
		return (NULL);
	i = -1;
	len = ft_strlen(str);
	while (++i < len + 1)
		if (str[i] == (char)nbr)
			return ((char *)str + i);
	return (NULL);
}
