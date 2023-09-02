/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahguney <ahguney@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:50:02 by ahguney           #+#    #+#             */
/*   Updated: 2023/01/12 12:50:02 by ahguney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_open_fd(char *str, int i)
{
	static int	fd;

	while (str && (str[0] == '>' || str[0] == '<'))
		str++;
	if (i == 1)
		fd = open(str, O_RDONLY, 0644);
	else if (i == 2)
		fd = open(str, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (i == 3)
		fd = open(str, O_RDWR | O_CREAT | O_TRUNC, 0644);
	else if (i == 4)
		fd = open(str, O_RDWR | O_CREAT, 0644);
	else if (i == 5)
		fd = open(str, O_WRONLY | O_CREAT, 0644);
	else if (i == 6)
		fd = open(str, O_RDWR | O_APPEND | O_CREAT, 0644);
	if (fd < 0)
	{
		ft_putstr_fd("minishell: open() error\n", 2);
		return (-1);
	}
	return (fd);
}
