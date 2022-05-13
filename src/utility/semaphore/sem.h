#ifndef my_sem_hpp
#define my_sem_hpp

#include <semaphore.h>

sem_t *create_semaphore(const char *sem_name, const int sem_value);

#endif