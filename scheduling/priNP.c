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
    int finished;
}Process;
void priNP(Process[],int);
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
        printf("Pri: ");
        scanf("%d",&p[i].pri);
        printf("\n");
    }//for(takes process values)2