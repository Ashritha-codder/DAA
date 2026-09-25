#include <stdio.h>
#define MAX 20
struct Edge{
	int u,v,w;
};
int find(int parent[],int i) {
	while(parent[i] != i)
		i = parent[i];
		return i;
}
void unionset(int parent[],int u,int v){
	int a = find(parent,u);
	int b = find(parent,v);
	parent[b] = a;
}
int main() {
	int n,e,count = 0,total = 0;
	struct Edge edges[MAX*MAX],temp;
	int parent[MAX];
	
	printf("Enter number of vertices:");
	scanf("%d",&n);

	printf("Enter number of edges:");
	scanf("%d",&e);
	
	printf("Enter edges(u v weight):\n");
	for(int i=0;i<e;i++)
		scanf("%d %d %d",&edges[i].u,&edges[i].v,&edges[i].w);

	for(int i=0;i<e-1;i++){
		for(int j=i+1;j<e;j++){
			if(edges[i].w>edges[j].w){
				temp = edges[i];
				edges[i] = edges[j];
				edges[j] = temp;
			}
		}
	}
	for(int i = 0; i<n;i++)
		parent[i]=i;
	printf("\nKruskal's MST:\n");
	for(int i = 0; i<e && count < n-1;i++){
		if(find(parent,edges[i].u)!= find(parent,edges[i].v)) {
			printf("%d - %d : %d\n",edges[i].u,edges[i].v,edges[i].w);
			total +=edges[i].w;
			unionset(parent,edges[i].u,edges[i].v);
			count++;
		}
	}
	printf("Total Cost = %d\n",total);
	return 0;
}
