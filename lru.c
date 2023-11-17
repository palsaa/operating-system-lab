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
				{
					for(int p=j;p<k-1;p++)
					{
						frame[p]=frame[p+1];
					}
					frame[k-1]=str[i];
					flag=1;
				}
				if(flag==1)
				   break;
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
				{
					for(int p=j;p<m-1;p++)
					{
						frame[p]=frame[p+1];
					}
					frame[m-1]=str[i];
					flag=1;
				}
				if(flag==1)
				    break;
			}
			if(flag==0)
			{
					for(int j=0;j<m-1;j++)
					{
						frame[j]=frame[j+1];
					}
					frame[m-1]=str[i];
					count++;			
			}
		
		}
		
		   
	}
	printf("the number of page faults are : %d\n",count);
}
