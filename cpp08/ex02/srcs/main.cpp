/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahguney <ahguney@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:37:11 by ahguney           #+#    #+#             */
/*   Updated: 2023/09/12 17:37:11 by ahguney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "MutantStack.hpp"

int main()
{
	std::cout << "----- test1 -----" << std::endl;
	{
		MutantStack<int> test;
		test.push(20);
		test.push(30);
		std::cout << test.top() << std::endl;
		test.pop();
		std::cout << test.size() << std::endl;
		test.push(40);
		test.push(50);
		test.push(60);
		test.push(70);
		for (MutantStack<int>::iterator it = test.begin(); it != test.end(); ++it)
        	std::cout << *it << std::endl;
	}
    std::cout << "----- test2 -----" << std::endl;
	{
		std::list<int> test2;
		test2.push_front(20);
		test2.push_front(30);
		std::cout << test2.front() << std::endl;
		test2.pop_front();
		std::cout << test2.size() << std::endl;
		test2.push_back(40);
		test2.push_back(50);
		test2.push_back(60);
		test2.push_back(70);
		for (std::list<int>::iterator it=test2.begin(); it != test2.end(); ++it)
			std::cout << *it << std::endl;
	}
    return(0);
}
