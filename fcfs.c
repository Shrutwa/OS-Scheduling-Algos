#include<stdio.h>

struct pro{
	int id,at,bt,ct,tat,wt;
};

void sort(int n,struct pro p[n])
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n-1;j++)
		{
			if(p[j].at > p[j+1].at)
			{
				struct pro temp = p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
			}
		}
}
void main()
{
	int n;
	printf("Enter the no. of process");
	scanf("%d",&n);
	struct pro p[n];
	for(int i=0;i<n;i++)
	{
		p[i].id=i+1;		
		printf("Enter arrival time for process %d :",i+1);
		scanf("%d",&p[i].at);
		printf("Enter bust time for process %d :",i+1);
		scanf("%d",&p[i].bt);
		p[i].ct=0;
		p[i].tat=0;
		p[i].wt=0;
	}
	sort(n,p);	
	double a_tat=0.0;
	double a_wt=0.0; 
	int cur=0;
	printf("PI:AT:BT:CT:Tat:WT\n");
	for(int i=0;i<n;i++)
	{
		if(cur<p[i].at){
			cur=p[i].at;
		}		
		p[i].ct=p[i].bt + cur;
		cur=cur+p[i].bt;		
		p[i].tat=p[i].ct-p[i].at;
		p[i].wt=p[i].tat-p[i].bt;
		a_tat+=p[i].tat;
		a_wt+=p[i].wt;		
		printf("%d :%d :%d :%d :%d  :%d\n",p[i].id,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
	}	
	double m=n;
	printf("Avg. tat: %f,Avg. wt: %f,eff. : %f",(a_tat/n),(a_wt/n),(m/cur));	
}

