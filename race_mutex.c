#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <sched.h>

pthread_mutex_t mutex;

void *thread_entry(void *ptr)
{
    int i, j, len;
    char *str = (char *) ptr;

    len = strlen(str);
    for (i = 0; i < 10; i++) {
        pthread_mutex_lock (&mutex); /* entercritical() */
	for (j = 0; j < len; j++) {
	    putchar(str[j]);
	    sched_yield(); /*to yield CPU*/
	}
        putchar('\n');
        pthread_mutex_unlock (&mutex); /* exitcritical() */
    }
}

int main()
{
    pthread_t thread1, thread2;
    const char *msg1 = "Hello This is Thread 1.";
    const char *msg2 = "I am not Thread 1.";

    pthread_mutex_init(&mutex, NULL);

    pthread_create(&thread1, NULL, thread_entry, (void *) msg1);
    pthread_create(&thread2, NULL, thread_entry, (void *) msg2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    pthread_mutex_destroy(&mutex);

    return 0;
}

