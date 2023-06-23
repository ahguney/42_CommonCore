/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ircbot.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facar <facar@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:10:12 by facar             #+#    #+#             */
/*   Updated: 2023/06/23 13:10:56 by facar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.hpp"
#include "ircbot.hpp"

ircbot::ircbot(Channel &c) : onwork(c)
{
	name = "ircbot";
	cnlname = onwork.getname();
}

void ircbot::wellcome(Server &srv, Clients *cl)
{
	srv.sendmessage(*cl->getclient(), RPL_PRIVMSG(name, cnlname, "<-<-<-<-<-<-<-<-<-<-->->->->->->->->->->\n"));
	srv.sendmessage(*cl->getclient(), RPL_PRIVMSG(name, cnlname, "<-          Welcome IM ircbot         ->\n"));
	srv.sendmessage(*cl->getclient(), RPL_PRIVMSG(name, cnlname, "<-    This channel Protected by me    ->\n"));
	srv.sendmessage(*cl->getclient(), RPL_PRIVMSG(name, cnlname, "<-               ENJOY !              ->\n"));
	srv.sendmessage(*cl->getclient(), RPL_PRIVMSG(name, cnlname, "<-<-<-<-<-<-<-<-<-<-->->->->->->->->->->\n"));
}

int	ircbot::checkmsg(Server &srv, Clients *cl, std::string str)
{
	if (str.find("amk") != std::string::npos)
		srv.sendmessage(*cl->getclient(), RPL_PRIVMSG(name, cnlname, "Lutfen kufur etmeyin !\n"));
	return 1;
}