#include<stdio.h>
#include"test.h"


int main()
{

	
	unordered_map* map = createUnordered_map(POINTER, INT);
	int x = 10;
	int* z = &x;
	PutUnordered_map(map, &z, &x);
	int y = 0;
	GetUnordered_map(map, &z, &y);
	printf("%d\n", y);
	FreeUnordered_map(map);
	
	return 0;
}