all : queue

queue : queue.c
	gcc -g -o queue queue.c
