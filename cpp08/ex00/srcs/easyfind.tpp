/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahguney <ahguney@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:37:47 by ahguney           #+#    #+#             */
/*   Updated: 2023/09/12 17:37:47 by ahguney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "easyfind.hpp"

template<typename T> void easyfind(T &array, int nbr)
{
	typename T::iterator result = std::find(array.begin(), array.end(), nbr);
	if (result != array.end())
	{
		std::cout << "Number " << *result << " Found!" << std::endl;
		return ;
	}
	throw std::invalid_argument ("Not found!");
}