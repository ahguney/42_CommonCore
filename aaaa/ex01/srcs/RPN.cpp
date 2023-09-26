/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahguney <ahguney@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:12:30 by ahguney           #+#    #+#             */
/*   Updated: 2023/09/26 14:51:54 by ahguney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void) {}

RPN::~RPN(void) {}

RPN::RPN(std::string &expression) : _expression(expression) {}

RPN::RPN(const RPN &copy)
{
	*this = copy;
}

RPN &RPN::operator=(const RPN &copy)
{
	if (this == &copy)
		return (*this);
	return (*this);
}

void RPN::evaluate() 
{
	std::istringstream iss(_expression);
	std::string token;

	while (iss >> token) 
	{
		if (!isOperator(token)) 
		{
			int num;
			if (token.length() > 1)
				throw std::runtime_error("Error");
			if (std::istringstream(token) >> num && num < 10)
				_numbers.push(num);
			else
				throw std::runtime_error("Error");
		}
		else 
		{
			if (_numbers.size() < 2)
				throw std::runtime_error("Error");  
			int operand2 = _numbers.top();
			_numbers.pop();
			int operand1 = _numbers.top();
			_numbers.pop();

			if (token == "+")
				_numbers.push(operand1 + operand2);
			else if (token == "-")
				_numbers.push(operand1 - operand2);
			else if (token == "*")
				_numbers.push(operand1 * operand2);
			else if (token == "/") 
			{
				if (operand2 == 0)
					throw std::runtime_error("Error");
				_numbers.push(operand1 / operand2);
			}
		}
	}

	if (_numbers.size() != 1)
		throw std::runtime_error("Error");
	std::cout << _numbers.top() << std::endl;
}

bool RPN::isOperator(std::string &token) const 
{
	return (token == "+" || token == "-" || token == "*" || token == "/");
}
