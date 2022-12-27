int* find_largest(int arr[], int n)
{
    int i, larg_index = 0;

    for (i = 0; i < n; i++)
        if (arr[i] > arr[larg_index])
            larg_index = i;
    return &arr[larg_index];
}
