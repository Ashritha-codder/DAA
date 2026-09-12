#include <stdio.h>

struct Result {
    int max;
    int min;
};

struct Result maxMin(int a[], int low, int high) {
    struct Result left, right, result;

    // Only one element
    if (low == high) {
        result.max = result.min = a[low];
        return result;
    }

    // Two elements
    if (high == low + 1) {
        if (a[low] > a[high]) {
            result.max = a[low];
            result.min = a[high];
        } else {
            result.max = a[high];
            result.min = a[low];
        }
        return result;
    }

    // Divide
    int mid = (low + high) / 2;

    // Conquer
    left = maxMin(a, low, mid);
    right = maxMin(a, mid + 1, high);

    // Combine
    result.max = (left.max > right.max) ? left.max : right.max;
    result.min = (left.min < right.min) ? left.min : right.min;

    return result;
}

int main() {
    int a[100], n, i;
    struct Result result;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    result = maxMin(a, 0, n - 1);

    printf("Maximum element = %d\n", result.max);
    printf("Minimum element = %d\n", result.min);

    return 0;
}
