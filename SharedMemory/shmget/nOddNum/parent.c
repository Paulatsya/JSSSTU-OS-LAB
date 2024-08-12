#include <stdio.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct
{
    int n;
    int odd[100];
} pack;
int main()
{
    key_t key = 1000;
    int shmid = shmget(key, sizeof(pack), 0666 | IPC_CREAT);
    pack *shm_ptr = (pack *)shmat(shmid, NULL, 0);
    // user input
    printf("[PARENT]Created shared memory with key=%d , id=%d, address=%p\n", key, shmid, shm_ptr);
    printf("[PARENT]Enter n");
    scanf("%d", &shm_ptr->n);
    pid_t child_pid;
    child_pid = fork();
    if (child_pid == 0)
    {
        execlp("./child", "./child", NULL);
    }
    else
    {
        wait(NULL);
        printf("[PARENT]Child has finished execution");
        printf("[PARENT]The first %d odd numbers are:\n", shm_ptr->n);
        for (int i = 0; i < shm_ptr->n; i++)
        {
            printf("%d", shm_ptr->odd[i]);
        }
    }
    //cleanup
    shmdt((void *)shm_ptr);
    shmctl(shmid, IPC_RMID, NULL);
    printf("[PARENT]Memory deleted");
    return 0;

} // int main