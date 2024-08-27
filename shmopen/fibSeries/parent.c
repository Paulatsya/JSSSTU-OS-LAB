#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/shm.h>
#include<sys/mman.h>

int main(int argc, char *argv[])
{
    int shmid;
    pid_t child_pid;
    void *ptr;
    child_pid=fork();
    if(child_pid==0){
        execlp("./child","./child",argv[1],NULL);
    }
    else if (child_pid>0)
    {
        wait(NULL);
        printf("\n[PARENT]\n");
        shmid=shm_open("OS",O_RDONLY,0666);
        ptr=mmap(0,4096,PROT_READ,MAP_SHARED,shmid,0);
        printf("%s\n",(char *)ptr);
        shm_unlink("OS");
    }
    
    return 0;
}
