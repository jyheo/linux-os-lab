all: race_cond race_mutex

race_cond:
	gcc -o race_cond race_cond.c -lpthread

race_mutex:
	gcc -o race_mutex race_mutex.c -lpthread
