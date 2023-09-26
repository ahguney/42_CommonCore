/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahguney <ahguney@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:11:56 by ahguney           #+#    #+#             */
/*   Updated: 2023/09/25 18:11:56 by ahguney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <iomanip>

class BitcoinExchange
{
	private:

		std::map<std::string, float> _bitcoinPrices;

	public:

		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange &operator=(const BitcoinExchange &copy);
		~BitcoinExchange(void);

		int opencsv(std::string filename);
		int readinputfile(char *filename);
};

#endif