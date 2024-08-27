#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int pid;
    int at;
    int bt;
    int ct; 
    int tt;
    int wt;
    int finished;
} process;
void sjfNP(process p[],int n){
    int et=0,temp,exec,idle=0;
    int tWt=0,tTT=0;
    float avgWT=0,avgTT=0;
    int remaining=n;
    while(remaining){
        exec=-1;
        int shortest=9999;
        for (int i = 0; i < n; i++)
        {
            if(!p[i].finished && p[i].at<=et){
                if(p[i].bt<shortest){
                    exec=i;
                    shortest=p[i].bt;
                }else if (p[i].bt==shortest)
                {
                    if (p[i].at<p[exec].at)
                    {
                        exec=i;
                    }
                    
                }
                
            }
        }
        if(exec>-1){
            if (idle>0)
            {
                printf("|idle %d|",et);
    
            }
            idle=0;
            int temp=et;
            et+=p[exec].bt;
            p[exec].finished=1;
            p[exec].ct=et;
            p[exec].tt=p[exec].ct-p[exec].at;
            p[exec].wt=p[exec].tt-p[exec].bt;
            printf("|(%d) P%d (%d)|",temp,p[exec].pid,et);
            remaining--;
        }
        else{
            idle++;
            et++;
        }
        
    }
    printf("|\n");
    printf("|| Observation table ||\n");
    printf("pID\tAT\tBT\tCT\tTT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tt,p[i].wt);
        tWt+=p[i].wt;
        tTT+=p[i].tt;
    }
    printf("\navgWt>> %f",(float)tWt/n);
    printf("\navgTt>> %f",(float)tTT/n);

    
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
        p[i].finished=0;
    }
    sjfNP(p,n);
    return 0;
    
}