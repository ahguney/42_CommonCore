#include <string>
#include <iostream>
#include <fstream>


int	main(int argc, char **argv)
{
	std::ifstream	Infile;
	std::ofstream	Outfile;
	std::string		Name, Find, Replace, Line;
	size_t			Pos;
	
	if (argc != 4)
		std::cout << "Usage: ./replace [filename] [string to find] [string to replace]" << std::endl;
	else {

		Name = argv[1];
		Find = argv[2];
		Replace = argv[3];
		
		Infile.open(Name);
		if (!Infile.is_open())
			std::cout << "Error: File could not be opened" << std::endl;
		else {
			
			Outfile.open(Name + ".replace");
			if (!Outfile.is_open())
				std::cout << "Error: Replace File could not be created" << std::endl;
			else {
				
				while (std::getline(Infile, Line)) {
					
					if (Line.find(Find) != std::string::npos){
						
						Pos = Line.find(Find);
						while (Pos != std::string::npos){
							
							Line.erase(Pos, Find.length());
							Line.insert(Pos, Replace);
							Pos = Line.find(Find, Pos + Replace.length());
						}
					}
				Outfile << Line << std::endl;
				}
			Outfile.close();
			}
		}
	return (0);
	}
}