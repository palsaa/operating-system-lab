#include<stdio.h>
#include<limits.h>
struct process{
	int pid,at,bt,pri;
	int ct;
};
int sorting(struct process p[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(p[j].at>p[j+1].at || (p[j].at==p[j+1].at && p[j].pri>p[j+1].pri))
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
	printf("eneter PID,PRIORITY,AT,BT : ");
	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&p[i].pid,&p[i].pri,&p[i].at,&p[i].bt);
	}
	sorting(p,n);
	for(int i=0;i<n;i++)
	{
		printf("%d\t%d\t%d\t%d\n",p[i].pid,p[i].pri,p[i].at,p[i].bt);
	}
	int sum=p[0].at;
	int ideal=0,index=0,f1,f2;
	while(1)
	{
		f1=0;
		f2=0;
		int priority=INT_MAX;
		for(int i=0;i<n;i++)
		{
			if(p[i].bt>0)
			{
				f1=1;
				if(sum>=p[i].at && p[i].pri<priority)
				{
					f2=1;
					index=i;
					priority=p[i].pri;	
				}
			}
		}
		printf("%d %d\n",f1,f2);
		if(f1==0)
		    break;
		else if(f2==1)
		{
			p[index].bt--;
			p[index].ct=1+sum;
			//printf(" find.....%d %d %d\n",p[index].pid,p[index].ct,p[index].bt);
			ideal=index;
			sum=sum+1;
			
		}
		else if(p[ideal].bt>0)
		{
			p[ideal].bt--;
			p[ideal].ct=1+sum;
			sum=sum+1;		
		}
		else
		    sum=sum+1;	
	}
	printf("PID\tCT\n");
	for(int i=0;i<n;i++)
	{
		printf("%d\t%d\n",p[i].pid,p[i].ct);
	}
	
}






