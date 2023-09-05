/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguney <fguney@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:23:47 by fguney            #+#    #+#             */
/*   Updated: 2023/09/05 17:23:47 by fguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): 
		AForm("RobotomyRequestForm", "Default", false, 72, 45) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src): 
		AForm(src.getName(), 
		src.getTarget(), 
		src.getIsSigned(), 
		src.getGradeToSign(), 
		src.getGradeToExec()) {
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target): 
		AForm("RobotomyRequestForm", target, false, 72, 45) {
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm&) {
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {

	validateExecute(executor);
	std::cout << "ZZZZZZZZZZZZZ crack oups.... ZZZzZZZZZZZZZZZzZZ ok...c'Est bon...ZZZZZzZZZZZZZZZZZZzZZZZZzZZ" << std::endl;
	srand(time(NULL));
	bool rand = (std::rand() % 2);
	if (rand)
		std::cout << getTarget() << " the terminator have been robotomizated" << std::endl;
	else
		std::cout << getTarget() << " robotomization failed" << std::endl;
}
