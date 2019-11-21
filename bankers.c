#include<stdio.h>

int check(int m,int avail[m],int need[m]){
    int f=1;
    for(int i=0;i<m;i++){
        if(avail[i]<need[i])
            f=0;
    }
    return f;

}

void main()
{
    int n,m;
    printf("Enter no. of process:\n");
    scanf("%d",&n);
    printf("Enter no. of resources:\n");
    scanf("%d",&m);
    int alloc[n][m];
    int max[n][m];
    int need[n][m];
    int t_r[m];
    int a[m];
    int avail[m];
    int f_p[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter for process: %d\n",i+1);
        for(int j=0;j<m;j++)
        {
                printf("Enter allocated value for resource: %d\n",j+1);
                scanf("%d",&alloc[i][j]);
                printf("Enter maximum value for resource: %d\n",j+1);
                scanf("%d",&max[i][j]);
                need[i][j]=max[i][j]-alloc[i][j];
                a[j]+=alloc[j][i];
        }
    }
    for(int i=0;i<m;i++){
        a[i]=0;
        for(int j=0;j<n;j++)
        {
            a[i]+=alloc[j][i];
        }
    }
    for(int i=0;i<n;i++)
        f_p[i]=0;
    for(int i=0;i<m;i++)
    {
        printf("Enter total resources for resource: %d\n",i+1);
        scanf("%d",&t_r[i]);
    }
    printf("Allocated :\n");
    for(int k=0;k<m;k++)
    {
        printf("%d ",a[k]);
        avail[k]=t_r[k]-a[k];
    }
    printf("\nAvailable :\n");
    for(int k=0;k<m;k++)
    {
        printf("%d ",avail[k]);
    }
    printf("\nOutput:\n");
    int comp=0;
    int p;
    for(int q=0;q<8;q++)
    {
    for(p=0;p<n;p++)
        {
            if(check(m,avail,need[p])==1 && f_p[p]==0){
                comp++;
                f_p[p]=1;
                for(int j=0;j<m;j++){
                    avail[j]+=alloc[p][j];
                }
                printf("%d ->",(p+1));
                break;
            }
        }
        if(p==n){
            printf("DEADLOCK\n");
            break;
        }
        if(comp==n)
            break;

    }

}
