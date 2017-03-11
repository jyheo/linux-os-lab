all: thread race_cond race_cond_2 race_mutex

thread: thread.c
	gcc -o thread thread.c -pthread

race_cond: race_cond.c
	gcc -o race_cond race_cond.c -pthread

race_cond_2: race_cond_2.c
	gcc -o race_cond_2 race_cond_2.c -pthread

race_mutex: race_mutex.c
	gcc -o race_mutex race_mutex.c -pthread

