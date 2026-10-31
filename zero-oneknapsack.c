#include <stdio.h>
int max(int a, int b) {
	return (a > b) ? a : b;
}
int main() {
	int n, W, i, w;
	printf("Enter number of items: ");
	scanf("%d", &n);
	int wt[n], val[n];
	printf("Enter weights of items:\n");
	
	for (i = 0; i < n; i++) {
 		   scanf("%d", &wt[i]);
	}
	
	printf("Enter values of items:\n");
	
	for (i = 0; i < n; i++) {
  		scanf("%d", &val[i]);
	}
	
	printf("Enter knapsack capacity: ");
	scanf("%d", &W);
	int dp[n + 1][W + 1];
	
	for (i = 0; i <= n; i++) {
    		for (w = 0; w <= W; w++) {
        			if (i == 0 || w == 0) {
            				dp[i][w] = 0;
       			 }
        			else if (wt[i - 1] <= w) {
            				dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]],dp[i - 1][w]);
        			}
        			else {
            				dp[i][w] = dp[i - 1][w];
        			}
    		}
	}

	printf("\nDP Table:\n");

	for (i = 0; i <= n; i++) {
    		for (w = 0; w <= W; w++) {
        			printf("%d\t", dp[i][w]);
    		}
    		printf("\n");
	}

	printf("\nMaximum Profit = %d\n", dp[n][W]);

	return 0;
}

