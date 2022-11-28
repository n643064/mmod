#include "util.hpp"

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
