#ifndef ZOMBIE_CLASS_HPP
# define ZOMBIE_CLASS_HPP
# include <iostream>

class Zombie
{
public:

	// Constructors and destructors
	Zombie(void);
	~Zombie(void);

	// Use to annonce the zombie to STDOUT
	void		announce(void);
	// Use to set the zombie name
	void		setName(std::string name);
	
private:

	// Zombie's name
	std::string _name;

};

#endif
