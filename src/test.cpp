#include <iostream>
#include <cstdio>
#include "map.hpp"
#include "memory.hpp"
#include "util.hpp"

#pragma GCC diagnostic ignored "-Wwrite-strings"
using namespace std;


typedef struct
{
	int x;
} Data;

int main(int argc, char** argv)
{
	void* address = (void*) 0x564246a2803c;

	Data d;
	std::cout << d.x << "\n";
	readm(7344, address, &d, sizeof(Data));
	std::cout << d.x << "\n";
}
