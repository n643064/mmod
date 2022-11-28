#include "map.hpp"
using std::stringstream, std::ifstream, std::string;

Map::Map(pid_t pid)
{
	this -> map << "/proc/" << pid << "/maps";
	ifstream mapf(this -> map.str(), std::ios::binary);
	if (!mapf.is_open())
	{
		printf("Couldn't open map file");		
		exit(1);	
	}
	
	this -> map.clear();
	this -> map << mapf.rdbuf();
	mapf.close();


}

