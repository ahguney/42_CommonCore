/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantremb <dantremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 18:26:45 by dantremb          #+#    #+#             */
/*   Updated: 2022/12/08 13:38:29 by dantremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.class.hpp"

PhoneBook::PhoneBook(void) : _max_contacts(8), _nb_contacts(0){
	//std::cout << "Phonebook created" << std::endl;
}

PhoneBook::~PhoneBook(void){
	//std::cout << "Phonebook destroyed" << std::endl;
}

void PhoneBook::open_phonebook(void){
	std::string	buffer;
	
	std::cout << "_____________________________________________" << std::endl;
	std::cout << "|                                           |" << std::endl;
	std::cout << "|            DANTREMB   PHONEBOOK           |" << std::endl;
	std::cout << "|___________________________________________|" << std::endl;
	std::cout << "|                                           |" << std::endl;
	std::cout << "|      [ADD]      [SEARCH]      [EXIT]      |" << std::endl;
	std::cout << "|___________________________________________|" << std::endl;
	while (1)
	{
		std::cout << "PhoneBook > ";
		std::getline(std::cin, buffer);
		if (buffer == "EXIT")
			return ;
		else if (buffer == "SEARCH")
			this->_search_contact();
		else if (buffer == "ADD")
			this->_add_contact();
		else
			continue ;
	}
}

void PhoneBook::_add_contact(void){
	static int i = 0;
	this->_nb_contacts++;
	if (this->_nb_contacts > this->_max_contacts)
	{
		if (i >= 0)
		{
			if (i >= 7)
			i = 0;
			this->_contacts[i].create_contact();
			this->_nb_contacts--;
			++i;
		}
		return ;
	}
	this->_contacts[_nb_contacts - 1].create_contact();
}

void PhoneBook::_search_contact(void){
	std::string	buffer;
	int index = -1;
	if (this->_nb_contacts == 0)
	{
		std::cout << "Phonebook is empty" << std::endl;
		return ;
	}
	std::cout << "_____________________________________________" << std::endl;
	std::cout << "|     Index| FirstName|  LastName|  NickName|" << std::endl;
	std::cout << "|__________|__________|__________|__________|" << std::endl;
	for (int i = 0 ; i != this->_nb_contacts ; i++)
		this->_contacts[i].print_preview(i + 1);
	std::cout << "|__________|__________|__________|__________|" << std::endl;
	while (std::isdigit(buffer[0]) == 0)
	{
		std::cout << "Search > ";
		std::getline(std::cin, buffer);
	}
	index = std::stoi(buffer);
	if (index <= this->_nb_contacts && index > 0)
		this->_contacts[index - 1].print_contact();
	else
		std::cout << "Contact not found" << std::endl;
}
