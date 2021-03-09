#include<stdio.h>
#include<conio.h>
struct DisjSet
{
	int parent[10];
	int rank[10];
	int n;
}dis;

void makeSet()
{
	int i;
	for(i=0;i<dis.n;i++)
	{
		dis.parent[i]=i;
		dis.rank[i]=0;
	}
}

void displaySet()
{
	int i;
	printf("\n Parent array : \n ");
	for(i=0;i<dis.n;i++)
	{
		printf("%d",dis.parent[i]);
	}
	printf("\n rank array : \n");
	for(i=0;i<dis.n;i++)
	{
		printf("%d",dis.rank[i]);
	}
	printf("\n");
}

int find(int x)
{
	if(dis.parent[x]!=x)
	{
		dis.parent[x]=find(dis.parent[x]);
	}
	return dis.parent[x];
}

void Union(int x,int y)
{
	int xset=find(x);
	int yset=find(y);
	if(xset==yset)
		return;
	if(dis.rank[xset]<dis.rank[yset])
	{
		dis.parent[xset]=yset;
		dis.rank[xset]=-1;
	}
	else if(dis.rank[xset]>dis.rank[yset])
	{
		dis.parent[yset]=xset;
		dis.rank[yset]=-1;
	}
	else
	{
		dis.parent[yset]=xset;
		dis.rank[xset]=dis.rank[xset]+1;
		dis.rank[yset]=-1;
	}
}

int main()
{
	int n,x,y;
	int ch,wish;
	clrscr();
	printf("\nhow many elements ? ");
	scanf("%d",&dis.n);
	makeSet();

	printf("\n menu \n");
	printf("1.union.\n2.find.\n3.display\n");

	do
	{
		printf("\nEnter a choice :  ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("enter the elements to union : ");
			scanf("%d %d",&x,&y);
			Union(x,y);
			break;
			case 2:
				printf("enter elements to check connected component : ");
				scanf("%d %d",&x,&y);
				if(find(x)==find(y))
				{
					printf("\nconnected");
				}
				else
					printf("\n not connected");
				break;
			case 3:displaySet();
				break;
			}
		printf("\ndo you wish to ontinue : (1/0)");
		scanf("%d",&wish);
	}while(wish==1);
return 0;
}