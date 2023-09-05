/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguney <fguney@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:23:47 by fguney            #+#    #+#             */
/*   Updated: 2023/09/05 17:23:47 by fguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
	this->_form[0] = "presidential pardon";
	this->_form[1] = "robotomy request";
	this->_form[2] = "shrubbery creation";
}

Intern::Intern(const Intern& src) {
	if (&src != this){
		this->_form[0] = src._form[0];
		this->_form[1] = src._form[1];
		this->_form[2] = src._form[2];
	}
}

Intern::~Intern() {}

Intern &Intern::operator=(const Intern& src) {
	if (&src != this){
		this->_form[0] = src._form[0];
		this->_form[1] = src._form[1];
		this->_form[2] = src._form[2];
	}
	return *this;
}

AForm *Intern::makeForm(std::string name, std::string target) {
    for (int i = 0; i < 3; i++) {
        if (name == this->_form[i]) {
            std::cout << "Intern creates " << name << std::endl;
            switch (i) {
                case 0:
                    return new PresidentialPardonForm(target);
                case 1:
                    return new RobotomyRequestForm(target);
                case 2:
                    return new ShrubberyCreationForm(target);
                default:
                    break;
            }
        }
    }
    
    std::cout << "Intern can't create " << name << std::endl;
    return NULL;
}
