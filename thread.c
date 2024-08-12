#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
int sm=0,prod=1;
void *sum(void *arg);
void *mul(void *arg);
int main(int argc, char *argv[])
{
    pthread_t t1,t2;
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    pthread_create(&t1,&attr,sum,argv[1]);
    pthread_create(&t2,&attr,mul,argv[1]);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);

    printf("Inside main thread\n");
    printf("sum=%d",sm);
    printf("mul=%d",prod);
    return 0;
}
void *sum(void *parm){
    int i,n;
    n=atoi(parm);
    printf("inside sum thread");
    for(i=0;i<=n;i++){
        sm+=i;
    }
    printf("sum thread completed\n");
    return NULL;
}
void *mul(void *parm){
    int i,n;
    n=atoi(parm);
    printf("Inside mul thread\n ");
    for(i=2;i<=n;i++){
        prod*=i;
    }
    printf("Completed mul thread\n");
    return NULL;
}