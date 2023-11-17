#include<stdio.h>
#include<limits.h>
struct block{
	int pid,size;
};
int main()
{
	int n,m;
	printf("enter the number of blocks of memory : ");
	scanf("%d",&n);
	printf("enter the each block capacity : \n");
	struct block b[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&b[i].size);
		b[i].pid=-1;
	}
	printf("enter the number of process : ");
	scanf("%d",&m);
	int p[m];
	printf("enter the each process size : \n");
	for(int i=0;i<m;i++)
		scanf("%d",&p[i]);
	int index;
	for(int i=0;i<m;i++)
	{
		int min=INT_MAX,flag=0;
		for(int j=0;j<n;j++)
		{
			if(b[j].pid==-1 && p[i]<=b[j].size && b[j].size<min)
			{
				flag=1;
				min=b[j].size;
				index=j;	
			}
		}
		if(flag==1)
		   b[index].pid=i;
	}
	printf("THE SOLUTION USING BEST FIT IS : \n");
	printf("BLOCK_NUMBER\tPROCESSOR_ID\tFRAGMENTATION: \n");
	for(int i=0;i<n;i++)
	{
		if(b[i].pid!=-1)
		   printf("%d\t\t%d\t\t%d\n",i+1,b[i].pid+1,(b[i].size-p[b[i].pid]));
		else
		  printf("%d\t\t-\t\t-\n",i+1);
	}	
	
	
}
