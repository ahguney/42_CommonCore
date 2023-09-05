/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguney <fguney@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:23:46 by fguney            #+#    #+#             */
/*   Updated: 2023/09/05 17:23:46 by fguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <exception>
# include <iostream>

class Form;

class Bureaucrat
{
public:

    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
	
    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
	
    Bureaucrat();
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat &src);
    ~Bureaucrat();
    Bureaucrat& operator=(const Bureaucrat &src);

    void        	setName(const std::string &name);
    std::string 	getName() const;
    int         	getGrade() const;
    void        	incrementGrade(int increment);
    void        	decrementGrade(int decrement);
    void        	signForm(Form& value) const;

private:

    std::string 	_name;
    int         	_grade;

};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& src);

#endif
