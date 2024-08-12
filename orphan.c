#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
    pid_t myPid,childPid,parentPid;
    childPid=fork();
    if(childPid<0){
        printf("Error in creating a chlid\n");
        exit(0);
    }//if check id child created
    if(childPid==0){
        myPid=getpid();
        parentPid=getppid();
        printf("[CHILD]My pid=%d\n[CHILD]My Parent's pid=%d\n ",myPid,parentPid);
        printf("[CHILD]Sleeping\n");
        sleep(10);//child adopted by init
        parentPid=getppid();
        printf("[CHILD]My new parents PID=%d\n",parentPid);
    }//child process
    else{
        myPid=getpid();
        parentPid=getppid();
        printf("[PARENT]My pid=%d\n[PARENT]My Parent's pid=%d\n ",myPid,parentPid);
        printf("[PARENT]EXITING\n");
        exit(0);
    }
}//int main