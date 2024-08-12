#include<stdio.h>
typedef struct{
    int pid;
    int at;
    int bt;
    int ct;
    int tt;
    int wt;
    int rt;
    int pri;    
}Process;
void fcfs(Process[],int);
int main(){
    int n;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    Process p[n];
    
    for(int i=0; i<n; i++){
        p[i].pid=i+1;
        printf("Process %d\n",i+1);
        printf("Arrival Time: ");
        scanf("%d",&p[i].at);
        printf("burst time: ");
        scanf("%d",&p[i].bt);
        printf("\n");
    }//for(takes process values)
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(p[j].at>=p[j+1].at){
                Process temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
            
        }
    }
    fcfs(p,n);
    return 0;
}//main
void fcfs(Process p[],int n){
    int et=0;
    float avgWT=0;
    float avgTT=0;
    float avgRT=0;
    int totalWT=0;
    int totalTT=0;
    int totalRT=0;

    printf("\n||| Gantt chart |||\n");
    for(int i=0;i<n;i++){
        if(p[i].at>et)
            et=et+(p[i].at - et);
        int temp=et;
        p[i].rt=et-p[i].at;
        et+=p[i].bt;
        p[i].ct=et;
        p[i].tt=p[i].ct-p[i].at;
        p[i].wt=p[i].tt-p[i].bt;
        printf("|(%d) P%d (%d)|",temp,p[i].pid,et);
    }
    printf("|\n");
    printf("||| Observation table |||\n");
    printf("pID\tAT\tBT\tCT\tTT\tWT\tRT\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tt,p[i].wt,p[i].rt);
        totalWT+=p[i].wt;
        totalRT+=p[i].rt;
        totalTT+=p[i].tt;
    }
    printf("\nAvgWT= %.2f",(float)totalWT/n);
    printf("\nAvgTT= %.2f",(float)totalTT/n);
    printf("\nAvgRT= %.2f",(float)totalRT/n);




}//fcfs










