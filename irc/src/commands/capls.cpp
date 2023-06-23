/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capls.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facar <facar@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:06:01 by facar             #+#    #+#             */
/*   Updated: 2023/06/23 13:06:03 by facar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.hpp"

int	Messages::cap(struct pollfd fd, Server &srv, std::vector<std::string> token)
{
	(void)token;
	srv.sendmessage(fd, "");
	return 0;
}