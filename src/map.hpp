#ifndef MAP_HPP
#define MAP_HPP
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Map
{
	private:
		std::string map, stack_base, stack_end;
		 
	public:
		Map(pid_t pid);
		std::string get_base(void);
		std::string get_object_at(long offset);
};

#endif

