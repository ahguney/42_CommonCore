/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahguney <ahguney@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:50:01 by ahguney           #+#    #+#             */
/*   Updated: 2023/01/12 12:50:01 by ahguney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	**ft_free_array(char **array)
{
	int	i;

	if (!array)
		return (NULL);
	i = -1;
	while (array[++i])
	{
		if (array[i])
			array[i] = ft_free(array[i]);
	}
	array = ft_free(array);
	return (NULL);
}
