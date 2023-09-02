/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahguney <ahguney@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:50:03 by ahguney           #+#    #+#             */
/*   Updated: 2023/01/12 12:50:03 by ahguney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_pipe_check(char *buf)
{
	char	*tmp;

	tmp = buf;
	if (buf[0] == '|' || buf[ft_strlen(buf) - 1] == '|')
	{
		ft_putstr_fd("minishell: syntax error\n", 2);
		return (1);
	}
	while (*tmp)
	{
		if (*tmp == '|' && *(tmp + 1) == '|')
		{
			*tmp = '\0';
			return (0);
		}
		if (*tmp == '|' && ft_is_only(tmp + 1, ' '))
		{
			ft_putstr_fd("minishell: syntax error\n", 2);
			return (1);
		}
		tmp++;
	}
	return (0);
}
