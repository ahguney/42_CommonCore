/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_only.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahguney <ahguney@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:50:01 by ahguney           #+#    #+#             */
/*   Updated: 2023/01/12 12:50:01 by ahguney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

bool	ft_is_only(char *buffer, char c)
{
	int	i;

	i = 0;
	if (!buffer)
		return (false);
	while (buffer[i] != '\0')
	{
		if (buffer[i] != c)
			return (false);
		i++;
	}
	return (true);
}
