/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahguney <ahguney@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:12:09 by ahguney           #+#    #+#             */
/*   Updated: 2023/09/26 14:56:54 by ahguney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	(void)argv;
	if (argc == 2)
	{
		BitcoinExchange btc;
		btc.opencsv("data.csv");
		btc.readinputfile(argv[1]);
		return (0);
	}
	std::cerr << "Error: could not open file." << std::endl;
	return (1);
}