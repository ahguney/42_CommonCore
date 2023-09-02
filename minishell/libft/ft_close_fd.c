/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahguney <ahguney@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:50:01 by ahguney           #+#    #+#             */
/*   Updated: 2023/01/12 12:50:01 by ahguney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_close_fd(int fd)
{
	if (fd > 2)
	{
		close(fd);
		return (-1);
	}
	return (fd);
}
