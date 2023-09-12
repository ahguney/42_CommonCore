/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahguney <ahguney@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:37:18 by ahguney           #+#    #+#             */
/*   Updated: 2023/09/12 17:37:18 by ahguney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <iterator>
# include <algorithm>
# include <list>

class Span
{
	public:

		class maxNumberException : public std::exception {
			const char* what() const throw();
		};

		class lessNumberException : public std::exception {
			const char* what() const throw();
		};

		class noDiffException : public std::exception {
			const char* what() const throw();
		};

		Span();
		Span(unsigned int const);
		Span(Span const&);
		~Span();
		Span& operator=(Span const&);
	
		void				addNumber(int);
		int					shortestSpan();
		int					longestSpan();
		void				addRandom();
		void				rangeNumber(std::vector<int>::iterator, std::vector<int>::iterator);

	private:

		unsigned int		_max;
		std::vector<int>		_n;
};

#endif
