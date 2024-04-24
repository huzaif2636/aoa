#include <stdio.h>
#define SIZE 8
int w[SIZE] = {15, 22, 14, 26, 32, 9, 16, 8};
int subset[SIZE];
int totalSubset = 0;

void generateSubset(int index, int sum, int target) {
    if (sum == target) {
        printf("{ ");
        for (int i = 0; i < index; i++) {
            printf("%d ", subset[i]);
        }
        printf("}\n");
        totalSubset++;
        return;
    }
    if (index == SIZE || sum > target)
        return;
    subset[index] = w[index];
    generateSubset(index + 1, sum + w[index], target);
    subset[index] = 0;
    generateSubset(index + 1, sum, target);
}

int main() {
    int target = 53;
    printf("Subsets of w that sum to %d:\n", target);
    generateSubset(0, 0, target);
    
    printf("Nodes generated %d\n", totalSubset);
    return 0;
}
// Good Luck for Viva :)
