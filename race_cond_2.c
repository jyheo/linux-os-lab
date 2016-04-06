#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

int share_var = 0;
#define LOOP_COUNT 1000000

void *thread_entry(void *ptr)
{
    int i;
    int local_var;

    for (i = 0; i < LOOP_COUNT; i++) {
        local_var = share_var;
        local_var++;
        share_var = local_var;
    }
}

int main()
{
    pthread_t thread1, thread2;
    const char *msg1 = "Hello This is Thread 1.";
    const char *msg2 = "I am Thread 2.";

    pthread_create(&thread1, NULL, thread_entry, (void *) msg1);
    pthread_create(&thread2, NULL, thread_entry, (void *) msg2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("%d == %d\n", share_var, LOOP_COUNT * 2);

    return 0;
}

