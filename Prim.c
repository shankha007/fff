#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int g[10][10],n;
bool mstSet[10];
FILE *f;
typedef struct node
{
	int dist;
	int paren;
}node;

node v[10];

void readGraph()
{
	f=fopen("graph2","r");
	fscanf(f, "%d",&n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			fscanf(f, "%d",&g[i][j]);
}

void printGraph()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			printf("%d\t",g[i][j]);
		printf("\n");
	}
}

void printMST()
{
	printf("Edge \tWeight\n"); 
    for (int i = 1; i < n; i++) 
        printf("%d - %d \t%d \n", v[i].paren, i, g[i][v[i].paren]);
}

int extractMin() 
{ 
    int min = 9999, min_index; 
    for (int i = 0; i < n; i++) 
        if (mstSet[i] == false && v[i].dist < min) 
            min = v[i].dist, min_index = i; 
  
    return min_index; 
}

void prim(int s)
{
	for(int i=0;i<n;i++)
		mstSet[i]=false;
	for(int i=0;i<n;i++)
		v[i].dist=9999;
	v[s].dist=0;
	v[s].paren=-1;
	for(int k=0;k<n-1;k++)
	{
		int u=extractMin();
		mstSet[u]=true;
		for(int i=0;i<n;i++)
		{
			if(g[u][i] && mstSet[i]==false && v[i].dist>g[u][i])
			{
				v[i].dist=g[u][i];
				v[i].paren=u;
			}
		}
	}
	
	printMST();
}

void main()
{
	int source;
    readGraph();
    printf("\nSo, the adjacency matrix is:\n");
    printGraph();
    printf("\nEnter the source vertex:");
    scanf("%d",&source);
    prim(source);
}
