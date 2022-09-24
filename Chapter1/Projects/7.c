#include <stdio.h>

int main()
{
    int arr[5][5];
	int i, j;
	int row_total[5] = { 0 };
	int column_total[5] = { 0 };

	for (i = 0; i < 5; i++) {
		printf("Enter row %d: ", i + 1);
		for (j = 0; j < 5; j++) {
			scanf_s("%d", &arr[i][j]);
		}
	}
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			row_total[i] += arr[i][j];
			column_total[i] += arr[j][i];
		}
	}
	printf("Row totals:");
	for (i = 0; i < 5; i++)
		printf(" %d", row_total[i]);
	printf("\nColumn totals:");
	for (i = 0; i < 5; i++)
		printf(" %d", column_total[i]);
	printf("\n");
    
    return 0;
}
