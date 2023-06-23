/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whois.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facar <facar@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:09:29 by facar             #+#    #+#             */
/*   Updated: 2023/06/23 13:09:29 by facar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.hpp"

int	Messages::whois(struct pollfd sock, Server &srv, std::vector<std::string> token)
{
	std::vector<Clients>::iterator it = util::findnick(srv.getclient(), token[1]);
	if (it == srv.getclient().end())
		return 1;
	userinf tmp = (*it).getuserinf();
	std::string	msg;
	msg = " " + tmp.username + " " + tmp.hostname + " " + tmp.realname;
	srv.sendmessage(sock, RPL_WHOIS((*it).getnickname(), msg));
	return 0;
}