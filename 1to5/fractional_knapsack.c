#include<stdio.h>

void selectionSort(float ratio[], float profit[], float weight[], int n) {
    int i, j, MaxIndex;
    float temp;
    float temp1, temp2;
    
    for (i = 0; i < n - 1; i++) {
        MaxIndex = i;
        for (j = i + 1; j < n; j++) {
            if (ratio[j] > ratio[MaxIndex]) {
                MaxIndex = j;
            }
        }
        temp = ratio[MaxIndex];
        ratio[MaxIndex] = ratio[i];
        ratio[i] = temp;
        
        temp1 = profit[MaxIndex];
        profit[MaxIndex] = profit[i];
        profit[i] = temp1;
        temp2 = weight[MaxIndex];
        weight[MaxIndex] = weight[i];
        weight[i] = temp2;
    }
    
    printf("Profit/Weight in descending order: ");
    for(int i = 0; i < n; i++) {
        printf("%.2f ", ratio[i]);
    }
    printf("\n");
}

void Knapsack(float weight[], float profit[], int m, int n) {
    float Total_profit = 0.0;
    int i = 0;
    for (int i = 0; i < n; i++) {
        if (m >= weight[i]) {
            Total_profit = Total_profit + profit[i];
            m = m - weight[i];
        } else if (m < weight[i]) {
            Total_profit = Total_profit + (m / weight[i]) * profit[i];
            break; 
        } else {
            break;
        }
    }
    
    printf("\nTotal Profit: %.2f\n", Total_profit);
}

int main() {
    int n, m;
    printf("Enter the number of objects: ");
    scanf("%d", &n);
    float profit[n];
    printf("Enter the profits: ");
    for (int i = 0; i < n; i++) {
        scanf("%f", &profit[i]);
    }
    float weight[n];
    printf("Enter the weights: ");
    for (int i = 0; i < n; i++) {
        scanf("%f", &weight[i]);
    }
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &m);
    float ratio[n];
    for (int i = 0; i < n; i++) {
        ratio[i] = profit[i] / weight[i];
    }
    printf("Profit/Weight: ");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", ratio[i]);
    }
    printf("\n");
    selectionSort(ratio, profit, weight, n);
    Knapsack(weight, profit, m, n);
    return 0;
}
// Good Luck for Viva :)