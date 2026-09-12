#include <stdio.h>
#define MAX 64

void add(int A[MAX][MAX],int B[MAX][MAX],int C[MAX][MAX],int n){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            C[i][j]=A[i][j]+B[i][j];
}

void sub(int A[MAX][MAX],int B[MAX][MAX],int C[MAX][MAX],int n){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            C[i][j]=A[i][j]-B[i][j];
}

void strassen(int A[MAX][MAX],int B[MAX][MAX],int C[MAX][MAX],int n){
    if(n==1){
        C[0][0]=A[0][0]*B[0][0];
        return;
    }

    int k=n/2,i,j;
    int A11[MAX][MAX]={0},A12[MAX][MAX]={0};
    int A21[MAX][MAX]={0},A22[MAX][MAX]={0};
    int B11[MAX][MAX]={0},B12[MAX][MAX]={0};
    int B21[MAX][MAX]={0},B22[MAX][MAX]={0};
    int M1[MAX][MAX]={0},M2[MAX][MAX]={0},M3[MAX][MAX]={0};
    int M4[MAX][MAX]={0},M5[MAX][MAX]={0},M6[MAX][MAX]={0},M7[MAX][MAX]={0};
    int X[MAX][MAX]={0},Y[MAX][MAX]={0};

    for(i=0;i<k;i++)
        for(j=0;j<k;j++){
            A11[i][j]=A[i][j];       A12[i][j]=A[i][j+k];
            A21[i][j]=A[i+k][j];     A22[i][j]=A[i+k][j+k];
            B11[i][j]=B[i][j];       B12[i][j]=B[i][j+k];
            B21[i][j]=B[i+k][j];     B22[i][j]=B[i+k][j+k];
        }

    add(A11,A22,X,k); add(B11,B22,Y,k); strassen(X,Y,M1,k);
    add(A21,A22,X,k); strassen(X,B11,M2,k);
    sub(B12,B22,Y,k); strassen(A11,Y,M3,k);
    sub(B21,B11,Y,k); strassen(A22,Y,M4,k);
    add(A11,A12,X,k); strassen(X,B22,M5,k);
    sub(A21,A11,X,k); add(B11,B12,Y,k); strassen(X,Y,M6,k);
    sub(A12,A22,X,k); add(B21,B22,Y,k); strassen(X,Y,M7,k);

    for(i=0;i<k;i++)
        for(j=0;j<k;j++){
            C[i][j]=M1[i][j]+M4[i][j]-M5[i][j]+M7[i][j];
            C[i][j+k]=M3[i][j]+M5[i][j];
            C[i+k][j]=M2[i][j]+M4[i][j];
            C[i+k][j+k]=M1[i][j]-M2[i][j]+M3[i][j]+M6[i][j];
        }
}

int main(){
    int A[MAX][MAX]={0},B[MAX][MAX]={0},C[MAX][MAX]={0};
    int r1,c1,r2,c2,size=1,i,j;

    printf("Enter rows and columns of A: ");
    scanf("%d%d",&r1,&c1);

    printf("Enter rows and columns of B: ");
    scanf("%d%d",&r2,&c2);

    if(c1!=r2){
        printf("Matrix multiplication not possible.\n");
        return 0;
    }

    printf("Enter Matrix A:\n");
    for(i=0;i<r1;i++)
        for(j=0;j<c1;j++)
            scanf("%d",&A[i][j]);

    printf("Enter Matrix B:\n");
    for(i=0;i<r2;i++)
        for(j=0;j<c2;j++)
            scanf("%d",&B[i][j]);

    /* Find required square size */
    while(size<r1 || size<c1 || size<r2 || size<c2)
        size*=2;

    strassen(A,B,C,size);

    printf("Result Matrix:\n");
    for(i=0;i<r1;i++){
        for(j=0;j<c2;j++)
            printf("%d ",C[i][j]);
        printf("\n");
    }

    return 0;
}
