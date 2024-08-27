#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int pid;
    int at;
    int bt;
    int ct; 
    int tt;
    int wt;
} process;
void fcfs(process[],int);
int main(){
    int n;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    process p[n];
    
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
            if(p[j].at>p[j+1].at){
                process temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
            
        }
    }
    fcfs(p,n);
    return 0;
}//main
void fcfs(process p[],int n){
    int et=0;
    int tWT=0,tTT=0;
    float avgWT=0,avgTT=0;
    printf("|| GANTT CHART ||\n");
    for (int i = 0; i < n; i++)
    {
        if(p[i].at>et)
            et+=(p[i].at-et);
        int temp=et;
        et+=p[i].bt;
        p[i].ct=et;
        p[i].tt=p[i].ct-p[i].at;
        p[i].wt=p[i].tt-p[i].bt;
        printf("|(%d) P%d (%d)|",temp,p[i].pid,et);
    }
    printf("|\n");
    printf("|| Observation Table ||\n");
    printf("pID\tAT\tBT\tCT\tTT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tt,p[i].wt);
        tTT+=p[i].tt;
        tWT+=p[i].wt;
    }
    printf("\nAvgWt>> %f",(float)tWT/n);
    printf("\nAvgTt>> %f",(float)tTT/n);
    
}  