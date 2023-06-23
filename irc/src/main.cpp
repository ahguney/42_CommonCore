/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facar <facar@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:11:15 by facar             #+#    #+#             */
/*   Updated: 2023/06/23 13:11:17 by facar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.hpp"
#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		std::cerr << "Wrong use plase run with : ./ircserv <port> <password>" << std::endl;
		return 1;
	}
	Server	srv(stoi(argv[1]), argv[2]);
	srv.loop();
}