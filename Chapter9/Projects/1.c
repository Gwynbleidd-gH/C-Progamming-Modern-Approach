void selection_sort(int arr[], int arr_size)
{
    int largest_index = 0;
    int i, temp;

    if (arr_size <= 1)
        return;
    for (i = 0; i < arr_size; i++) {
        if (arr[i] > arr[largest_index]) {
            largest_index = i;
        }
    }
    temp = arr[arr_size - 1];
    arr[arr_size - 1] = arr[largest_index];
    arr[largest_index] = temp;
    selection_sort(arr, arr_size - 1);
}
