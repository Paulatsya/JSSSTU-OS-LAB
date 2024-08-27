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
#include<stdlib.h>

int main(int argc, char *argv[])
{
    int shmid=shm_open("OS",O_CREAT | O_RDWR , 0666);
    ftruncate(shmid,4096);
    void *ptr=mmap(0,4096,PROT_WRITE,MAP_SHARED,shmid,0);
    
    int n=atoi(argv[1]);
    for (int i = 2; i <= n; i++)
    {
        int flag=0;
        for (int j = 2; j*j <= i; j++)
        {
            if(i % j==0){
                flag=1;
            }
        }
        if(flag==0){
            sprintf(ptr,"%d ",i);
            ptr+=strlen(ptr);
        }
    }
    
    return 0;
}
