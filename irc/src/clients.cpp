/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clients.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facar <facar@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:09:59 by facar             #+#    #+#             */
/*   Updated: 2023/06/23 13:10:00 by facar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clients.hpp"

Clients::Clients(int sock) : _nickname(UNCONFIRMED)
{
	struct sockaddr_in	clientaddr;
	socklen_t	slen = sizeof(clientaddr);
	_client.fd = accept(sock, (struct sockaddr*)&clientaddr, &slen);
	if (_client.fd < 0)
		exit(EXIT_FAILURE);
	confirmed = false;
	registered = false;
	serverop = false;
}

void	Clients::setuserinf(std::string s1, std::string s2, std::string s3, std::string s4)
{
	_userinf.username = s1;
	_userinf.hostname = s2;
	_userinf.servername = s3;
	_userinf.realname = s4;
}

Clients::~Clients()
{
}