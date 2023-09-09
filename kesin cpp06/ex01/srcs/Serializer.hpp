/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahguney <ahguney@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:35:58 by ahguney           #+#    #+#             */
/*   Updated: 2023/09/05 16:35:59 by ahguney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>

typedef struct Data {
	uint content;
	std::string string;
} Data;

class Serializer {

public:
	Serializer();

	Serializer(Serializer const &other);

	~Serializer();

	Serializer &operator=(Serializer const &rhs);

	static uintptr_t serialize(Data *ptr);

	static Data *deserialize(uintptr_t raw);

private:

};

#endif