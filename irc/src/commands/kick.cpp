/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kick.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facar <facar@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:07:13 by facar             #+#    #+#             */
/*   Updated: 2023/06/23 13:08:04 by facar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.hpp"

int	Messages::kick(struct pollfd fd,  Server &srv, std::vector<std::string> token)
{
	std::vector<Clients>::iterator it = util::findclient(srv.getclient(), fd);
	std::map<std::string, Channel>::iterator cnl = srv.findchannel(token[1]);
	if (srv.ischannelexists(cnl) && it != srv.getclient().end())
	{
		if (cnl->second.isthisop(&*it))
			cnl->second.kickmember(srv, &(*it), &*(util::findnick(srv.getclient(), token[2])));
		else
			srv.sendmessage(fd, RPL_PRIVMSG(it->getnickname(), token[1], "You are not OP in that Channel."));
		return 0;
	}
	return 1;
}