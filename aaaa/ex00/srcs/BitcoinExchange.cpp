/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahguney <ahguney@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:11:51 by ahguney           #+#    #+#             */
/*   Updated: 2023/09/26 15:06:41 by ahguney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	*this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
	if (this == &copy)
		return (*this);
	return (*this);
}
BitcoinExchange::~BitcoinExchange(void) {}

int BitcoinExchange::opencsv(std::string filename)
{
	std::ifstream rates(filename.c_str());
	if (!rates)
	{
		std::cerr << "Error opening the csv file" << std::endl;
		return 1;
	}
	std::string line;
	while (std::getline(rates, line))
	{
		std::string date;
		float value;
		std::istringstream iss(line);
		if (std::getline(iss, date, ',') && iss >> value)
		{
			_bitcoinPrices[date] = value;
		}
	}
	rates.close();
	return (0);
}

static bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

static int daysInMonth(int year, int month) {
    const int daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month == 2 && isLeapYear(year)) {
        return 29;
    } else {
        return daysPerMonth[month - 1];
    }
}

static int isValidDate(std::string a)
{
	std::string line = a;
	std::string date[3];
	std::string finds = "";
	size_t p = 0;
	int i = 0;

	for(; (p = a.find("-")) != std::string::npos ;i++)
	{
		finds = a.substr(0,p);
		date[i] = finds;
		a.erase(0, p + 1);
	}
	try{
		if (!a.empty()) {
    	    date[i] = a;
   	 	}
		if(std::stoi(date[0]) >= 2023 || std::stoi(date[1]) > 12 || std::stoi(date[2]) > daysInMonth(std::stoi(date[0]),std::stoi(date[1])))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			return 0;
		}
	}
	catch(...)
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return 0;
	}
	return 1;
}

int BitcoinExchange::readinputfile(char *filename)
{
	std::ifstream inputFile(filename);
	if (!inputFile)
	{
		std::cerr << "Error opening the input file" << std::endl;
		return 1;
	}
	inputFile.seekg(0, std::ios::end);
    std::streampos fileSize = inputFile.tellg();
    inputFile.seekg(0, std::ios::beg);

    if (fileSize == 0) {
        std::cerr << "Error: input file is empty." << std::endl;
        inputFile.close();
        return 1;
    }

	std::string line;
	while (std::getline(inputFile, line))
	{
		std::string inputdate;
		float inputvalue;
		std::istringstream iss(line);
        if (line == "date | value")
			continue;
		if ((std::getline(iss, inputdate, '|') && iss >> inputvalue))
		{
			if (inputvalue < 0)
			{
				std::cerr << "Error: not a positive number." << std::endl;
				continue;
			}
			else if (inputvalue >= 1000)
			{
				std::cerr << "Error: too large a number." << std::endl;
				continue;
			}
			if(isValidDate(inputdate))
			{
				std::map<std::string, float>::iterator it = _bitcoinPrices.lower_bound(inputdate);
				if (it == _bitcoinPrices.begin())
					std::cerr << "Error: no data available for date " << inputdate << std::endl;
				else
				{
					--it;
					float bitcoinPrice = it->second;
					float result = inputvalue * bitcoinPrice;
					std::cout << inputdate << " => " << inputvalue << " = " << result << std::endl;
				}
			}
		}
		else
		{
			if (!line.empty() && line[line.size() - 1] == '|') 
				line.erase(line.size() - 1);
			std::cerr << "Error: bad input => " << line << std::endl;
            continue;
		}		
	}
	inputFile.close();
	return (0);
}