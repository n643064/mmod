#include <stdio.h>

struct 
{
	int x;
} data;

static void* p = &data;

int main()
{
	data.x = 15;
	printf("%x\n", p);
	printf("%d\n", data.x);
	while (data.x != 100)
	{

	}
	printf("End\n");
}
