/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguney <fguney@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:23:47 by fguney            #+#    #+#             */
/*   Updated: 2023/09/05 17:23:47 by fguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_H
#define AFORM_H

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm{

public:

		class GradeTooHighException: public std::exception {
			public:
					virtual const char* what() const throw();
		};

		class GradeTooLowException: public std::exception{
			public:
					virtual const char* what() const throw();
		};
		
		class FormIsNotSignException: public std::exception{
			public:
					virtual const char* what() const throw();
		};
		
		AForm();
        AForm(const AForm& src);
		AForm(const std::string name, const std::string target, bool isSigned, const int gradeToSign, const int gradeToExec);
        virtual ~AForm();
        AForm &operator=(const AForm&);

		std::string getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExec() const;
		std::string getTarget() const;
		virtual void execute(Bureaucrat const & user) const = 0;
		void validateExecute(Bureaucrat const & user) const;
		void beSigned(const Bureaucrat&);

private:
		const std::string _name;
		const std::string _target;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExec;
		
		void checkGrade() const;
};

std::ostream& operator<<(std::ostream&, const AForm&);

#endif
