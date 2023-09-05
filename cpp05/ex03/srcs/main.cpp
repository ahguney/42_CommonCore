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
#include "Intern.hpp"

int main()
{
	Intern user;
	AForm* newForm;
	newForm = user.makeForm("robotomy request", "ahmet");

	Bureaucrat ned("GUNEY", 20);
	std::cout << ned;
	ned.signForm(*newForm);
	ned.executeForm(*newForm);
	delete newForm;
	std::cout << std::endl;


	newForm = user.makeForm("shrubbery creation", "fahri");
	ned.signForm(*newForm);
	ned.executeForm(*newForm);
	delete newForm;
	std::cout << std::endl;

	newForm = user.makeForm("presidential pardon", "güney");
	ned.signForm(*newForm);
	ned.executeForm(*newForm);
	delete newForm;
	std::cout << std::endl;

	newForm = user.makeForm("furkan", "talha");
	delete newForm;
	
	return 0;
}
