/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahguney <ahguney@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:50:02 by ahguney           #+#    #+#             */
/*   Updated: 2023/01/12 12:50:02 by ahguney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_isalpha(int nbr)
{
	if ((nbr >= 'a' && nbr <= 'z') || (nbr >= 'A' && nbr <= 'Z'))
		return (1);
	return (0);
}