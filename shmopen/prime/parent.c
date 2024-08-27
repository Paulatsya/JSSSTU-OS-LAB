#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>
#include<unistd.h>
#include<sys/shm.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/mman.h>

int main(int argc, char  *argv[])
{
    pid_t child_pid = fork();
    if(child_pid==0){
        execlp("./child","./child",argv[1],NULL);
    }
    else if (child_pid>0)
    {
        wait(NULL);
        printf("[PARENT]\n");
        int shmid=shm_open("OS",O_RDONLY,0666);
        void *ptr=mmap(0,4096,PROT_READ,MAP_SHARED,shmid,0);
        printf("%s\n",(char *)ptr);
        shm_unlink("OS");
    }
    
    return 0;
}
