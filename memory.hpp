#ifndef MEMORY_HPP
#define MEMORY_HPP
#include <cstdlib>

typedef struct
{
	void* base;
	size_t size;
} iovec_t;


void readm(pid_t pid, void* address, void* buffer, size_t size);
void writem(pid_t pid, void* address, void* buffer, size_t size);
#endif
