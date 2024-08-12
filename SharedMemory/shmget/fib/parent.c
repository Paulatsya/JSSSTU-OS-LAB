#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/shm.h>
#include<sys/ipc.h>
int main(int argc,char *argv[])
{
    int i;
    pid_t child_pid;
    int key=1234;
    int shmid=shmget(key,4096,0666 | IPC_CREAT);
    void *ptr=shmat(shmid,NULL,0);
    if(argc>1){
        sscanf(argv[1],"%d",&i);
        if(i<1){
            printf("Error input%d\n",i);
            return 0;
        }
    }
    else{
        return 1;
    }
    child_pid=fork();
    if(child_pid==0){
        execlp("./child","./child",argv[1],NULL); 
    }
    else if(child_pid>0){
        wait(NULL);
        printf("\n[PARENT]child completed\b");
        printf("%s",(char*) ptr);
        shmdt((void*)ptr);
        shmctl(shmid,IPC_RMID,NULL);
        printf("[PARENT]Memory deleted\n");
    }
    return 0;
}
