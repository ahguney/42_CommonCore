/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahguney <ahguney@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:50:06 by ahguney           #+#    #+#             */
/*   Updated: 2023/01/12 12:50:06 by ahguney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_trim_token(char *token, char sep)
{
	int		i;

	if (!token)
		return (token);
	i = ft_strlen(token) - 1;
	while (token[i] == sep)
	{
		token[i] = '\0';
		i--;
	}
	while (*token == sep)
		token++;
	return (token);
}
