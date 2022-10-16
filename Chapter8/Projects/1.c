#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h>

int main(void)
{
    int digit_seen[10] = { 0 };
    long number;
    int digit;
    int i;

    printf("Enter a number: ");
    scanf_s("%ld", &number);
    while (number > 0) {
        digit = number % 10;
        number /= 10;
        ++digit_seen[digit];
    }
    printf("Repeated digits: ");
    for (i = 0; i < 10; i++)
        if (digit_seen[i] >= 2)
            printf(" %d", i);
    printf("\n");
  
    return 0;
}
