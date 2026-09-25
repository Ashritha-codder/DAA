#include <stdio.h>
#define MAX 20
#define INF 9999
int main(){
	int n,graph[MAX][MAX];
	int selected[MAX]={0};
	int edges=0,total=0;

	printf("Enter number of vertices:");
	scanf("%d",&n);
	printf("Enter adjacency matrix:\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&graph[i][j]);
		}
	}
	selected[0]=1;

	printf("\nPrim's MST:\n");
	while(edges < n-1) {
		int min = INF;
		int u = -1,v = -1;

		for(int i = 0;i<n;i++) {
			if(selected[i]){
				for(int j=0;j<n;j++){
					if(!selected[j] && graph[i][j]!=0 && graph[i][j]<min){
						min=graph[i][j];
						u=i;
						v=j;
					}
				}
			}
		}
		printf("%d - %d : %d\n",u,v,min);
		total += min;
		selected[v] = 1;
		edges++;
	}
	printf("Total Cost = %d\n",total);
	return 0;
}

