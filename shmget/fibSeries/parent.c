#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/ipc.h>
#include<sys/shm.h>
int main(int argc, char  *argv[])
{
    key_t key=1;
    int shmid=shmget(key,4096,0666 | IPC_CREAT);
    void *ptr=shmat(shmid,NULL,0);
    pid_t child_pid=fork();
    if(child_pid==0){
        execlp("./child","./child",argv[1],NULL);
    }
    else{
        wait(NULL);
        printf("\n[PARENT] ");
        printf("%s",(char *)ptr);
    }
    shmdt(ptr);
    shmctl(shmid,IPC_RMID,0);
    return 0;
}
