#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
int sm=0,prod=1;
void *sum(void *arg){
    int n=atoi(arg);
    printf("[T1]\n");
    for (int i = 1; i <= n; i++)
    {
        sm+=i;
    }
    printf("[T1]Completed\n");
    return NULL;
}
void *mul(void *arg){
    int n=atoi(arg);
    printf("[T2]\n");
    for (int i = 1; i <= n; i++)
    {
        prod*=i;
    }
    printf("[T2]Completed\n");
    return NULL;
}
int main(int argc,char *argv[])
{
    pthread_t t1,t2;
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    pthread_create(&t1,&attr,sum,argv[1]);
    pthread_create(&t2,&attr,mul,argv[1]);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);

    printf("Inside main thread\n");
    printf("sum=%d\n",sm);
    printf("mul=%d\n",prod);
    return 0;
}
