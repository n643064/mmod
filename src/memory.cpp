#include "memory.hpp"

void readm(pid_t pid, void* address, void* buffer, size_t size)
{
	struct iovec local;
	local.iov_base = buffer;
	local.iov_len = size;
	
	struct iovec remote;
	remote.iov_base = address;
	remote.iov_len = size;

	process_vm_readv(pid, &local, 1, &remote, 1, 0);
}

void writem(pid_t pid, void* address, void* buffer, size_t size)
{
	struct iovec local;
	local.iov_base = buffer;
	local.iov_len = size;
	
	struct iovec remote;
	remote.iov_base = address;
	remote.iov_len = size;

	process_vm_writev(pid, &local, 1, &remote, 1, 0);
}
