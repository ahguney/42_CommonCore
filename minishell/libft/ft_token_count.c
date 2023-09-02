/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahguney <ahguney@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:50:06 by ahguney           #+#    #+#             */
/*   Updated: 2023/01/12 12:50:06 by ahguney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_token_count(char *buffer, char sep)
{
	char	*tmp;
	char	*token;
	int		i;

	i = 0;
	tmp = ft_strdup(buffer);
	token = ft_trim_token(ft_strtok(tmp, sep), ' ');
	while (token)
	{
		i++;
		token = ft_trim_token(ft_strtok(NULL, sep), ' ');
	}
	free(tmp);
	return (i);
}
