/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahguney <ahguney@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:20:02 by ahguney           #+#    #+#             */
/*   Updated: 2023/09/05 16:20:02 by ahguney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

# include <iostream>
# include <sstream>

class ScalarConverter
{
	public:
		ScalarConverter&	operator=(const ScalarConverter &);
		static void				convert(std::string);
		static void				detectType(std::string	const &,long double &,bool &);
		static double 			check(std::string &,bool &);
		static int 				finds(const std::string& ,std::string);

	private:
		ScalarConverter(int a);
		ScalarConverter(std::string const&);
		ScalarConverter(ScalarConverter const&);
		~ScalarConverter();

};

#endif
