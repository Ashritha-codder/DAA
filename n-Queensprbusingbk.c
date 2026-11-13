#include <stdio.h>
#include <stdlib.h>
int board[20][20];
int n; 
int isSafe(int row, int col)
{
    int i, j;
    for (i = 0; i < row; i++)
    {
        if (board[i][col] == 1)
            return 0;
    }
    for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
            return 0;
    }
    for (i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 1)
            return 0;
    } 
   return 1;
}
void printSolution()
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (board[i][j] == 1)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
    printf("\n");
}
int solveNQueens(int row)
{
    int col;
    if (row == n)
    {
        printSolution();
        return 1;
    }
    int found = 0;
    for (col = 0; col < n; col++)
    {
        if (isSafe(row, col))
        {
            board[row][col] = 1;
            if (solveNQueens(row + 1))
                found = 1;
            board[row][col] = 0;
        }
    }
    return found;
}
int main()
{
    printf("Enter the value of N: ");
    scanf("%d", &n);
    if (n < 1 || n > 20)
    {
        printf("Enter N between 1 and 20\n");
        return 0;
    }
    if (!solveNQueens(0))
        printf("No solution exists\n");
    return 0;
}

