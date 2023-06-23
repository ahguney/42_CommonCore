/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nick.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facar <facar@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:08:12 by facar             #+#    #+#             */
/*   Updated: 2023/06/23 13:08:15 by facar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.hpp"

int	Messages::nick(struct pollfd fd,  Server &srv, std::vector<std::string> msg)
{
	if (msg.size() < 2)
	{
		Messages::error(fd, srv, util::msgCreator("ERROR", "461", "Not Enough Parameters"));
		return 1;
	}
	std::vector<Clients>::iterator	cli = util::findclient(srv.getclient(), fd);
	if (util::findnick(srv.getclient(), msg[1]) != srv.getclient().end())
	{
		Messages::error(fd, srv, util::msgCreator("ERROR", "443", "This Nickname Already Taken"));
		return 1;
	}
	if (srv.isop(msg[1]))
		(*cli).setop(1);
	else
		(*cli).setop(0);
	(*cli).setnickname(msg[1]);
	return 0;
}