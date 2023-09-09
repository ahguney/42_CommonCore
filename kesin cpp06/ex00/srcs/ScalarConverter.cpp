/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahguney <ahguney@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:19:59 by ahguney           #+#    #+#             */
/*   Updated: 2023/09/05 16:19:59 by ahguney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(int a)
{
	std::cout << "Private Constructor" << a << std::endl;
}

ScalarConverter::ScalarConverter(std::string const& _str){
}

ScalarConverter::ScalarConverter(ScalarConverter const& src) {
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &op) {
	(void) op;
	return *this;
}

ScalarConverter::~ScalarConverter(){
}

int ScalarConverter::finds(const std::string& str,std::string key) {
    size_t found = str.find(key);
    return (found != std::string::npos) ? 1 : 0;
}

double ScalarConverter::check(std::string &str,bool &isNumber)
{
	if(str.length() == 1 && str[0] != '0')
	{
		isNumber = true;
		return static_cast<int>(str[0]);
	}
	return 0;
}

void	ScalarConverter::detectType(std::string	const &str,long double &nbr,bool &isNumber){
	std::string tmp;
	if(finds(str,"nan") || finds(str,"nanf"))
	{
			isNumber = false;
			return ;
	}
	if(str[str.length() - 1] != 'f')
	{
		std::stringstream ss;
		tmp = str;
		ss << tmp;
		nbr = check(tmp,isNumber);

		if(isNumber == true)
			return;
		ss >> nbr;
		ss.fail() ? isNumber = false : isNumber = true;

		
	}
	else if(str[str.length() - 1] == 'f' || finds(str,"."))
	{
		std::stringstream ss;
		tmp = str;
		if(str.length() == 1 && str == "f")
		{
			isNumber = true;
			nbr = check(tmp,isNumber);
			return;
		}
		else
			tmp[str.length() - 1] = '\0';
		ss << tmp;
		ss >> nbr;
		ss.fail() ? isNumber = false : isNumber = true;
	}
}

void ScalarConverter::convert(std::string a)
{
	std::string			str;
	long double			nbr;
	bool				isNumber;
	str = a;
	isNumber = false;
	ScalarConverter::detectType(str,nbr,isNumber);
	bool flag = 0;
	if (nbr > 32 && nbr <= 126)
	std::cout << "char : '" << static_cast<char>(nbr) << '\''<< std::endl ;
	else if (nbr <= 127 || nbr <= 32)
	std::cout << "char : Non displayable" << std::endl;
	else if (nbr >= 128 || !isNumber)
	std::cout << "char : Impossible" << std::endl;
	if (nbr >= -2147483647 && nbr <= 2147483648  && isNumber)
	{
		std::cout << "int: " << static_cast<int>(nbr)  << std::endl;
	}
	else
		std::cout << "int: impossible" << std::endl,flag = true;
	if (isNumber){
		std::cout << "float: " <<  static_cast<float>(nbr)  << ((static_cast<float>(nbr) - static_cast<int>(nbr) == 0) ? ".0" : "") << "f" << std::endl;
		std::cout << "double: " <<  static_cast<double>(nbr)  << ((static_cast<double>(nbr) - static_cast<int>(nbr) == 0) ? ".0" : "") << std::endl;
		return;
	}
	if(flag != true)
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
}
