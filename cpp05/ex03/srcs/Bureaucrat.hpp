/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguney <fguney@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:23:47 by fguney            #+#    #+#             */
/*   Updated: 2023/09/05 17:23:47 by fguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "AForm.hpp"

class AForm;

class Bureaucrat{
	
public:

		class GradeTooHighException: public std::exception{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException: public std::exception{
			public:
				virtual const char* what() const throw();
		};

		Bureaucrat();
        Bureaucrat(const Bureaucrat& src);
		Bureaucrat(const std::string name, int grade);
        ~Bureaucrat();
        Bureaucrat &operator=(const Bureaucrat&);

		std::string 			getName() const;
		int 					getGrade() const;
		void					incrementGrade();
		void 					decrementGrade();
		void 					signForm(AForm& src) const;
		void 					executeForm(AForm const & form);

private:

		const std::string 		_name;
		int 					_grade;

		void 					checkGrade() const;
		
};

std::ostream& operator<<(std::ostream&, const Bureaucrat&);

#endif
