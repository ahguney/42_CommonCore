/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahguney <ahguney@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:18:32 by ahguney           #+#    #+#             */
/*   Updated: 2023/09/05 16:18:32 by ahguney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void)
{
	Base *type[3] = {
						new A(),
						new B(),
						new C()
					};
	srand(time(nullptr));
	int random = rand() % 3;
	for (int i = 0; i < 3 ; i++){
		if (i != random)
			delete type[i];
	}
	return (type[random]);
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Pointers  type is A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Pointers  type is B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Pointers  type is C" << std::endl;
	else
		std::cout << "Bad dynamic cast" << std::endl;
}

void identify(Base& p)
{
	try{ 
		static_cast<void>(dynamic_cast<A&>(p));
		std::cout << "Reference type is A" << std::endl;
	}		catch (std::exception &bc){}
	try{ static_cast<void>(dynamic_cast<B&>(p));
		std::cout << "Reference type is B" << std::endl;
	}		catch (std::exception &bc){}
	try{ static_cast<void>(dynamic_cast<C&>(p));
		std::cout << "Reference type is C" << std::endl;
	}		catch (std::exception &bc){}
}

int main ()
{
	Base *b =  generate();
	identify(b);
	identify(*b);
	delete b;
	return (0);
}
