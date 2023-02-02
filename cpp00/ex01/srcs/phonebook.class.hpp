#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP
# include "contact.class.hpp"

class PhoneBook
{
	
public:

	
	PhoneBook(void);
	~PhoneBook(void);
	
	
	void		open_phonebook(void);

private:

	
	int const	_max_contacts;
	int		 	_nb_contacts;
	Contact 	_contacts[8];
	
	
	void		_add_contact(void);
	void		_search_contact(void);
	
};

#endif
