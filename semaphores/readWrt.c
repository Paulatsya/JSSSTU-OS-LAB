#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
int count=1;
sem_t wrt;
pthread_t write[3],read[3];
pthread_mutex_t mutex;
int numReader=0;
void *writer(void *wno){
    sem_wait(&wrt);
    count*=2;
    printf("Writer %d writing %d\n",*((int *)wno),count);
    sem_post(&wrt);
}
void *reader(void *rno){
    pthread_mutex_lock(&mutex);
    if(++numReader==1)
        sem_wait(&wrt);
    pthread_mutex_unlock(&mutex);
    printf("Reader %d reading %d\n",*(int *)rno,count);
    pthread_mutex_lock(&mutex);
    
    if(!--numReader)
        sem_post(&wrt);
    pthread_mutex_unlock(&mutex);
}
int main()
{
    int a[3]={1,2,3};
    sem_init(&wrt,0,1);
    pthread_mutex_init(&mutex,NULL);
    for (int i = 0; i < 3; i++)
    {
        pthread_create(&write[i],NULL,writer,(void *)&a[i]);
        pthread_create(&read[i],NULL,reader,(void *)&a[i]);
    }
    for (int i = 0; i < 3; i++)
    {
        pthread_join(write[i],NULL);
        pthread_join(read[i],NULL);
    }
    
    return 0;
}
