/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahguney <ahguney@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:19:53 by ahguney           #+#    #+#             */
/*   Updated: 2023/09/05 16:19:53 by ahguney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "./ScalarConverter.hpp"


int	main(int ac, char **av)
{
	if (ac != 2){
		std::cout << "Need one argument! example: " << av[0] << " 42.42332f" << std::endl;
		return (1);
	}
	ScalarConverter::convert(av[1]);
}