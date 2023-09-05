/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguney <fguney@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:23:46 by fguney            #+#    #+#             */
/*   Updated: 2023/09/05 17:23:46 by fguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
    std::cout << "--------Creating and presenting everyone--------" << std::endl;
    Bureaucrat nobody;
    Bureaucrat bob("bob", 10);
    std::cout << nobody << std::endl;
    std::cout << bob << std::endl;

    std::cout << "\n\n----add 100 to the grade------" << std::endl;
    try {
        nobody.incrementGrade(100);
        std::cout << nobody << std::endl;
        bob.incrementGrade(100);
        std::cout << bob << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException&ex){
        std::cout << ex.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooHighException& ex) {
        std::cout << ex.what() << std::endl;
    }

    std::cout << "\n\n---remove 110 to the grade------" << std::endl;
    try {
        bob.decrementGrade(110);
        std::cout << bob << std::endl;
        nobody.decrementGrade(110);
        std::cout << nobody << std::endl;
    }
    catch (std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }


    std::cout << "\n\n-----create a bureaucrat with too low grades------"
              << std::endl;
    try {
        Bureaucrat buroc("buroc", 200);
    } 
    catch (std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }


    std::cout << "\n\n----create a bureaucrat with too high grades------" << std::endl;
    try {
        Bureaucrat burocc("burocc", 0);
    }
    catch (std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
    catch (...) {
        std::cout << "unkowned exception" << std::endl;
    }

    return 0;
}
