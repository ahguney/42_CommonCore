/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pong.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facar <facar@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:08:35 by facar             #+#    #+#             */
/*   Updated: 2023/06/23 13:08:50 by facar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.hpp"

int	Messages::pong(struct pollfd sock,  Server &srv, std::vector<std::string> token)
{
	std::vector<Clients>::iterator it = util::findclient(srv.getclient(), sock);
	if (it == srv.getclient().end())
		return 1;
	srv.sendmessage(sock, ":" + (*it).getnickname() + " PONG :" + token[1]);
	return 0;
}