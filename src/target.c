#include <stdio.h>

struct 
{
	int x;
} data;

static void* p = &data;

int main()
{
	data.x = 10;
	printf("%x\n", p);
	printf("%d\n", data.x);
	for (;;)
	{

	}
}
