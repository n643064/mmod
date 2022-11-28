#ifndef MEMORY_HPP
#define MEMORY_HPP
#include <cstdint>
#include <sys/uio.h>
#include "map.hpp"
typedef struct
{
	void* base;
	size_t size;
} iovec_t;


void readm(pid_t pid, void* address, void* buffer, size_t size);
void writem(pid_t pid, void* address, void* buffer, size_t size);


#endif
