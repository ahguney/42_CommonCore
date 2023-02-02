#include "zombie.class.hpp"

Zombie::Zombie(void){
	//std::cout << "Create a zombie" << std::endl;
	return;
}

Zombie::~Zombie(void){
	//std::cout << "kill " << this->_name << " the zombie!" << std::endl;
	return;
}

void	Zombie::announce(void){
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name){
	this->_name = name;
}
