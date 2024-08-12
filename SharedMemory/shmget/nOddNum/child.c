#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <unistd.h>
#include <sys/shm.h>

typedef struct
{
    int n;
    int odd[100];
} pack;

int main()
{
    key_t key = 1000;
    int shmid = shmget(key, sizeof(pack), 0666);
    pack *shm_ptr = (pack *)shmat(shmid, NULL, 0);

    printf("[CHILD]Attached memory with key=%d, id=%d, address=%p\n", key, shmid, shm_ptr);
    int j = 0;
    for (int i = 0; i < shm_ptr->n; i++)
    {
        if ((i % 2) == 0)
            continue;
        else
        {
            shm_ptr->odd[j] = i;
            j++;
        }
    }
    printf("[CHILD]Finished generating first %d odd numbers\n", shm_ptr->n);
    shmdt((void *)shm_ptr);
    return 0;
}
