#include <iostream>
#include <cstdio>
#include "map.hpp"
#include "memory.hpp"
#include "util.hpp"

#pragma GCC diagnostic ignored "-Wwrite-strings"
using namespace std;

#define OFFSET 0x403c

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
	stringstream ss;
	string read;
	ss << "/proc/" << pid << "/maps";
	ifstream mapf(ss.str(), std::ios::binary);
	if (!mapf.is_open())
	{
		cout << "Couldn't open map file\n";
		exit(1);	
	}
	getline(mapf, read);
	string base = "0x" + read.substr(0, read.find("-"));
	cout << base << "\n";
	unsigned long int a = stoul(base, nullptr, 16);
	printf("%x\n", a);
	void* address = a + OFFSET;
	cout << address << "\n";



	Data d;
	readm(pid, address, &d, sizeof(Data));
	std::cout << d.x << "\n";
}
