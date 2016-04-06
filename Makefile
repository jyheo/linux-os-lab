all: race_cond race_cond_2 race_mutex

race_cond: race_cond.c
	gcc -o race_cond race_cond.c -lpthread

race_cond_2: race_cond_2.c
	gcc -o race_cond_2 race_cond_2.c -lpthread

race_mutex: race_mutex.c
	gcc -o race_mutex race_mutex.c -lpthread
