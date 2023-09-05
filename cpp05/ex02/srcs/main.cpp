/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguney <fguney@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:23:47 by fguney            #+#    #+#             */
/*   Updated: 2023/09/05 17:23:47 by fguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::cout << "-----------------ShrubberyCreationForm-----------------" << std::endl;
	Bureaucrat dixie("ahmet", 20);
	ShrubberyCreationForm form1("Christmas tree");
	std::cout << dixie;
	dixie.signForm(form1);
	dixie.executeForm(form1);
	std::cout << std::endl;

	std::cout << "-----------------RobotomyRequestForm-----------------" << std::endl;
	Bureaucrat lala("fahri", 46);
	RobotomyRequestForm form2("form2");
	std::cout << lala;
	lala.signForm(form2);
	lala.executeForm(form2);
	dixie.executeForm(form2);
	std::cout << std::endl;

	std::cout << "-----------------PresidentialPardonForm-----------------" << std::endl;
	Bureaucrat tinky("güney", 2);
	PresidentialPardonForm form3("form3");
	std::cout << tinky;
	lala.signForm(form3);
	tinky.signForm(form3);
	tinky.executeForm(form3);
	
	return 0;
}
