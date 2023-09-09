/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahguney <ahguney@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:19:25 by ahguney           #+#    #+#             */
/*   Updated: 2023/09/05 16:19:25 by ahguney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"


int main( void )
{
	Data 		a;
	uintptr_t 	b = 0;
	Data 		*c = NULL;

	std::cout << "------------------Making Struct------------------" << std::endl;
	a.content = 42;
	a.string = "Struct is not empty!";
	std::cout << "Data a = " << a.content << "  text = " << a.string << std::endl;
	std::cout << "&a : " << &a << " b : " << b << " ap: " << c << std::endl <<std::endl;

	std::cout << "----------------Put Struct on intPTR-------------" << std::endl;
	b = Serializer::serialize(&a);
	std::cout << "&a : " << &a << " b : " << b << " ap: " << c << std::endl <<std::endl;

	std::cout << "----------------Put inPTR on data PTR------------" << std::endl;
	c = Serializer::deserialize(b);
	std::cout << "Data c = " << c->string << "  text = " << c->content << std::endl;
	std::cout << "&a : " << &a << " b : " << b << " ap: " << c << std::endl <<std::endl;

	return (0);
}
