#include "sort.h"

/**
  * shell_sort - A function tat sorts an array usin shell algorithm.
  * @array: The array to sort.
  * @size: The length of the array.
  * Return: Nothing.
  */
void shell_sort(int *array, size_t size) {
    int interval = 1;
    while (interval < size / 3) {
        interval = interval * 3 + 1; // calculate Knuth sequence interval
    }

    while (interval > 0) {
        printf("Array after interval %d sorting: ", interval);
        for (int i = interval; i < size; i++) {
            int temp = array[i];
            int j = i;
            while (j >= interval && array[j - interval] > temp) {
                array[j] = array[j - interval];
                j -= interval;
            }
            array[j] = temp;
        }

        // decrease the interval
        interval = (interval - 1) / 3;
        // print the current state of array
        for (int i = 0; i < size; i++) {
            printf("%d ", array[i]);
        }
        printf("\n");
    }
}

int main() {
    int arr[] = {45, 23, 76, 32, 82, 15, 68, 53};
    size_t size = sizeof(arr) / sizeof(arr[0]);

    printf("Array before sorting: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    shell_sort(arr, size);

    printf("Array after sorting: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}