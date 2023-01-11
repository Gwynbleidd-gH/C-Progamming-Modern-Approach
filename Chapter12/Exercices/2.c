#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool palindrome(char str[]);

int main(void)
{
    char message[MAX_LEN];

    printf("Enter a message: ");
    fgets(message, MAX_LEN, stdin);
    message[strlen(message)] = '\0';

    if (palindrome(message))
        printf("Palindrome");
    else
        printf("Not a palindrome");

    return 0;
}

/* hard (or stupid?) mode */
bool palindrome(char str[])
{
    int i = 0, j = strlen(str) - 1;

    while (i < j) {
        if (!isalpha(str[i])) {
            i++;
            continue;
        }
        if (!isalpha(str[j])) {
            j--;
            continue;
        }
        if (toupper(str[i]) == toupper(str[j])) {
            i++;
            j--;
        }
        else
            break;
    }

    return i == j;
}
