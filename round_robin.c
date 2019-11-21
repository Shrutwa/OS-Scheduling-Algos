#include<stdio.h>
#include<stdlib.h>
struct pro{
	int id,at,bt,ct,tat,wt,u_bt;
	//int b;
};
struct node
{
    int pid;
    struct node * ptr;
};
struct node * insert_at_tail(struct node *h,int pid)
{
    struct node *t;
    t=h;
    struct node * newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("Malloc failed \n");
        exit(-1);
    }
    if(h==NULL)
    {
        newnode->pid=pid;
        newnode->ptr=NULL;
        h=newnode;
        return h;
    }
        while((t->ptr)!=NULL)
        t=t->ptr;

        newnode->pid=pid;
        newnode->ptr=NULL;
        t->ptr=newnode;
        return h;
}
struct node * delete_front(struct node *h)
{
        struct node * deletethis;
        if(h==NULL)
        {
            printf("List is empty\n");
            exit(-1);
        }
        deletethis=h;
        h=h->ptr;
        free(deletethis);
        return h;
};
void display(struct node *h)
{
    struct node *temp;
    temp=h;
    while(temp!=NULL)
    {
        printf("%d\n",temp->pid);
        temp=temp->ptr;
    }
}
void main()
{
	struct node * h;
	h=NULL;
	int n,tq;
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
		p[i].u_bt=p[i].bt;
		//p[i].b=0;
	}
	printf("Enter time quantum:");
	scanf("%d",&tq);
	int cur=0;
	int comp=0;
	int c_id;
	double a_tat=0.0;
	double a_wt=0.0;
    if(p[0].at>=cur){
        cur+=p[0].at;
        h=insert_at_tail(h,p[0].id);
        printf("%d ->",p[0].id);
        }
  	while(1)
    {
            c_id=h->pid;
            if(p[c_id-1].bt<=tq){
                h=delete_front(h);
                cur+=p[c_id-1].bt;
                comp++;
                for(int i=c_id;i<n;i++){
                    if(p[i].at>(cur-p[c_id-1].bt) && p[i].at<=cur){
                        h=insert_at_tail(h,p[i].id);
                        printf("%d ->",p[i].id);
                    }
                }
                p[c_id-1].ct=cur;
                p[c_id-1].tat=p[c_id-1].ct-p[c_id-1].at;
                p[c_id-1].wt=p[c_id-1].tat-p[c_id-1].u_bt;
                p[c_id-1].bt=0;
                a_tat+=p[c_id-1].tat;
                a_wt+=p[c_id-1].wt;
            }
            else{
                h=delete_front(h);
                p[c_id-1].bt-=tq;
                cur=cur+tq;
                for(int i=c_id;i<n;i++){
                    if(p[i].at>(cur-tq) && p[i].at<=cur){
                        h=insert_at_tail(h,p[i].id);
                        printf("%d ->",p[i].id);
                    }
                }
                h=insert_at_tail(h,p[c_id-1].id);
                printf("%d ->",p[c_id-1].id);
            }
         if(comp==n)
            break;
    }
    printf("\n");
    printf("PI:AT:BT:CT:TAT:WT\n");
    for(int i=0;i<n;i++)
	{

				printf("%d :%d :%d :%d :%d  :%d \n",p[i].id,p[i].at,p[i].u_bt,p[i].ct,p[i].tat,p[i].wt);
				printf("\n");
	}

	printf("Avg. tat: %f,Avg. wt: %f",(a_tat/n),(a_wt/n));
}
