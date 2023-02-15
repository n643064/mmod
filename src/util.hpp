#ifndef UTIL_HPP
#define UTIL_HPP
#include <string>
#include <sstream>
#include <fstream>

std::string hex(long int d);
long dec(std::string h);
long unsigned int get_base_from_maps(pid_t pid);

#endif
