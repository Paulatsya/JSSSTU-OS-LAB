#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
    pid_t child_pid;
    child_pid=fork();
    if(child_pid==0){
        printf("[CHILD]You are in Child process\n");
        printf("[CHILD]My pid>> %d parents pid>> %d\n",getpid(),getppid());
        printf("[CHILD]Now i am going to sleep so that parent can terminate\n");
        sleep(5);
        printf("[CHILD]My parent has been executed but I am still running, which makes the init process my parent\n");
        printf("[CHILD]Hence new parent(init) pid>> %d",getppid());
    }else if (child_pid>0)
    {
        printf("[PARENT]You are in the Parent processs\n");
        printf("[PARENT]My pid>> %d childs pid>> %d\n",getpid(),child_pid);
        printf("[PARENT]Terminating myself before child wakes up");
        exit(0);
       
    }else
    {
        printf("Fork failed!!\n");
        exit(0);
    }
    return 0;
    
}   