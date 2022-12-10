void anagram2(void)
{
    short alphabet[26] = { 0 };
    int c, i;

    printf("Enter the first word: ");
    while ((c = getchar()) != '\n' && c != EOF)
        if (isalpha(c))
            alphabet[tolower(c) - 'a']++;

    printf("Enter the second word: ");
    while ((c = getchar()) != '\n' && c != EOF)
        if (isalpha(c))
            alphabet[tolower(c) - 'a']--;

    for (i = 0; i < 26; i++)
        if (alphabet[i])
            break;
    if (i == 26)
        printf("The words are anagrams.");
    else
        printf("The words are not anagrams.");
}
