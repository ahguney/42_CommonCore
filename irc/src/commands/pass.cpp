/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facar <facar@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:08:22 by facar             #+#    #+#             */
/*   Updated: 2023/06/23 13:08:23 by facar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.hpp"
#include <iostream>

int	Messages::pass(struct pollfd sock, Server &srv, std::vector<std::string> token)
{
	std::vector<Clients>::iterator it = util::findclient(srv.getclient(), sock);
	if (it == srv.getclient().end())
		return 1;
	if (token[1] != srv.getpass())
	{
		Messages::error(sock, srv, util::msgCreator(" 464 ERROR", "incorrect Password."));
		Messages::quit(sock, srv, util::msgCreator(" QUIT", "Disconnecting()"));
		return 1;
	}
	(*it).setconfirmed(true);
	srv.sendmessage(sock, util::msgSender(util::msgCreator("PASS", "001", "Password Accepted")));
	return 0;
}