#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int pid;
    int at;
    int bt;
    int pri;
    int ct; 
    int tt;
    int wt;
    int finished;
} process;
void priNP(process p[],int n){
    int et=0,temp,priority,remaining=n,exec,idle=0;
    int tTT=0,tWT=0;
    float avgTT=0,avgWt=0;
    printf("GANTT CHART\n");
    while(remaining){
        priority=9;
        exec=-1;
        for (int i = 0; i < n; i++)
        {
            if(!p[i].finished && p[i].at<=et){
                if(p[i].pri<priority){
                    exec=i;
                    priority=p[i].pri;
                }
                else if (p[i].pri==priority)
                {
                    if(p[i].at<p[exec].at){
                        exec=i;
                    }
                }
                
            }
        }
        if(exec>-1){
            if(idle>0){
                printf("|***(%d)",et);
                idle=0;
            }
            temp=et;
            et+=p[exec].bt;
            p[exec].ct=et;
            p[exec].tt=p[exec].ct-p[exec].at;
            p[exec].wt=p[exec].tt-p[exec].bt;
            p[exec].finished=1;
            printf("|(%d) P%d (%d)|",temp,p[exec].pid,et);
            remaining--;
        }else
        {
            et++;
            idle++;
        }
        
        
    }
    printf("\n");
    printf("Observation table\n");
    printf("pID\tAT\tPRI\tBT\tCT\tTT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].pri,p[i].bt,p[i].ct,p[i].tt,p[i].wt);
        tTT+=p[i].tt;
        tWT+=p[i].wt;
    }
    printf("AvgTT>> %d",(float)tTT/n);
    printf("AvgWT>> %d",(float)tWT/n);
}
int main(){
    int n;
    printf("Enter number of process>> ");
    scanf("%d",&n);
    process p[n];
    for (int i = 0; i < n; i++)
    {
        p[i].pid=i+1;
        printf("Process %d\n",i+1);
        printf("Arrival Time: ");
        scanf("%d",&p[i].at);
        printf("Burst time: ");
        scanf("%d",&p[i].bt);
        printf("Pri: ");
        scanf("%d",&p[i].pri);
        printf("\n");
        p[i].finished=0;
    }
    priNP(p,n);
    return 0;
    
}