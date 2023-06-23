/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facar <facar@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:06:11 by facar             #+#    #+#             */
/*   Updated: 2023/06/23 13:06:12 by facar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.hpp"

int	Messages::error(struct pollfd sock, Server &srv, std::vector<std::string> token)
{
	srv.sendmessage(sock, util::msgSender(token));
	return 1;
}