/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguney <fguney@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:23:47 by fguney            #+#    #+#             */
/*   Updated: 2023/09/05 17:23:47 by fguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

const char* AForm::GradeTooHighException::what() const throw() {
	return "Grade too High.";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Grade too Low.";
}

const char* AForm::FormIsNotSignException::what() const throw() {
	return "The form is not signed.";
}

AForm::AForm(): 
	_name("Default"), 
	_target("Default"),
	 _isSigned(false), 
	 _gradeToSign(150),
	  _gradeToExec(150) {
}

AForm::AForm(const AForm& src): 
	_name(src._name), 
	_target(src._target), 
	_isSigned(src._isSigned), 
	_gradeToSign(src._gradeToSign), 
	_gradeToExec(src._gradeToExec) {
}

AForm::AForm(const std::string name, const std::string target, bool isSigned, const int gradeToSign, const int gradeToExec):
	_name(name), 
	_target(target), 
	_isSigned(isSigned),
	_gradeToSign(gradeToSign),
	_gradeToExec(gradeToExec) {
}

AForm::~AForm() {}

AForm& AForm::operator=(const AForm& src) 
{
	if (&src != this){
		_isSigned=src._isSigned;
	}
	return *this;
}

std::string AForm::getName() const {
	return _name;
}

bool AForm::getIsSigned() const {
	return _isSigned;
}

int AForm::getGradeToSign() const {
	return _gradeToSign;
}

int AForm::getGradeToExec() const {
	return _gradeToExec;
}

std::string AForm::getTarget() const {
	return _target;
}

void AForm::validateExecute(Bureaucrat const & user) const {
	if (!getIsSigned())
		throw FormIsNotSignException();
	else if (user.getGrade() > getGradeToExec())
		throw GradeTooLowException();
}

void AForm::beSigned(const Bureaucrat& b){
	if (b.getGrade() <= _gradeToSign)
		_isSigned = true;
	else
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& out, const AForm& doc) {
	out << "AForm \"" << doc.getName();
	if (doc.getIsSigned())
		std::cout << "\" is signed.";
	else
		std::cout << "\" is not signed.";
	std::cout << " Required grade to sign is " << doc.getGradeToSign() 
	<< " and to execute is " << doc.getGradeToExec() << "." << std::endl;
		
	return out;
}

void AForm::checkGrade() const {
	if (_gradeToExec > 150)
		throw GradeTooLowException();
	else if (_gradeToExec < 1)
		throw GradeTooHighException();

	if (_gradeToSign > 150)
		throw GradeTooLowException();
	else if (_gradeToSign < 1)
		throw GradeTooHighException();
}
