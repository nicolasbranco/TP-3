#include <stdio.h>

#define NUM 5

void test_c()
{
	int * table;

	table = (int*)malloc(NUM * sizeof(int));

	for (int i = 0; i < NUM; i++)
	{
		table[i] = i;
		printf("\n %d = %d \n", i, table[i]);
	}

	system("pause");
}