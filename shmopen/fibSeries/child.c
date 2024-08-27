#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/shm.h>
#include<sys/mman.h>
int main(int argc, char const *argv[])
{
    int k,n1=0,n2=1,n3;
    int shmid=shm_open("OS",O_CREAT | O_RDWR,0666);
    ftruncate(shmid,4096);
    void *ptr=mmap(0,4096,PROT_WRITE,MAP_SHARED,shmid,0);

    int n=atoi(argv[1]);
    sprintf(ptr,"%d ",n1);
    ptr+=strlen(ptr);
    sprintf(ptr,"%d ",n2);
    ptr+=strlen(ptr);
    for (int i = 2; i < n; i++)
    {
        n3=n1+n2;
        sprintf(ptr,"%d ",n3);
        ptr+=strlen(ptr);
        n1=n2;
        n2=n3;
    }
    
    

    return 0;
}
