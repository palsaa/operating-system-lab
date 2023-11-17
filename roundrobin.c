#include<stdio.h>
struct process{
	int pid,at,bt,ct,tat,wt;
};
int sorting(struct process p[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(p[j].at>p[j+1].at)
			{
				struct process temp;
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
			}
		}
	}
}
int main()
{
	int n;
	printf("enter the number of processess : ");
	scanf("%d",&n);
	struct process p[n];
	int visit[n];
	printf("enter the PID AT BT :\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d",&p[i].pid,&p[i].at,&p[i].bt);
		visit[i]=-1;
	}
	sorting(p,n);
	int bt[n];
	for(int i=0;i<n;i++)
	{
		bt[i]=p[i].bt;
		printf("%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt);
	}
	int tq;
	printf("enter the time quantum : ");
	scanf("%d",&tq);
	int queue[50];
	int front=0,rear=0;
	int sum=0;
	if(p[0].bt<=tq)
	{
		sum=p[0].bt+p[0].at;
		p[0].ct=sum;
		p[0].bt=0;	
	}
	else
	{
		sum=sum+tq+p[0].at;
		p[0].ct=sum;
		p[0].bt=p[0].bt-tq;		
	}
	for(int i=1;i<n;i++)
	{
		if(p[i].at<=sum)
		{
			queue[rear++]=p[i].pid;
			visit[p[i].pid]=p[i].pid;
		}
	}
	if(p[0].bt>0)
		queue[rear++]=p[0].pid;
	while(1)
	{
		int k=queue[front++];
		if(p[k].bt<=tq)
		{
			sum=sum+p[k].bt;
			p[k].ct=sum;
			p[k].bt=0;	
		}
		else
		{
			sum=sum+tq;
			p[k].ct=sum;
			p[k].bt=p[k].bt-tq;		
		}
		for(int i=0;i<n;i++)
		{
			if(p[i].at<=sum && visit[p[i].pid]==-1)
			{
				queue[rear++]=p[i].pid;
				visit[p[i].pid]=p[i].pid;
			}
		}
		if(p[k].bt>0)
			queue[rear++]=p[k].pid;
		if(front==rear)
			break;
			
	}
	for(int i=0;i<n;i++)
	{
		p[i].tat=p[i].ct-p[i].at;
		p[i].wt=p[i].tat-bt[i];
	}
	printf("\n");
	printf("the solution is: \n");
	printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
	for(int i=0;i<n;i++)
	{
		printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,bt[i],p[i].ct,p[i].tat,p[i].wt);
	}
	
	
	
}









