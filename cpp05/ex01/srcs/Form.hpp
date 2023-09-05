/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguney <fguney@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:23:46 by fguney            #+#    #+#             */
/*   Updated: 2023/09/05 17:23:46 by fguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Form
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
    
    Form();
    Form(const std::string& name, int sign, int execute);
    Form(const Form&);
    Form& operator=(const Form&);
    ~Form();

    const std::string&        getName() const;
    int                 getSignGrade() const;
    int                 getExecuteGrade() const;
    bool                getIsSigned() const;
    void                beSigned(const Bureaucrat& user);

private:
    const std::string   _name;
    bool                _isSigned;
    const int           _signGrade;
    const int           _executeGrade;
};

std::ostream& operator<<(std::ostream& out, const Form& doc);

#endif
