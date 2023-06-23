/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftransfer.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facar <facar@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:03:44 by facar             #+#    #+#             */
/*   Updated: 2023/06/23 13:04:01 by facar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <fstream>
#include <vector>
class Clients;

#define FILET_STATUS_WAITING	0
#define FILET_STATUS_ACCEPTED	1
#define FILET_STATUS_REJECTED	2

class filet{
public:
	filet(Clients *source, Clients *target, std::string filename);
	~filet();

	int	setfile(std::fstream *);

	std::fstream	*getfile() const	{ return _file;		}
	Clients *		getSource() const	{ return source;	}
	Clients *		getTarget() const	{ return target;	}
	std::string		getFilename() const	{ return filename;	}
	std::string		getFilepath() const	{ return filepath;	}

	static std::vector<filet *>::iterator	filetfinder(std::vector<filet *> &, Clients *, std::string);
private:
	std::fstream	*_file;

	Clients *	source;
	Clients *	target;
	std::string	filepath;
	std::string	filename;
};