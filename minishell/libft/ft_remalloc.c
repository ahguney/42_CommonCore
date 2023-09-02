/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahguney <ahguney@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:50:03 by ahguney           #+#    #+#             */
/*   Updated: 2023/01/12 12:50:03 by ahguney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**ft_remalloc(char **old, int size, int f)
{
	char	**new;
	int		i;

	if (old == NULL)
		return (NULL);
	new = ft_calloc(sizeof(char *), (ft_array_size(old) + size));
	if (!new)
		return (NULL);
	i = -1;
	while (old[++i])
		new[i] = ft_strdup(old[i]);
	if (f == 1)
		ft_free_array(old);
	return (new);
}
