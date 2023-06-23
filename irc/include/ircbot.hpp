/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ircbot.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facar <facar@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:04:05 by facar             #+#    #+#             */
/*   Updated: 2023/06/23 13:04:06 by facar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "channel.hpp"
class Server;
class Clients;
class Channel;

class ircbot{
public:
	ircbot(Channel &);

	void	wellcome(Server &, Clients *);
	int		checkmsg(Server &, Clients *, std::string);
private:
	std::string	name;
	std::string	cnlname;
	Channel &onwork;
};