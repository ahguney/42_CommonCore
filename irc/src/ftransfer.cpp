/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftransfer.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facar <facar@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:10:04 by facar             #+#    #+#             */
/*   Updated: 2023/06/23 13:10:09 by facar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.hpp"

filet::filet(Clients *source, Clients *target, std::string filename)
{
	this->source = source;
	this->target = target;
	this->filename = std::string(filename.begin() + filename.find_last_of("/") + 1, filename.end());
	this->filepath = std::string(filename.begin(), filename.begin() + filename.find_last_of("/") + 1);
}

filet::~filet()
{
	delete _file;
}

int	filet::setfile(std::fstream *s)
{
	_file = s;
	if (_file->fail())
		return 1;
	else
		return 0;
}

std::vector<filet *>::iterator	filet::filetfinder(std::vector<filet *> &vc, Clients *target, std::string filename)
{
	std::vector<filet *>::iterator	it = vc.begin();
	for (; it != vc.end(); it++)
	{
		if ((*it)->getFilename() == filename && (*it)->getSource() == target)
			break;
	}
	return it;
}

int	Server::removefile(std::vector<filet *>::iterator it)
{
	_files.erase(it);
	return 1;
}