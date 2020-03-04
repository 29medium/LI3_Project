#include "headers.h"

void swap(char** a, char** b)
{
    void* aux = *a;
    *a = *b;
    *b = aux;
}

int partition (char** arr, int low, int high)
{
    char* pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {
        if (strcmp(arr[j], pivot) < 0)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(char** arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int binarySearch(char** arr, char* code, int low, int high)
{
    if (high >= low)
    {
        int mid = low + (high - low) / 2;

        if (strcmp(arr[mid], code) == 0)
            return mid;

        if (strcmp(arr[mid], code) > 0)
            return binarySearch(arr, code, low, mid - 1);

        else return binarySearch(arr, code, mid + 1, high);
    }

    return -1;
}
