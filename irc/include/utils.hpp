/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facar <facar@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:05:08 by facar             #+#    #+#             */
/*   Updated: 2023/06/23 13:05:42 by facar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <poll.h>
#include <vector>
#include <string>
#include <map>

class Clients;

class util{
public:
	static	std::vector<struct pollfd>::iterator	findsocket(std::vector<struct pollfd> &,const struct pollfd &);
	template<typename T>
	static	std::vector<Clients>::iterator	findnclient(std::vector<Clients> &, T(Clients::*)(void), T);
	static	std::vector<Clients>::iterator	findclient(std::vector<Clients> &map, const int &poll);
	static	std::vector<Clients>::iterator	findclient(std::vector<Clients> &, const struct pollfd &);
	static	std::vector<Clients>::iterator	findnick(std::vector<Clients> &, std::string);

	static	std::vector<std::string>	msgCreator(std::string, std::string, std::string);
	static	std::vector<std::string>	msgCreator(std::string, std::string);
	static	std::string	msgSender(std::vector<std::string>);
	static	std::string	msgSender(std::vector<std::string>, int start);

	static	std::vector<std::string>	split(std::vector<std::string>, int start);
};

int	operator<<(std::vector<struct pollfd> &, const struct pollfd &);