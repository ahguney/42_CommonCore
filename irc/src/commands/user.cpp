/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facar <facar@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:09:19 by facar             #+#    #+#             */
/*   Updated: 2023/06/23 13:09:20 by facar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.hpp"

int	Messages::user(struct pollfd sock,  Server &srv, std::vector<std::string> token)
{
	std::vector<Clients>::iterator it = util::findclient(srv.getclient(), sock);
	if (token.size() != 5)
	{
		Messages::error(sock, srv, util::msgCreator("ERROR", "Not Enough Parameters"));
		return 1;
	}
	(*it).setuserinf(token[1], token[2], token[3], token[4]);
	(*it).setregistered(true);
	srv.sendmessage(sock, util::msgSender(util::msgCreator((*it).getnickname(), "001", "User Registered")));
	return 0;
}