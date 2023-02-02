/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantremb <dantremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 18:26:40 by dantremb          #+#    #+#             */
/*   Updated: 2022/08/22 01:34:34 by dantremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP
# include <iostream>
# include <string>

class Contact
{
	
public:

	// Constructors and destructors
	Contact(void);
	~Contact(void);
	
	// Function to manage the contact
	void			create_contact(void);
	void			print_preview(int index) const;
	void			print_contact(void) const;
	
private:

	// Getters to access private members
	std::string 	_get_first_name(void) const;
	std::string		_get_last_name(void) const;
	std::string		_get_nickname(void) const;
	std::string 	_get_phone_number(void) const;
	std::string 	_get_darkest_secret(void) const;
	std::string 	_truncate(std::string str) const;

	// Setters to modify the contact's data
	void			_set_first_name(void);
	void			_set_last_name(void);
	void			_set_nickname(void);
	void			_set_phone_number(void);
	void			_set_darkest_secret(void);
		
	// Attributes can only be accessed by the class itself
	std::string 	_first_name;
	std::string 	_last_name;
	std::string 	_nickname;
	std::string 	_phone_number;
	std::string 	_darkest_secret;	
	
};

#endif
