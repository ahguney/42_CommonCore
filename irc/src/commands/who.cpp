/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   who.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facar <facar@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:09:23 by facar             #+#    #+#             */
/*   Updated: 2023/06/23 16:36:37 by facar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.hpp"

int	Messages::who(struct pollfd sock,  Server &srv, std::vector<std::string> token)
{
	if (token.size() < 2)
	{
		Messages::error(sock, srv, util::msgCreator("ERROR", "461", "Not Enough Parameters"));
		return 1;
	}
	if (token[1][0] == '#')
	{
		std::map<std::string, Channel>::iterator chnl = srv.findchannel(token[1]);
		if (srv.ischannelexists(chnl))
		{
			(*chnl).second.loadlist(srv, &*(util::findclient(srv.getclient(), sock)));
		}
	}
	return 0;
}