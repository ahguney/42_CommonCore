/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguney <fguney@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:23:46 by fguney            #+#    #+#             */
/*   Updated: 2023/09/05 17:23:46 by fguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

const char* Form::GradeTooHighException::what() const throw() {
    return ("User can't acces file, the grade is too high");
}

const char* Form::GradeTooLowException::what() const throw() {
    return ("User can't access file, the grade is too low");
}

Form::Form() : _name("unamed"), _isSigned(false), _signGrade(150), _executeGrade(150) {}


Form::Form(const std::string& name, int sign, int execute) : 
            _name(name), 
            _isSigned(false), 
            _signGrade(sign), 
            _executeGrade(execute)
{
    if (sign < 1 || execute < 1)
        throw Form::GradeTooHighException();
    else if (sign > 150 || execute > 150)
        throw Form::GradeTooLowException();    
}

Form::Form(const Form& obj) : 
            _name(obj._name), 
            _isSigned(obj._isSigned), 
            _signGrade(obj._signGrade), 
            _executeGrade(obj._executeGrade)
{
    if (obj._signGrade < 1 || obj._executeGrade < 1)
        throw Form::GradeTooHighException();
    else if (obj._signGrade > 150 || obj._executeGrade > 150)
        throw Form::GradeTooLowException();
}

Form& Form::operator=(const Form& obj) {
    if (&obj == this){
        this->_isSigned = obj.getIsSigned();
    }
    return *this;
}

Form::~Form() {}


const std::string& Form::getName() const {
    return this->_name;
}
int Form::getSignGrade() const {
    return this->_signGrade;
}
int Form::getExecuteGrade() const {
    return this->_executeGrade;
}
bool Form::getIsSigned() const {
    return this->_isSigned;
}

void Form::beSigned(const Bureaucrat& user) {
    if (user.getGrade() > this->_signGrade)
        throw Form::GradeTooLowException();
    this->_isSigned = true;
}

std::ostream& operator<<(std::ostream& s, const Form& value) {
    s << value.getName() << " form require " << value.getSignGrade()
      << " to be signed and require " << value.getExecuteGrade() << " to be executed and it "
      << (value.getIsSigned() ? "is signed" : "is not signed");
    return s;
}
