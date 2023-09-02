/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahguney <ahguney@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:50:05 by ahguney           #+#    #+#             */
/*   Updated: 2023/01/12 12:50:05 by ahguney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_strdup(const char *src)
{
	char	*tmp;

	if (!src)
		return (NULL);
	tmp = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (tmp == NULL)
		return (0);
	ft_strlcpy(tmp, src, sizeof(char) * (ft_strlen(src) + 1));
	*(tmp + ft_strlen(src)) = '\0';
	return (tmp);
}
