#include<stdio.h>
#include<stdlib.h>

int a[10][10],n,v[10],source;
void input();
void dfs(int);
void output();
int main()
{
	input();
	dfs(source);
	output();
	return 0;
}

void input()
{
	int i,j;
	printf("enter the no of nodes:");
	scanf("%d",&n);
	printf("enter the adjacency matrix:");
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		scanf("%d",&a[i][j]);
	printf("enter the source vertex: ");
	scanf("%d",&source);
	for(i=1;i<=n;i++)
		v[i]=0;
}

void dfs(int s)
{
	int k;
	v[s]=1;
	for(k=1;k<=n;k++)
	{
	 if(a[s][k]==1 && v[k]==0)
	  {
		printf("%d->%d",s,k);
		dfs(k);
	  }
	}

}

void output()
{
	int i;
	for(i=1;i<=n;i++)
	{
	 if(v[i]==0)
		printf("%d not reachable\n",i);
	else
		printf("%d reachable\n",i);
	}
}	
