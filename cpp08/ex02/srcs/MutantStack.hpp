/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahguney <ahguney@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:36:59 by ahguney           #+#    #+#             */
/*   Updated: 2023/09/12 17:36:59 by ahguney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <iostream>
# include <list>
# include <deque>

template <typename T>
class MutantStack : public std::stack<T>
{
    public :
        MutantStack(void) {}
        MutantStack & operator=(MutantStack const &cpy)
        {
			this->c = cpy.c;
			return(*this);
        }
        MutantStack(MutantStack const &cpy) { *this = cpy; }
        ~MutantStack(void) {}

        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator    begin()     { return (this->c.begin());     }
        iterator    end()       { return (this->c.end());       }
};

#endif
