CC=gcc-4.9
FLAGS=-fopenmp -O2 -g -std=gnu99

all: default

default:
	$(CC) $(FLAGS) -c -o thread_sort.o thread_sort.c; $(CC) $(FLAGS) thread_sort.c -o thread_sort

run:
	./thread_sort

clean:
	rm -f thread_sort.o thread_sort