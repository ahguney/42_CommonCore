/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahguney <ahguney@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:37:24 by ahguney           #+#    #+#             */
/*   Updated: 2023/09/12 17:37:24 by ahguney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Span.hpp"

Span::Span() : _max(0) {}

Span::Span(unsigned int const n) : _max(n) {}

Span::Span(Span const& cpy) : _max(cpy._max), _n(cpy._n){}

Span& Span::operator=(Span const& cpy) {
	this->_max = cpy._max;
	this->_n = cpy._n;
	return (*this);
}

Span::~Span() {}

void	Span::addNumber(int n) {
	if (_n.size() >= _max)
		throw Span::maxNumberException();
	_n.push_back(n);
}

void	Span::addRandom() {
	for (unsigned int i = this->_n.size(); i !=  _max; i++)
		this->addNumber(rand());
}

void	Span::rangeNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	for (; begin != end; ++begin) {
	 	try { 
			this->addNumber(*begin);
		}
		catch (std::exception &e) { 
			std::cout << e.what() << std::endl;
			return ;
		}
	}
}

int Span::shortestSpan(void)
{
	if (_n.size() <= 1)
		throw Span::lessNumberException();
	std::vector<int> sortedNumbers = _n;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());
	int diff = std::numeric_limits<int>::max();
	for (size_t i = 1; i < sortedNumbers.size(); i++)
	{
		if ((sortedNumbers[i] - sortedNumbers[i - 1]) < diff)
			diff = (sortedNumbers[i] - sortedNumbers[i - 1]);
	}
	if (diff == 0)
		throw Span::noDiffException();
	return (diff);
}

int		Span::longestSpan() {
	int max = *std::max_element(this->_n.begin(), this->_n.end());
	int min = *std::min_element(this->_n.begin(), this->_n.end());
	return (std::abs(max-min));
}

const char* Span::maxNumberException::what() const throw() {
	return ("Too many number in vector to add more...");
}

const char* Span::lessNumberException::what() const throw() {
	return ("To less number in vector to search the sortest! Need minimum 2 number in vector");
}

const char* Span::noDiffException::what() const throw() {
	return ("No diff between all number!");
}