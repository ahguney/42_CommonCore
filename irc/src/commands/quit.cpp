/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facar <facar@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:09:07 by facar             #+#    #+#             */
/*   Updated: 2023/06/23 13:09:08 by facar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.hpp"

int	Messages::quit(struct pollfd sock,  Server &srv, std::vector<std::string> str)
{
	srv.sendmessage(sock, util::msgSender(str));
	srv.removesock(sock);
	return 1;
}