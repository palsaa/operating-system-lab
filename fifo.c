#include<stdio.h>
int main()
{
	int n;
	printf("enter the size of reference string : ");
	scanf("%d",&n);
	int str[n];
	printf("enter the string values :\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&str[i]);
	}
	int m;
	printf("enter the number of frames : ");
	scanf("%d",&m);
	int frame[m];
	for(int i=0;i<m;i++)
		frame[i]=-1;
	int ptr=0;
	int k=0;
	int count=0;
	for(int i=0;i<n;i++)
	{
		int flag=0;
		if(k<m)
		{
			for(int j=0;j<m;j++)
			{
				if(str[i]==frame[j])
				    flag=1;
			}
			if(flag==0)
			{
				frame[k++]=str[i]; 
				count++; 
		        } 
		}
		else
		{
			for(int j=0;j<m;j++)
			{
				if(str[i]==frame[j])
				    flag=1;
			}
			if(flag==0)
			{
				frame[ptr]=str[i];
				ptr=(ptr+1)%m;
				count++; 
			}
		
		}
		
		   
	}
	printf("the number of page faults are : %d\n",count);
}
