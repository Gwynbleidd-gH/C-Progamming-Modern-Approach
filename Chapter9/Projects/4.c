#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void read_word(int counts[26])
{
    int c;

    while ((c = getchar()) != '\n' && c != EOF)
        if (isalpha(c))
            counts[tolower(c) - 'a']++;
}

bool equal_array(int counts1[26], int counts2[26])
{
    int i;

    for (i = 0; i < 26; i++)
        if (counts1[i] != counts2[i])
            return false;
    return true;
}

int main(void)
{
    int arr1[26] = { 0 }, arr2[26] = { 0 };

    printf("Enter the first word: ");
    read_word(arr1);

    printf("Enter the second word: ");
    read_word(arr2);

    if (equal_array(arr1, arr2))
        printf("The words are anagrams.\n");
    else
        printf("The words are not anagrams.\n");
    
    return 0;
}

