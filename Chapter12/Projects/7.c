#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

void max_min(int *a, int n, int *max, int *min);

int main(void)
{
	int arr[5] = { 3, 5, 2, 1, 8 };
	int max, min;

	max_min(arr, 5, &max, &min);
	printf("%d %d\n", max, min);

	return 0;
}

void max_min(int *a, int n, int *max, int *min)
{
	int *ptr;

	*max = *min = *a;
	for (ptr = a + 1; ptr < a + n; ptr++) {
		if (*ptr > *max)
			*max = *ptr;
		else if (*ptr < *min)
			*min = *ptr;
	}
}
