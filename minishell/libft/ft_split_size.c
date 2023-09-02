/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahguney <ahguney@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:50:04 by ahguney           #+#    #+#             */
/*   Updated: 2023/01/12 12:50:04 by ahguney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h" 

int	ft_split_size(char *src, char sep)
{
	int		words;
	int		i;

	i = 0;
	words = 0;
	while (src[i])
	{
		while (src[i] == sep)
			i++;
		if (src[i] != sep && src[i])
			words++;
		while (src[i] != sep && src[i])
			i++;
	}
	return (words);
}
