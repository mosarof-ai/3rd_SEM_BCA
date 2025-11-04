#include <stdio.h>

void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

void insertionSort(int arr[], int n) {
    int i, j, key;
    int totalComparisons = 0, totalShifts = 0;
    printf("Initial Array: ");
    displayArray(arr, n);
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        int comparisons = 0, shifts = 0;
        printf("Pass %d: ", i);
        while (j >= 0) {
            comparisons++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                shifts++;
                j--;
            } else break;
        }
        arr[j + 1] = key;
        totalComparisons += comparisons;
        totalShifts += shifts;
        displayArray(arr, n);
        printf("Comparisons this pass: %d, Shifts this pass: %d\n", comparisons, shifts);
    }
    printf("\nFinal Array: ");
    displayArray(arr, n);
    printf("Total Comparisons: %d\nTotal Shifts: %d\n", totalComparisons, totalShifts);
}

int main(void) {
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input!\n");
        return 1;
    }
    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        if (scanf("%d", &arr[i]) != 1) { printf("Invalid input!\n"); return 1; }
    insertionSort(arr, n);
    return 0;
}
