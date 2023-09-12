/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahguney <ahguney@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:37:33 by ahguney           #+#    #+#             */
/*   Updated: 2023/09/12 17:37:33 by ahguney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Span.hpp"
#include <ctime>

int main( void )
{
	srand (time(NULL));

	std::cout << "----- Test #1 -----" << std::endl;
	Span sp = Span(10000);
	
  	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(15);
	sp.addRandom();
 	try {
		sp.addNumber(34);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		sp.shortestSpan();
		sp.longestSpan();
	}
	catch (std::exception &e) { 
		std::cout << e.what() << std::endl;
		return (0);
	}
	std::cout << "Shortest difference: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest difference: " << sp.longestSpan() << std::endl;

	return (0);
}
