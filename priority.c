#include<stdio.h>
struct pro{
	int id,at,bt,p,ct,tat,wt,b;
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
		printf("Enter priority for process %d :",i+1);
		scanf("%d",&p[i].p);
		printf("Enter arrival time for process %d :",i+1);
		scanf("%d",&p[i].at);
		printf("Enter burst time for process %d :",i+1);
		scanf("%d",&p[i].bt);
		p[i].ct=0;
		p[i].tat=0;
		p[i].wt=0;
		p[i].b=0;
	}
	double a_tat=0.0;
	double a_wt=0.0;
	int max_p;
	int max_id;
	int i=0;
	int comp=0;
	int cur=0;
	while(comp!=n)
	{
        if(p[i].at>cur && p[i].b==0)
            cur=p[i].at;
        max_p=0;
        max_id=0;
		for(int j=0;j<n;j++)
		{
			if(p[j].at<=cur && p[j].b==0)
			{
				if(p[j].p>max_p)
				{
					max_p=p[j].p;
					max_id=p[j].id;
				}
			}
		}
		p[max_id-1].ct=cur+p[max_id-1].bt;
		p[max_id-1].tat=p[max_id-1].ct-p[max_id-1].at;
		p[max_id-1].wt=p[max_id-1].tat-p[max_id-1].bt;
		p[max_id-1].b=1;
		cur+=p[max_id-1].bt;
        a_tat+=p[max_id-1].tat;
        a_wt+=p[max_id-1].wt;
        comp++;
        i++;
	}
	printf("PI:P :AT:BT:CT:TAT:WT\n");
	for(int i=0;i<n;i++)
	{
				printf("%d :%d :%d :%d :%d :%d  :%d\n",p[i].id,p[i].p,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
				printf("\n");
	}
	printf("Avg. tat: %f,Avg. wt: %f\n",(a_tat/n),(a_wt/n));
}

