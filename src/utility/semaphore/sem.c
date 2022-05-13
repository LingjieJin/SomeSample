#include "sem.h"

#include <stdio.h>
#include <stdbool.h>
#include <errno.h>
#include <fcntl.h>
#include <assert.h>

sem_t *create_semaphore(const char *sem_name, const int sem_value)
{
    //
    sem_unlink(sem_name);
    //
    //    sem_t * semaphore = sem_open( inName, O_CREAT, 0644, inStartingCount );
    sem_t *semaphore = sem_open(sem_name, O_CREAT, S_IRUSR | S_IWUSR, sem_value);
    //
    if (semaphore == SEM_FAILED)
    {
        switch (errno)
        {
        case EEXIST:
            printf("Semaphore with name '%s' already exists.\n", sem_name);
            break;

        default:
            printf("Unhandled error: %d.\n", errno);
            break;
        }
        //
        assert(false);
        return SEM_FAILED;
    }
    //
    return semaphore;
}