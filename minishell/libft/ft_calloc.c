/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahguney <ahguney@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:50:00 by ahguney           #+#    #+#             */
/*   Updated: 2023/01/12 12:50:00 by ahguney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	*ft_calloc(size_t nbr, size_t size)

{
	void	*tab;

	tab = malloc(size * nbr);
	if (!tab)
		return (NULL);
	ft_bzero(tab, size * nbr);
	return (tab);
}
