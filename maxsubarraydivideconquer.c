#include <stdio.h>
#include <limits.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int crossSum(int a[], int low, int mid, int high) {
    int sum = 0, left = INT_MIN, right = INT_MIN;

    for (int i = mid; i >= low; i--) {
        sum += a[i];
        left = max(left, sum);
    }

    sum = 0;
    for (int i = mid + 1; i <= high; i++) {
        sum += a[i];
        right = max(right, sum);
    }

    return left + right;
}

int maxSubarray(int a[], int low, int high) {
    if (low == high)
        return a[low];

    int mid = (low + high) / 2;

    int left = maxSubarray(a, low, mid);
    int right = maxSubarray(a, mid + 1, high);
    int cross = crossSum(a, low, mid, high);

    return max(max(left, right), cross);
}

int main() {
    int a[50], n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Maximum subarray sum = %d\n",
           maxSubarray(a, 0, n - 1));

    return 0;
}
