#include<stdio.h>
struct pro{
	int id,at,bt,t_bt,ct,tat,wt,b;
};
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
		printf("Enter burst time for process %d :",i+1);
		scanf("%d",&p[i].bt);
		p[i].t_bt=p[i].bt;
		p[i].ct=0;
		p[i].tat=0;
		p[i].wt=0;
		p[i].b=0;
	}
	double a_tat=0.0;
	double a_wt=0.0;
	int cur=0;
	int min_bt=99999;
	int min_id=0;
	int j;
	int comp=0;
	printf("PI:AT:BT:CT:TAT:WT\n");
	while(1)
	{
		min_bt=99999;
		for(int j=0;j<n;j++)
		{
			if(p[j].at<=cur && p[j].b==0)
			{
				if(p[j].bt<min_bt)
				{
					min_bt=p[j].bt;
					min_id=p[j].id;
				}
			}
		}
		p[min_id-1].bt=p[min_id-1].bt-1;
		cur+=1;
		if(p[min_id-1].bt==0)
        {
            p[min_id-1].ct=cur;
            p[min_id-1].tat=p[min_id-1].ct-p[min_id-1].at;
            p[min_id-1].wt=p[min_id-1].tat-p[min_id-1].t_bt;
            p[min_id-1].b=1;
            a_tat+=p[min_id-1].tat;
            a_wt+=p[min_id-1].wt;
            comp++;
		}
        if(comp==n)
            break;
	}
	for(int i=0;i<n;i++)
	{
				printf("%d :%d :%d :%d :%d  :%d\n",p[i].id,p[i].at,p[i].t_bt,p[i].ct,p[i].tat,p[i].wt);
				printf("\n");
	}
	printf("Avg. tat: %f,Avg. wt: %f",(a_tat/n),(a_wt/n));
}
