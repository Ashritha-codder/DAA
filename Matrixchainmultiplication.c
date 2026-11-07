#include <stdio.h>
 #include <limits.h>
int matrixChainMultiplication(int p[], int n) {
 int dp[n][n]; int i,l,k;
for ( i = 1; i < n; i++)
{
    dp[i][i] = 0;
}
for ( l = 2; l < n; l++)
{
    for ( i = 1; i < n - l + 1; i++)
    {
        int j = i + l - 1;
        dp[i][j] = INT_MAX;
        for ( k = i; k < j; k++)
        {
            int cost = dp[i][k] +  dp[k + 1][j] +  p[i - 1] * p[k] * p[j];
            if (cost < dp[i][j])
            {
                dp[i][j] = cost;
            }
        }
    }
}
return dp[1][n - 1];
}
int main() { 
int n,i;
printf("Enter number of matrices: ");
scanf("%d", &n);
int p[n + 1];
printf("Enter dimensions of matrices:\n");
for ( i = 0; i <= n; i++)
{
    scanf("%d", &p[i]);
}
int result = matrixChainMultiplication(p, n + 1);
printf("Minimum number of multiplications = %d\n", result);
return 0;
}

