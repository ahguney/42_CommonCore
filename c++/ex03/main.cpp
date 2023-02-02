#include "Weapon.class.hpp"
#include "HumanA.class.hpp"
#include "HumanB.class.hpp"

int main()
{
	Weapon club = Weapon("crude spiked club");
	HumanA bob("Bob", club);
	bob.attack();
	club.setType("some other type of club");
	bob.attack();

	Weapon clubs = Weapon("crude spiked club");
	HumanB jim("Jim");
	jim.setWeapon(clubs);
	jim.attack();
	clubs.setType("some other type of club");
	jim.attack();
	return 0;
}
