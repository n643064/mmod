#include <stdio.h>

struct 
{
	int x;
} data;


int main()
{
	data.x = 15;
	printf("%d : %x\n", data.x, &data);
	while (data.x != 100)
	{

	}
	printf("End\n");
}
