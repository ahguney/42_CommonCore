/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantremb <dantremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 18:26:38 by dantremb          #+#    #+#             */
/*   Updated: 2022/12/08 13:38:10 by dantremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.class.hpp"

Contact::Contact(void){
	//std::cout << "Contact created" << std::endl;
}

Contact::~Contact(void){
	//std::cout << "Contact destroyed" << std::endl;
}

std::string Contact::_get_first_name(void) const{
	return (this->_first_name);
}

std::string Contact::_get_last_name(void) const{
	return (this->_last_name);
}

std::string Contact::_get_nickname(void) const{
	return (this->_nickname);
}

std::string Contact::_get_phone_number(void) const{
	return (this->_phone_number);
}

std::string Contact::_get_darkest_secret(void) const{
	return (this->_darkest_secret);
}

void Contact::_set_first_name(void){
	std::string buffer;

	while (buffer.size() <= 0)
	{
		std::cout << "PhoneBook >    First name : ";
		std::getline(std::cin, buffer);
	}
	this->_first_name = buffer;
}

void Contact::_set_last_name(void){
	std::string buffer;

	while (buffer.size() <= 0)
	{
		std::cout << "PhoneBook >     Last name : ";
		std::getline(std::cin, buffer);
	}
	this->_last_name = buffer;
}

void Contact::_set_nickname(void){
	std::string buffer;

	while (buffer.size() <= 0)
	{
		std::cout << "PhoneBook >      Nickname : ";
		std::getline(std::cin, buffer);
	}
	this->_nickname = buffer;
}

void Contact::_set_phone_number(void){
	std::string buffer;

	while (buffer.size() <= 0)
	{
		std::cout << "PhoneBook >  Phone Number : ";
		std::getline(std::cin, buffer);
	}
	this->_phone_number = buffer;
}

void Contact::_set_darkest_secret(void){
	std::string buffer;

	while (buffer.size() <= 0)
	{
		std::cout << "PhoneBook > Darkest Secret: ";
		std::getline(std::cin, buffer);
	}
	this->_darkest_secret = buffer;
}

std::string Contact::_truncate(std::string str) const{
	std::string temp = str;
	
	if (temp.size() > 10)
		return (temp.substr(0, 9) + ".");
	return (temp);
}

void Contact::print_preview(int index) const{
	std::cout << "|";
	std::cout.width(10);
	std::cout << index << "|";
	std::cout.width(10);
	std::cout << this->_truncate(this->_first_name) << "|";
	std::cout.width(10);
	std::cout << this->_truncate(this->_last_name) << "|";
	std::cout.width(10);
	std::cout << this->_truncate(this->_nickname) << "|";
	std::cout << std::endl;
	return ;
}

void Contact::print_contact(void) const{
	std::cout << "    First name: " << this->_first_name << std::endl;
	std::cout << "     Last name: " << this->_last_name << std::endl;
	std::cout << "      Nickname: " << this->_nickname << std::endl;
	std::cout << "  Phone number: " << this->_phone_number << std::endl;
	std::cout << "Darkest secret: " << this->_darkest_secret << std::endl;
}

void Contact::create_contact(void){
	this->_set_first_name();
	this->_set_last_name();
	this->_set_nickname();
	this->_set_phone_number();
	this->_set_darkest_secret();
}