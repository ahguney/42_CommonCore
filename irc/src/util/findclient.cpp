/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findclient.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facar <facar@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:52:26 by facar             #+#    #+#             */
/*   Updated: 2023/06/23 16:52:28 by facar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include "clients.hpp"

template<typename T>
std::vector<Clients>::iterator	Clients::findnclient(std::vector<Clients> &map, T(Clients::*func)(void), T asd)
{
	std::vector<Clients>::iterator	ret = map.begin();
	for (; ret != map.end() ; ret++)
	{
		if (ret->*func() == asd)
			break;
	}
	return (ret);
}

std::vector<Clients>::iterator	util::findclient(std::vector<Clients> &map, const struct pollfd &poll)
{
	std::vector<Clients>::iterator	ret = map.begin();
	for (; ret != map.end() ; ret++)
	{
		if (ret->getclientsock() == poll.fd)
			break;
	}
	return (ret);
}

std::vector<Clients>::iterator	util::findclient(std::vector<Clients> &map, const int &poll)
{
	std::vector<Clients>::iterator	ret = map.begin();
	for (; ret != map.end() ; ret++)
	{
		if (ret->getclientsock() == poll)
			break;
	}
	return (ret);
}

std::vector<Clients>::iterator	util::findnick(std::vector<Clients> &cli, std::string nick)
{
	std::vector<Clients>::iterator ret = cli.begin();
	for (; ret != cli.end(); ret++)
	{
		if (ret->getnickname() == nick)
			break;
	}
	return (ret);
}
