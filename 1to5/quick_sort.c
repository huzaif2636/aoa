#include <stdio.h>
#include <stdlib.h>

void quicksort(int *arr, int start, int end) {
    if (start >= end - 1)
        return;
    
    int p = start + 1, q = end - 1;
    int v = start;
    
    while (p <= q) {
        while (p < end && arr[p] <= arr[v])
            p++;
        while (q >= start && arr[q] > arr[v])
            q--;
        if (p > q)
            break;
        int temp = arr[p];
        arr[p] = arr[q];
        arr[q] = temp;
        p++;
        q--;
    }
    int temp = arr[v];
    arr[v] = arr[q];
    arr[q] = temp;
    
    quicksort(arr, start, q);
    quicksort(arr, q + 1, end);
}

int main() {
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Invalid size\n");
        return 1;
    }
    
    int *arr = malloc(sizeof(int) * n);
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        printf("Enter Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    
    quicksort(arr, 0, n);
    
    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    free(arr);
    return 0;
}
// Good Luck for Viva :)