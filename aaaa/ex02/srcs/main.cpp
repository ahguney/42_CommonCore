/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahguney <ahguney@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:12:55 by ahguney           #+#    #+#             */
/*   Updated: 2023/09/26 14:54:47 by ahguney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static int isChar(char *str)
{
	int i = 0;

	while(str[i] <= 32)
	i++;
	if (str[i] >= '0' && str[i] <= '9')
	{
		while (str[i] != 0)
		{
			if (!(str[i] >= '0' && str[i] <= '9') && str[i] != ' ')	
				return 1;
				i++;
		}
	}
	else
		return 1;
	
	return 0;
}

int main(int argc, char **argv)
{
    if (argc < 2) 
	{
        std::cerr << "Error: Wrong arguments" << std::endl;
        return 1;
    }
	std::vector<int> input;
    for (int i = 1; i < argc; i++)
	{
        int num = std::atoi(argv[i]);
		if (num < 0)
		{
			std::cerr << "Error" << std::endl;
			return (1);
		}
		if (isChar(argv[i]) == 1)
		{
			std::cerr << "Error" << std::endl;
			return (1);
		}
		else if (num == 0 && *argv[i] != '0')
		{
			std::cerr << "Error" << std::endl;
			return (1);
		}
        input.push_back(num);
    }
	try
	{
		Pmerge sorter(input);
		sorter.result();
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
    return 0;
}