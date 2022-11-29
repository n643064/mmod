#ifndef MAP_HPP
#define MAP_HPP
#include <string>
#include <fstream>
#include <sstream>
#include <stdio.h>

class Map
{
	private:
		std::stringstream map;
		long start, end; 
	public:
		Map(pid_t pid);
		std::string get_base(void);
		std::string get_object_at(long offset);
};

#endif

