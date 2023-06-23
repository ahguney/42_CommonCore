/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getops.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facar <facar@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:52:37 by facar             #+#    #+#             */
/*   Updated: 2023/06/23 16:52:39 by facar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.hpp"
#include <iostream>

std::vector<std::string> getops()
{
	std::vector<std::string> ret;
	std::cout << "Do you want to enter op? (y/n) :";
	std::string op;
	std::cin >> op;
	if (!(op == "y"))
		return ret;
	while (op == "y") {
		std::cout << "Enter op(nickname): ";
		std::cin >> op;
		ret.push_back(op);
		std::cout << "Do you want to enter another op? (y/n) :";
		std::cin >> op;
	}
	return ret;
}
