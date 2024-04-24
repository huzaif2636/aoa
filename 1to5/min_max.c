#include <stdio.h>

void MaxMin(int i, int j, int a[], int *max, int *min) {
    int mid, max1, min1;
    if (i == j) {
        *max = *min = a[i];
    } else if (i == j - 1) {
        if (a[i] < a[j]) {
            *max = a[j];
            *min = a[i];
        } else {
            *max = a[i];
            *min = a[j];
        }
    } else {
        mid = (i + j) / 2;
        MaxMin(i, mid, a, max, min);
        MaxMin(mid + 1, j, a, &max1, &min1);
        if (*max < max1) {
            *max = max1;
        }
        if (*min > min1) {
            *min = min1;
        }
    }
}

int main() {
    int a[] = {3, 1, 5, 2, 4};
    int n = sizeof(a) / sizeof(a[0]);
    int max, min;
    MaxMin(0, n - 1, a, &max, &min);
    printf("Maximum element: %d\n", max);
    printf("Minimum element: %d\n", min);
    return 0;
}
// Good Luck for Viva :)