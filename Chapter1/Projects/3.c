#include <stdio.h>
#include <stdbool.h>

int main()
{
	int repeated_digits[10] = { 0 };
	int number;
	int digit;
	int i;

	while (true) {
		printf("Enter a number: ");
		scanf_s("%d", &number);
		if (number <= 0)
			break;
		while (number > 0) {
			digit = number % 10;
			repeated_digits[digit]++;
			number /= 10;
		}
		printf("Digit:\t\t0 1 2 3 4 5 6 7 8 9");
		printf("\nOccurrences:\t");
		for (i = 0; i < 10; i++) {
			printf("%d%c", repeated_digits[i], (i < 9) ? ' ' : '\n');
			repeated_digits[i] = 0;
		}
	}
	return 0;
}
