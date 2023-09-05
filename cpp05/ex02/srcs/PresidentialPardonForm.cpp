/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguney <fguney@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:23:47 by fguney            #+#    #+#             */
/*   Updated: 2023/09/05 17:23:47 by fguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : 
		AForm("PresidentialPardonForm", "Default", false, 25, 5) {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) : 
		AForm(src.getName(), 
		src.getTarget(), 
		src.getIsSigned(), 
		src.getGradeToSign(), 
		src.getGradeToExec()) {
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target): 
		AForm("PresidentialPardonForm", target, false, 25, 5) {
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm&) {
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & user) const {
	validateExecute(user);
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
