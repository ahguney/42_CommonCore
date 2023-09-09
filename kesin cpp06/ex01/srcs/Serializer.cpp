/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahguney <ahguney@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:35:52 by ahguney           #+#    #+#             */
/*   Updated: 2023/09/05 16:35:54 by ahguney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {
	std::cout << "Serializer default constructor called\n";
}

Serializer::~Serializer() {
	std::cout << "Serializer default destructor called\n";
}

Serializer::Serializer(Serializer const &other) {
	(void) other;
	std::cout << "Serializer copy constructor called\n";
}

Serializer &Serializer::operator=(Serializer const &rhs) {
	(void) rhs;
	return *this;
}

uintptr_t Serializer::serialize(Data *ptr) {
	return reinterpret_cast<uintptr_t >(ptr);
}

Data *Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data *>(raw);
}