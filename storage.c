#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
	printf("Storage size for int: %d\n", sizeof(int));
	printf("Storage size for float: %d\n", sizeof(float));
	printf("Minimum float pos value: %E\n", FLT_MIN);
	printf("Max float pos value: %E\n", FLT_MAX);
	printf("Precision value: %d\n", FLT_DIG);
	return 0;
}

