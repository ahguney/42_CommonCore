/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahguney <ahguney@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:50:04 by ahguney           #+#    #+#             */
/*   Updated: 2023/01/12 12:50:04 by ahguney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**ft_split(char *src, char sep)
{
	char	**tab;
	int		words;
	int		i;
	int		len;

	words = ft_split_size(src, sep);
	tab = ft_calloc(sizeof(char *), (words + 1));
	i = -1;
	if (!tab)
		return (NULL);
	while (++i < words)
	{
		while (*src && *src == sep)
			src++;
		if (ft_strchr(src, sep))
			len = ft_strchr(src, sep) - src;
		else
			len = ft_strlen(src);
		tab[i] = ft_substr(src, 0, len);
		if (!tab[i])
			return (0);
		src += len;
	}
	return (tab);
}
