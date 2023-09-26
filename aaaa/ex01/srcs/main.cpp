/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahguney <ahguney@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:12:23 by ahguney           #+#    #+#             */
/*   Updated: 2023/09/25 18:12:23 by ahguney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv) 
{
    if (argc != 2) 
	{
        std::cerr << "Wrong arguments" << std::endl;
        return 1;
    }
	try
	{

		std::string expression = argv[1];
		RPN calculator(expression);
		calculator.evaluate();
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
    return 0;
}