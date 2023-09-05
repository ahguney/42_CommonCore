/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguney <fguney@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:23:47 by fguney            #+#    #+#             */
/*   Updated: 2023/09/05 17:23:47 by fguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H

# include <iostream>
# include <cstdlib>
# include <ctime>
# include "AForm.hpp"

class RobotomyRequestForm: public AForm {
	
public:
		RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm&);
		RobotomyRequestForm(const std::string target);
        virtual ~RobotomyRequestForm();
        RobotomyRequestForm &operator=(const RobotomyRequestForm&);

		virtual void execute(Bureaucrat const & executor) const;

};

#endif
