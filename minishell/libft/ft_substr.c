/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahguney <ahguney@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:50:06 by ahguney           #+#    #+#             */
/*   Updated: 2023/01/12 12:50:06 by ahguney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_substr(char const *src, unsigned int start, size_t len)
{
	size_t			i;
	size_t			slen;
	char			*tmp;

	if (!src)
		return (NULL);
	slen = ft_strlen(src);
	if (start > slen)
		return (NULL);
	tmp = malloc((len + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	i = 0;
	while (i < len)
	{
		tmp[i] = src[start + i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
