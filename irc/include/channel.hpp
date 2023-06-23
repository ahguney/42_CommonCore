/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facar <facar@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:01:53 by facar             #+#    #+#             */
/*   Updated: 2023/06/23 13:01:53 by facar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <vector>

#include "ircbot.hpp"
#include "clients.hpp"
class Server;

class Channel{
public:
	Channel(std::string, Clients *);
	~Channel();

	void	loadlist(Server &, Clients *);
	void	broadcast(Server &, Clients *, std::string);

	void	IRCkickmember(Server &, Clients *);
	void	kickmember(Server &, Clients *, Clients *);
	void	joinmember(Server &, Clients *);

	bool	isthisop(Clients *);

	ircbot	&getbot() { return *bot; }
	std::string	getname() const { return _name; }
private:
	ircbot	*bot;
	int	maxmember;
	Clients	*_creator;
	std::string	_name;
	std::string	_topic;
	std::vector<Clients *>	_members;
	std::vector<Clients *>	_ops;

	void	broadcast(Server &, std::string);
};
