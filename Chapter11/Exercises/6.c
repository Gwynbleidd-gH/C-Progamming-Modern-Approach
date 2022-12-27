void find_two_largest(int arr[], int n, int *largest, int *second_largest)
{
    int i;

    if (arr[0] > arr[1]) {
        *largest = arr[0];
        *second_largest = arr[1];
    }
    else {
        *second_largest = arr[0];
        *largest = arr[1];
    }
    for (i = 2; i < n; i++) {
        if (arr[i] > *largest)
            *largest = arr[i];
        if (arr[i] > *second_largest && arr[i] < *largest)
            *second_largest = arr[i];
    }
}
