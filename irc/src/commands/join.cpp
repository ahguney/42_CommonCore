/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facar <facar@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:06:26 by facar             #+#    #+#             */
/*   Updated: 2023/06/23 13:06:45 by facar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define CNLNAME (token[1][0] != '#' ? "#" + token[1] : token[1])
#include "server.hpp"

int	Messages::join(struct pollfd sock,  Server &srv, std::vector<std::string> token)
{
	std::map<std::string, Channel>::iterator	it;
	it = srv.findchannel(CNLNAME);
	if (srv.ischannelexists(it))
	{
		(*it).second.joinmember(srv, &*(util::findclient(srv.getclient(), sock)));
	}
	else
	{
		srv.newchannel(&*(util::findclient(srv.getclient(), sock)), CNLNAME);
	}
	return 0;
}