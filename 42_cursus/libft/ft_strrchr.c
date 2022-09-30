/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahguney <ahguney@student.42kocaeli.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 16:03:42 by ahguney           #+#    #+#             */
/*   Updated: 2022/02/09 13:02:45 by ahguney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	const char	t = (char) c;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == t)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}
