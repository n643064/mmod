#include "map.hpp"

using std::stringstream, std::ifstream, std::string, std::cout;

Map::Map(pid_t pid)
{
	stringstream ss;
	string map;
	ss << "/proc/" << pid << "/maps";
	ifstream mapf(ss.str(), std::ios::binary);
	if (!mapf.is_open())
	{
		cout << "Couldn't open map file\n";
		exit(1);	
	}
	
	ss.clear();
	ss << mapf.rdbuf();
	mapf.close();
	map = ss.str();
	int s = map.rfind("[stack]");
	if (s >= 0)
	{
		int se = map.rfind("\n", s);
		this -> stack_base = map.substr(se, s-se);
		cout << this -> stack_base;
	}


	this -> map = map;
}

