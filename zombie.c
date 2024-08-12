#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    pid_t child_pid, my_pid, parent_pid;
    child_pid=fork();

    if(child_pid<0){
        printf("fork failed");
        exit(0);
    }//if
    if(child_pid==0){//child process
        printf("[CHILD]I am the child process.\n");
        my_pid=getpid();
        parent_pid=getppid();
        printf("[CHILD]My pid is %d\n",my_pid);
        printf("[CHILD]My parents pid is %d\n",parent_pid);
        printf("[CHILD]Terminating\n");
        exit(0);
    }//if
    else{
        //parent process
        my_pid=getpid();
        parent_pid=getppid();
        printf("[Parent]I am the parent process\n");
        printf("[Parent]My PID is %d\n",my_pid);
        printf("[PARENT]My parents PID is %d\n",parent_pid);
        printf("[Parent]Sleeping 10 seconds\n");
        sleep(10);
        printf("[Parent]Child PID=%d has ended, but it has an entry in the pid_t, it is a Zombie!!",child_pid);
    }//else
}//int main