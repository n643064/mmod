#include "util.hpp"
#include <iostream>
std::string hex(long int d)
{
	std::stringstream ss;
	ss << std::hex << d;	
	return ss.str();		
}

long dec(std::string h)
{
	std::stringstream ss;
	ss << h;
	long d;
	ss >> std::hex >> d;
	return d;	
}


long unsigned int get_base_from_maps(pid_t pid)
{
	std::stringstream ss;
	std::string base;
	ss << "/proc/" << pid << "/maps";
	std::ifstream mapf(ss.str(), std::ios::binary);
	if (!mapf.is_open())
	{
		return -1;
	}
	
	getline(mapf, base);
	mapf.close();
	std::string address = "0x" + base.substr(0, base.find("-"));
	return stoul(base, nullptr, 16);
}
