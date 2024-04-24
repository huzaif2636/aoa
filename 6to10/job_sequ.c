#include<stdio.h>
void Sort(int Profit[], char job[], int Deadline[], int n);
int MAX(int n, int Deadline[]);
void Profits(int m, int n, char arr[], char job[], int Profit[], int Deadline[]);
int main() {
    int m, n;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);
    
    char job[n];
    int Profit[n], Deadline[n]; 
    
    printf("Enter Jobs (a, b, c, ...): ");
    for(int i = 0; i < n; i++) {
        scanf(" %c", &job[i]);
    }
    printf("Enter Profits: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &Profit[i]);
    }
    printf("Enter Deadlines: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &Deadline[i]);
    }
    
    Sort(Profit, job, Deadline, n);
    m = MAX(n, Deadline);
    char arr[m]; 
    Profits(m, n, arr, job, Profit, Deadline);
    return 0;
}
void Sort(int Profit[], char job[], int Deadline[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int MaxIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (Profit[j] > Profit[MaxIndex]) {
                MaxIndex = j;
            }
        }
        int temp1 = Profit[MaxIndex];
        Profit[MaxIndex] = Profit[i];
        Profit[i] = temp1;
        char temp2 = job[MaxIndex];
        job[MaxIndex] = job[i];
        job[i] = temp2;
        int temp3 = Deadline[MaxIndex];
        Deadline[MaxIndex] = Deadline[i];
        Deadline[i] = temp3;
    }
    printf("\nJobs: ");
    for (int i = 0; i < n; i++) {
        printf("%c ", job[i]);
    }
    printf("\nProfits: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", Profit[i]);
    }
    printf("\nDeadline: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", Deadline[i]);
    }
    printf("\n");
}
int MAX(int n, int Deadline[]) {
    int max = Deadline[0];
    for (int i = 1; i < n; i++) {
        if (Deadline[i] > max) {
            max = Deadline[i];
        }
    }
    return max;
}
void Profits(int m, int n, char arr[], char job[], int Profit[], int Deadline[]) {
    for (int i = 0; i < m; i++) {
        arr[i] = ' ';
    }
    int Total_profit = 0;
    for (int i = 0; i < n; i++) {
        int M = Deadline[i];
        while (M > 0 && arr[M - 1] != ' ') { 
            M--;
        }
        if (M > 0) {
            arr[M - 1] = job[i];
            Total_profit += Profit[i];
        }
    }
    printf("\nScheduled Jobs: ");
    for (int i = 0; i < m; i++) {
        if (arr[i] != ' ') {
            printf("%c ", arr[i]);
        } else {
            printf("| |");
        }
    }
    printf("\nTotal Profit: %d\n", Total_profit);
}
// Good Luck for Viva :)