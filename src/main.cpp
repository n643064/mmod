#include <iostream>
#include <cstdio>
#include "memory.hpp"
#include "util.hpp"

#pragma GCC diagnostic ignored "-Wwrite-strings"
using namespace std;

#define OFFSET 0x4044

typedef struct
{
	int x;
} Data;

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		std::cout << "Usage: ./mmod [flags] [pid]\n";
		exit(0);
	}
	pid_t pid = atoi(argv[1]);

	void* address = get_base_from_maps(pid) + OFFSET;

	Data d;
	readm(pid, address, &d, sizeof(Data));
	std::cout << d.x << "\n";
	d.x = 100;
	writem(pid, address, &d, sizeof(Data));
}
