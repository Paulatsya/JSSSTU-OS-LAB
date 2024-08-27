#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
    pid_t child_pid;
    child_pid=fork();
    if(child_pid==0){
        printf("[CHILD]You are in the child process\n");
        printf("[CHILD]My pid>> %d parent pid>> %d\n",getpid(),getppid());
        printf("[CHILD]Exiting.....\n");
        exit(0);
    }
    else if (child_pid>0)
    {
        
        printf("[PARENT]You are in the Parent process\n");
        printf("[PARENT]My pid>> %d Childs pid>> %d",getpid(),child_pid);
        printf("[PARENT]I am going to sleep\n");
        sleep(10);
        printf("[PARENT]My child: %d has been terminated but still exists in my proccess table\n",child_pid);
        exit(0);
    }
    else{
        printf("Fork failed!!\n");
    }
    return 0;
}
