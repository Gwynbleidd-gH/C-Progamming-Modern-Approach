#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h>

int main(void)
{
    int digit_occurrence[10] = { 0 };
    long number;
    int digit;
    int i;

    printf("Enter a number: ");
    scanf_s("%ld", &number);

    while (number > 0) {
        digit = number % 10;
        number /= 10;
        ++digit_occurrence[digit];
    }

    printf("Digit:\t\t0  1  2  3  4  5  6  7  8  9\n");
    printf("Occurrences:  ");
    for (i = 0; i < 10; i++) {
        printf("%3d", digit_occurrence[i]);
    }
    printf("\n");

    return 0;
}
