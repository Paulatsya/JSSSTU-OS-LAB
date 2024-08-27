#include<stdio.h>
#include<stdlib.h>
int timeProg[100],trackProc[100],k=-1,j=-1;
typedef struct{
    int pid,at,bt,ct,tt,wt,remainingTime;
}process;
void sjfPre(process p[],int n){
    int et=0,tTT=0,tWT=0,incomplete=n,exec,shortest;
    float avgWT=0,avgTT=0;
    timeProg[++j]=0;
    while(incomplete){
        exec=-1;
        shortest=99;
        for (int i = 0; i < n; i++)
        {
            if(p[i].at<=et && p[i].remainingTime>0){
                if(p[i].remainingTime<shortest){
                    exec=i;
                    shortest=p[i].remainingTime;
                }else if (p[i].remainingTime==shortest) 
                {
                    if(p[i].at<p[exec].at){
                        exec=i;
                        shortest=p[i].remainingTime;
                    }
                }
                
                

            }
        }
        if(exec==-1){
            et++;
            timeProg[++j]=et;
            trackProc[++k]=0;
            continue;
        }
        p[exec].remainingTime--;
        et++;
        timeProg[++j]=et;
        trackProc[++k]=p[exec].pid;

        if (p[exec].remainingTime==0)//process is done 
        {
            p[exec].ct=et;
            p[exec].tt=p[exec].ct - p[exec].at;
            p[exec].wt=p[exec].tt-p[exec].bt;
            tTT+=p[exec].tt;
            tWT+=p[exec].wt;
            incomplete--;

        }
        

    }
    printf("|| GANTT CHART ||\n");
    for (int i = 0; i <= k; i++)
    {
        printf("| P%d ",trackProc[i]);

    }
    printf("\n");
    for (int i = 0; i <= j; i++)
    {
        printf("%d    ",timeProg[i]);
    }
    printf("\n");

    printf("|| Observation table ||\n");
    printf("pID\tAT\tBT\tCT\tTT\tWT");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tt,p[i].wt);
    }
    printf("avgTT>> %f\n",(float)tTT/n);
    printf("avgWT>> %f\n",(float)tWT/n);        
    
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
        printf("\n");
        p[i].remainingTime=p[i].bt;
    }
    sjfPre(p,n);
    return 0;
    
}
