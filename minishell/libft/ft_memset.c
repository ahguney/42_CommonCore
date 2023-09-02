/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahguney <ahguney@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:50:02 by ahguney           #+#    #+#             */
/*   Updated: 2023/01/12 12:50:02 by ahguney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	*ft_memset(void *str, int nbr, size_t len)
{
	while (len-- > 0)
		((unsigned char *)str)[len] = (unsigned char)nbr;
	return (str);
}
