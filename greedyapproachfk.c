#include <stdio.h>

int main() {
    int n, capacity;
    float weight[20], profit[20], ratio[20], total = 0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weights:\n");
    for (int i = 0; i < n; i++)
        scanf("%f", &weight[i]);

    printf("Enter profits:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &profit[i]);
        ratio[i] = profit[i] / weight[i];
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    // Sort according to profit/weight ratio
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (ratio[i] < ratio[j]) {
                float t = ratio[i]; ratio[i] = ratio[j]; ratio[j] = t;
                t = weight[i]; weight[i] = weight[j]; weight[j] = t;
                t = profit[i]; profit[i] = profit[j]; profit[j] = t;
            }

    for (int i = 0; i < n; i++) {
        if (capacity >= weight[i]) {
            total += profit[i];
            capacity -= weight[i];
        } else {
            total += ratio[i] * capacity;
            break;
        }
    }

    printf("Maximum profit = %.2f\n", total);

    return 0;
}
