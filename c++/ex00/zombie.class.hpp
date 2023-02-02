#ifndef ZOMBIE_CLASS_HPP
# define ZOMBIE_CLASS_HPP
# include <iostream>

class Zombie
{
public:

	// Constructors and destructors
	Zombie(std::string init_name);
	~Zombie(void);

	// Use to annonce the zombie to STDOUT
	void		announce(void);
	
private:

	// Zombie's name
	std::string _name;

};

#endif
